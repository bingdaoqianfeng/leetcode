/*****************************************************************************
 * common.c: Windows video output common code
 *****************************************************************************
 * Copyright (C) 2001-2009 VLC authors and VideoLAN
 * $Id: e60a6394750478ec0c17590557ef23a6c6947167 $
 *
 * Authors: Gildas Bazin <gbazin@videolan.org>
 *          Martell Malone <martellmalone@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble: This file contains the functions related to the init of the vout
 *           structure, the common display code, the screensaver, but not the
 *           events and the Window Creation (events.c)
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>
#include <vlc_vout_display.h>

#include <windows.h>
#include <assert.h>

#define COBJMACROS

#include "common.h"

#include <vlc_windows_interfaces.h>

static void CommonChangeThumbnailClip(vout_display_t *, bool show);
#if !VLC_WINSTORE_APP
static int  CommonControlSetFullscreen(vout_display_t *, bool is_fullscreen);

static void DisableScreensaver(vout_display_t *);
static void RestoreScreensaver(vout_display_t *);
#endif

/* */
int CommonInit(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;

    sys->hwnd      = NULL;
    sys->hvideownd = NULL;
    sys->hparent   = NULL;
    sys->hfswnd    = NULL;
    sys->changes   = 0;
    sys->is_first_display = true;
    sys->is_on_top        = false;

#if !VLC_WINSTORE_APP
    SetRectEmpty(&sys->rect_display);
    SetRectEmpty(&sys->rect_parent);

    var_Create(vd, "video-deco", VLC_VAR_BOOL | VLC_VAR_DOINHERIT);
    var_Create(vd, "disable-screensaver", VLC_VAR_BOOL | VLC_VAR_DOINHERIT);

    /* */
    sys->event = EventThreadCreate(vd);
    if (!sys->event)
        return VLC_EGENERIC;
#endif

    event_cfg_t cfg;
    memset(&cfg, 0, sizeof(cfg));
#ifdef MODULE_NAME_IS_direct3d9
    cfg.use_desktop = sys->use_desktop;
#endif
#ifdef MODULE_NAME_IS_directdraw
    cfg.use_overlay = sys->use_overlay;
#endif
    cfg.x      = var_InheritInteger(vd, "video-x");
    cfg.y      = var_InheritInteger(vd, "video-y");
    cfg.width  = vd->cfg->display.width;
    cfg.height = vd->cfg->display.height;

#if !VLC_WINSTORE_APP
    event_hwnd_t hwnd;
    if (EventThreadStart(sys->event, &hwnd, &cfg))
        return VLC_EGENERIC;

    sys->parent_window = hwnd.parent_window;
    sys->hparent       = hwnd.hparent;
    sys->hwnd          = hwnd.hwnd;
    sys->hvideownd     = hwnd.hvideownd;
    sys->hfswnd        = hwnd.hfswnd;

    if (vd->cfg->is_fullscreen) {
        if (CommonControlSetFullscreen(vd, true))
            vout_display_SendEventFullscreen(vd, false);
    }

    DisableScreensaver (vd);
#endif

    return VLC_SUCCESS;
}

/* */
picture_pool_t *CommonPool(vout_display_t *vd, unsigned count)
{
    VLC_UNUSED(count);
    return vd->sys->pool;
}

/*****************************************************************************
* UpdateRects: update clipping rectangles
*****************************************************************************
* This function is called when the window position or size are changed, and
* its job is to update the source and destination RECTs used to display the
* picture.
*****************************************************************************/
void UpdateRects(vout_display_t *vd,
    const vout_display_cfg_t *cfg,
    const video_format_t *source,
    bool is_forced)
{
    vout_display_sys_t *sys = vd->sys;
#define rect_src sys->rect_src
#define rect_src_clipped sys->rect_src_clipped
#define rect_dest sys->rect_dest
#define rect_dest_clipped sys->rect_dest_clipped

    RECT  rect;
    POINT point;

    /* */
    if (!cfg)
        cfg = vd->cfg;
    if (!source)
        source = &vd->source;

    /* Retrieve the window size */
#if VLC_WINSTORE_APP
    rect.left   = 0;
    rect.top    = 0;
    uint32_t i_width;
    uint32_t i_height;
    UINT dataSize = sizeof(i_width);
    HRESULT hr = IDXGISwapChain_GetPrivateData(sys->dxgiswapChain, &GUID_SWAPCHAIN_WIDTH, &dataSize, &i_width);
    if (FAILED(hr)) {
        msg_Err(vd, "Can't get swapchain width, size %d. (hr=0x%lX)", hr, dataSize);
        return;
    }
    dataSize = sizeof(i_height);
    hr = IDXGISwapChain_GetPrivateData(sys->dxgiswapChain, &GUID_SWAPCHAIN_HEIGHT, &dataSize, &i_height);
    if (FAILED(hr)) {
        msg_Err(vd, "Can't get swapchain height, size %d. (hr=0x%lX)", hr, dataSize);
        return;
    }
    rect.right  = i_width;
    rect.bottom = i_height;
#else
    GetClientRect(sys->hwnd, &rect);
#endif

    /* Retrieve the window position */
    point.x = point.y = 0;
#if !VLC_WINSTORE_APP
    ClientToScreen(sys->hwnd, &point);
#endif

    /* If nothing changed, we can return */
    bool has_moved;
    bool is_resized;
#if VLC_WINSTORE_APP
    has_moved = false;
    is_resized = rect.right != (sys->rect_display.right - sys->rect_display.left) ||
        rect.bottom != (sys->rect_display.bottom - sys->rect_display.top);
    sys->rect_display = rect;
#else
    EventThreadUpdateWindowPosition(sys->event, &has_moved, &is_resized,
        point.x, point.y,
        rect.right, rect.bottom);
#endif
    if (is_resized)
        vout_display_SendEventDisplaySize(vd, rect.right, rect.bottom);
    if (!is_forced && !has_moved && !is_resized)
        return;

    /* Update the window position and size */
    vout_display_cfg_t place_cfg = *cfg;
    place_cfg.display.width = rect.right;
    place_cfg.display.height = rect.bottom;

    vout_display_place_t place;
    vout_display_PlacePicture(&place, source, &place_cfg, false);

#if !VLC_WINSTORE_APP
    EventThreadUpdateSourceAndPlace(sys->event, source, &place);

    if (sys->hvideownd)
        SetWindowPos(sys->hvideownd, 0,
            place.x, place.y, place.width, place.height,
            SWP_NOCOPYBITS | SWP_NOZORDER | SWP_ASYNCWINDOWPOS);
#endif

    /* Destination image position and dimensions */
#if (defined(MODULE_NAME_IS_direct3d9) || defined(MODULE_NAME_IS_direct3d11) || defined(MODULE_NAME_IS_direct2d)) && !VLC_WINSTORE_APP
    rect_dest.left = 0;
    rect_dest.right = place.width;
    rect_dest.top = 0;
    rect_dest.bottom = place.height;
#else
    rect_dest.left = point.x + place.x;
    rect_dest.right = rect_dest.left + place.width;
    rect_dest.top = point.y + place.y;
    rect_dest.bottom = rect_dest.top + place.height;

#ifdef MODULE_NAME_IS_directdraw
    /* Apply overlay hardware constraints */
    if (sys->use_overlay)
        AlignRect(&rect_dest, sys->i_align_dest_boundary, sys->i_align_dest_size);
#endif

#endif

#if defined(MODULE_NAME_IS_directdraw)
    /* UpdateOverlay directdraw function doesn't automatically clip to the
    * display size so we need to do it otherwise it will fail */

    /* Clip the destination window */
    if (!IntersectRect(&rect_dest_clipped, &rect_dest,
        &sys->rect_display)) {
        SetRectEmpty(&rect_src_clipped);
        goto exit;
    }

#ifndef NDEBUG
    msg_Dbg(vd, "DirectXUpdateRects image_dst_clipped coords:"
        " %li,%li,%li,%li",
        rect_dest_clipped.left, rect_dest_clipped.top,
        rect_dest_clipped.right, rect_dest_clipped.bottom);
#endif

#else

    /* AFAIK, there are no clipping constraints in Direct3D, OpenGL and GDI */
    rect_dest_clipped = rect_dest;

#endif

    /* the 2 following lines are to fix a bug when clicking on the desktop */
    if ((rect_dest_clipped.right - rect_dest_clipped.left) == 0 ||
        (rect_dest_clipped.bottom - rect_dest_clipped.top) == 0) {
#if !VLC_WINSTORE_APP
        SetRectEmpty(&rect_src_clipped);
#endif
        goto exit;
    }

    /* src image dimensions */
    rect_src.left = 0;
    rect_src.top = 0;
    rect_src.right = vd->fmt.i_visible_width;
    rect_src.bottom = vd->fmt.i_visible_height;

    /* Clip the source image */
    rect_src_clipped.left = source->i_x_offset +
        (rect_dest_clipped.left - rect_dest.left) *
        source->i_visible_width / (rect_dest.right - rect_dest.left);
    rect_src_clipped.right = source->i_x_offset +
        source->i_visible_width -
        (rect_dest.right - rect_dest_clipped.right) *
        source->i_visible_width / (rect_dest.right - rect_dest.left);
    rect_src_clipped.top = source->i_y_offset +
        (rect_dest_clipped.top - rect_dest.top) *
        source->i_visible_height / (rect_dest.bottom - rect_dest.top);
    rect_src_clipped.bottom = source->i_y_offset +
        source->i_visible_height -
        (rect_dest.bottom - rect_dest_clipped.bottom) *
        source->i_visible_height / (rect_dest.bottom - rect_dest.top);

#ifdef MODULE_NAME_IS_directdraw
    /* Apply overlay hardware constraints */
    if (sys->use_overlay)
        AlignRect(&rect_src_clipped, sys->i_align_src_boundary, sys->i_align_src_size);
#elif defined(MODULE_NAME_IS_direct3d9) || defined(MODULE_NAME_IS_direct3d11) || defined(MODULE_NAME_IS_direct2d)
    /* Needed at least with YUV content */
    rect_src_clipped.left &= ~1;
    rect_src_clipped.right &= ~1;
    rect_src_clipped.top &= ~1;
    rect_src_clipped.bottom &= ~1;
#endif

#ifndef NDEBUG
    msg_Dbg(vd, "DirectXUpdateRects souce"
        " offset: %i,%i visible: %ix%i",
        source->i_x_offset, source->i_y_offset,
        source->i_visible_width, source->i_visible_height);
    msg_Dbg(vd, "DirectXUpdateRects image_src"
        " coords: %li,%li,%li,%li",
        rect_src.left, rect_src.top,
        rect_src.right, rect_src.bottom);
    msg_Dbg(vd, "DirectXUpdateRects image_src_clipped"
        " coords: %li,%li,%li,%li",
        rect_src_clipped.left, rect_src_clipped.top,
        rect_src_clipped.right, rect_src_clipped.bottom);
    msg_Dbg(vd, "DirectXUpdateRects image_dst"
        " coords: %li,%li,%li,%li",
        rect_dest.left, rect_dest.top,
        rect_dest.right, rect_dest.bottom);
    msg_Dbg(vd, "DirectXUpdateRects image_dst_clipped"
        " coords: %li,%li,%li,%li",
        rect_dest_clipped.left, rect_dest_clipped.top,
        rect_dest_clipped.right, rect_dest_clipped.bottom);
#endif

#ifdef MODULE_NAME_IS_directdraw
    /* The destination coordinates need to be relative to the current
    * directdraw primary surface (display) */
    rect_dest_clipped.left -= sys->rect_display.left;
    rect_dest_clipped.right -= sys->rect_display.left;
    rect_dest_clipped.top -= sys->rect_display.top;
    rect_dest_clipped.bottom -= sys->rect_display.top;
#endif

    CommonChangeThumbnailClip(vd, true);

exit:
    /* Signal the change in size/position */
    sys->changes |= DX_POSITION_CHANGE;

#undef rect_src
#undef rect_src_clipped
#undef rect_dest
#undef rect_dest_clipped
}

#if !VLC_WINSTORE_APP
/* */
void CommonClean(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;
    if (sys->event) {
        CommonChangeThumbnailClip(vd, false);
        EventThreadStop(sys->event);
        EventThreadDestroy(sys->event);
    }

    RestoreScreensaver(vd);
}

void CommonManage(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;

    /* We used to call the Win32 PeekMessage function here to read the window
     * messages. But since window can stay blocked into this function for a
     * long time (for example when you move your window on the screen), I
     * decided to isolate PeekMessage in another thread. */
    /* If we do not control our window, we check for geometry changes
     * ourselves because the parent might not send us its events. */
    if (sys->hparent) {
        RECT rect_parent;
        POINT point;

        /* Check if the parent window has resized or moved */
        GetClientRect(sys->hparent, &rect_parent);
        point.x = point.y = 0;
        ClientToScreen(sys->hparent, &point);
        OffsetRect(&rect_parent, point.x, point.y);

        if (!EqualRect(&rect_parent, &sys->rect_parent)) {
            sys->rect_parent = rect_parent;

            /* This code deals with both resize and move
             *
             * For most drivers(direct3d9, gdi, opengl), move is never
             * an issue. The surface automatically gets moved together
             * with the associated window (hvideownd)
             *
             * For directdraw, it is still important to call UpdateRects
             * on a move of the parent window, even if no resize occurred
             */
            SetWindowPos(sys->hwnd, 0, 0, 0,
                         rect_parent.right - rect_parent.left,
                         rect_parent.bottom - rect_parent.top,
                         SWP_NOZORDER);

            UpdateRects(vd, NULL, NULL, true);
        }
    }

    /* HasMoved means here resize or move */
    if (EventThreadGetAndResetHasMoved(sys->event))
        UpdateRects(vd, NULL, NULL, false);
}

/**
 * It ensures that the video window is shown after the first picture
 * is displayed.
 */
void CommonDisplay(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;
    if (!sys->is_first_display)
        return;

    /* Video window is initially hidden, show it now since we got a
     * picture to show.
     */
    SetWindowPos(sys->hvideownd, 0, 0, 0, 0, 0,
                 SWP_ASYNCWINDOWPOS|
                 SWP_FRAMECHANGED|
                 SWP_SHOWWINDOW|
                 SWP_NOMOVE|
                 SWP_NOSIZE|
                 SWP_NOZORDER);
    sys->is_first_display = false;
}
#endif

/**
 * It updates a picture data/pitches.
 */
int CommonUpdatePicture(picture_t *picture, picture_t **fallback,
                        uint8_t *data, unsigned pitch)
{
    if (fallback) {
        if (*fallback == NULL) {
            *fallback = picture_NewFromFormat(&picture->format);
            if (*fallback == NULL)
                return VLC_EGENERIC;
        }
        for (int n = 0; n < picture->i_planes; n++) {
            const plane_t *src = &(*fallback)->p[n];
            plane_t       *dst = &picture->p[n];
            dst->p_pixels = src->p_pixels;
            dst->i_pitch  = src->i_pitch;
            dst->i_lines  = src->i_lines;
        }
        return VLC_SUCCESS;
    }
    /* fill in buffer info in first plane */
    picture->p->p_pixels = data;
    picture->p->i_pitch  = pitch;
    picture->p->i_lines  = picture->format.i_height;

    /*  Fill chroma planes for biplanar YUV */
    if (picture->format.i_chroma == VLC_CODEC_NV12 ||
        picture->format.i_chroma == VLC_CODEC_NV21) {

        for (int n = 1; n < picture->i_planes; n++) {
            const plane_t *o = &picture->p[n-1];
            plane_t *p = &picture->p[n];

            p->p_pixels = o->p_pixels + o->i_lines * o->i_pitch;
            p->i_pitch  = pitch;
            p->i_lines  = picture->format.i_height;
        }
        /* The dx/d3d buffer is always allocated as NV12 */
        if (vlc_fourcc_AreUVPlanesSwapped(picture->format.i_chroma, VLC_CODEC_NV12)) {
            /* TODO : Swap NV21 UV planes to match NV12 */
            return VLC_EGENERIC;
        }
    }

    /*  Fill chroma planes for planar YUV */
    if (picture->format.i_chroma == VLC_CODEC_I420 ||
        picture->format.i_chroma == VLC_CODEC_J420 ||
        picture->format.i_chroma == VLC_CODEC_YV12) {

        for (int n = 1; n < picture->i_planes; n++) {
            const plane_t *o = &picture->p[n-1];
            plane_t *p = &picture->p[n];

            p->p_pixels = o->p_pixels + o->i_lines * o->i_pitch;
            p->i_pitch  = pitch / 2;
            p->i_lines  = picture->format.i_height / 2;
        }
        /* The dx/d3d buffer is always allocated as YV12 */
        if (vlc_fourcc_AreUVPlanesSwapped(picture->format.i_chroma, VLC_CODEC_YV12)) {
            uint8_t *p_tmp = picture->p[1].p_pixels;
            picture->p[1].p_pixels = picture->p[2].p_pixels;
            picture->p[2].p_pixels = p_tmp;
        }
    }
    return VLC_SUCCESS;
}

void AlignRect(RECT *r, int align_boundary, int align_size)
{
    if (align_boundary)
        r->left = (r->left + align_boundary/2) & ~align_boundary;
    if (align_size)
        r->right = ((r->right - r->left + align_size/2) & ~align_size) + r->left;
}

#if !VLC_WINSTORE_APP
/* */
static void CommonChangeThumbnailClip(vout_display_t *vd, bool show)
{
    vout_display_sys_t *sys = vd->sys;

    /* Windows 7 taskbar thumbnail code */
    OSVERSIONINFO winVer;
    winVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (!GetVersionEx(&winVer) || winVer.dwMajorVersion <= 5)
        return;

    if( FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)) )
        vlc_assert_unreachable();

    void *ptr;
    if (S_OK == CoCreateInstance(&CLSID_TaskbarList,
                                 NULL, CLSCTX_INPROC_SERVER,
                                 &IID_ITaskbarList3,
                                 &ptr)) {
        ITaskbarList3 *taskbl = ptr;
        taskbl->lpVtbl->HrInit(taskbl);

        HWND hroot = GetAncestor(sys->hwnd,GA_ROOT);
        RECT relative;
        if (show) {
            RECT video, parent;
            GetWindowRect(sys->hvideownd, &video);
            GetWindowRect(hroot, &parent);
            relative.left   = video.left   - parent.left - 8;
            relative.top    = video.top    - parent.top - 10;

            relative.right  = video.right  - video.left + relative.left;
            relative.bottom = video.bottom - video.top  + relative.top - 25;
        }
        if (S_OK != taskbl->lpVtbl->SetThumbnailClip(taskbl, hroot,
                                                 show ? &relative : NULL))
            msg_Err(vd, "SetThumbNailClip failed");

        taskbl->lpVtbl->Release(taskbl);
    }
    CoUninitialize();
}

static int CommonControlSetFullscreen(vout_display_t *vd, bool is_fullscreen)
{
    vout_display_sys_t *sys = vd->sys;

#ifdef MODULE_NAME_IS_direct3d9
    if (sys->use_desktop && is_fullscreen)
        return VLC_EGENERIC;
#endif

    /* */
    if (sys->parent_window)
        return VLC_EGENERIC;

    /* */
    HWND hwnd = sys->hparent && sys->hfswnd ? sys->hfswnd : sys->hwnd;

    /* Save the current windows placement/placement to restore
       when fullscreen is over */
    WINDOWPLACEMENT window_placement;
    window_placement.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(hwnd, &window_placement);

    if (is_fullscreen) {
        msg_Dbg(vd, "entering fullscreen mode");

        /* Change window style, no borders and no title bar */
        SetWindowLong(hwnd, GWL_STYLE, WS_CLIPCHILDREN | WS_VISIBLE);

        if (sys->hparent) {
            /* Retrieve current window position so fullscreen will happen
            *on the right screen */
            HMONITOR hmon = MonitorFromWindow(sys->hparent,
                                              MONITOR_DEFAULTTONEAREST);
            MONITORINFO mi;
            mi.cbSize = sizeof(MONITORINFO);
            if (GetMonitorInfo(hmon, &mi))
                SetWindowPos(hwnd, 0,
                             mi.rcMonitor.left,
                             mi.rcMonitor.top,
                             mi.rcMonitor.right - mi.rcMonitor.left,
                             mi.rcMonitor.bottom - mi.rcMonitor.top,
                             SWP_NOZORDER|SWP_FRAMECHANGED);
        } else {
            /* Maximize non embedded window */
            ShowWindow(hwnd, SW_SHOWMAXIMIZED);
        }

        if (sys->hparent) {
            /* Hide the previous window */
            RECT rect;
            GetClientRect(hwnd, &rect);
            SetParent(sys->hwnd, hwnd);
            SetWindowPos(sys->hwnd, 0, 0, 0,
                         rect.right, rect.bottom,
                         SWP_NOZORDER|SWP_FRAMECHANGED);

            HWND topLevelParent = GetAncestor(sys->hparent, GA_ROOT);
            ShowWindow(topLevelParent, SW_HIDE);
        }
        SetForegroundWindow(hwnd);
    } else {
        msg_Dbg(vd, "leaving fullscreen mode");

        /* Change window style, no borders and no title bar */
        SetWindowLong(hwnd, GWL_STYLE, EventThreadGetWindowStyle(sys->event));

        if (sys->hparent) {
            RECT rect;
            GetClientRect(sys->hparent, &rect);
            SetParent(sys->hwnd, sys->hparent);
            SetWindowPos(sys->hwnd, 0, 0, 0,
                         rect.right, rect.bottom,
                         SWP_NOZORDER|SWP_FRAMECHANGED);

            HWND topLevelParent = GetAncestor(sys->hparent, GA_ROOT);
            ShowWindow(topLevelParent, SW_SHOW);
            SetForegroundWindow(sys->hparent);
            ShowWindow(hwnd, SW_HIDE);
        } else {
            /* return to normal window for non embedded vout */
            SetWindowPlacement(hwnd, &window_placement);
            ShowWindow(hwnd, SW_SHOWNORMAL);
        }
    }
    return VLC_SUCCESS;
}

int CommonControl(vout_display_t *vd, int query, va_list args)
{
    vout_display_sys_t *sys = vd->sys;

    switch (query) {
    case VOUT_DISPLAY_CHANGE_DISPLAY_SIZE:   /* const vout_display_cfg_t *p_cfg */
    {   /* Update dimensions */
        const vout_display_cfg_t *cfg = va_arg(args, const vout_display_cfg_t *);
        RECT rect_window = {
            .top    = 0,
            .left   = 0,
            .right  = cfg->display.width,
            .bottom = cfg->display.height,
        };

        AdjustWindowRect(&rect_window, EventThreadGetWindowStyle(sys->event), 0);
        SetWindowPos(sys->hwnd, 0, 0, 0,
                     rect_window.right - rect_window.left,
                     rect_window.bottom - rect_window.top, SWP_NOMOVE);
        UpdateRects(vd, cfg, &vd->source, false);
        return VLC_SUCCESS;
    }
    case VOUT_DISPLAY_CHANGE_DISPLAY_FILLED: /* const vout_display_cfg_t *p_cfg */
    case VOUT_DISPLAY_CHANGE_ZOOM:           /* const vout_display_cfg_t *p_cfg */
    case VOUT_DISPLAY_CHANGE_SOURCE_ASPECT:  /* const video_format_t *p_source */
    case VOUT_DISPLAY_CHANGE_SOURCE_CROP: {  /* const video_format_t *p_source */
        const vout_display_cfg_t *cfg;

        if (query == VOUT_DISPLAY_CHANGE_SOURCE_CROP ||
            query == VOUT_DISPLAY_CHANGE_SOURCE_ASPECT) {
            const video_format_t *source = va_arg(args, const video_format_t *);
            cfg    = vd->cfg;
            UpdateRects(vd, cfg, source, true);
        } else {
            cfg    = va_arg(args, const vout_display_cfg_t *);
            UpdateRects(vd, cfg, NULL, false);
        }
        return VLC_SUCCESS;
    }
    case VOUT_DISPLAY_CHANGE_WINDOW_STATE: {       /* unsigned state */
        const unsigned state = va_arg(args, unsigned);
        const bool is_on_top = (state & VOUT_WINDOW_STATE_ABOVE) != 0;
#ifdef MODULE_NAME_IS_direct3d9
        if (sys->use_desktop && is_on_top)
            return VLC_EGENERIC;
#endif
        HMENU hMenu = GetSystemMenu(sys->hwnd, FALSE);

        if (is_on_top && !(GetWindowLong(sys->hwnd, GWL_EXSTYLE) & WS_EX_TOPMOST)) {
            CheckMenuItem(hMenu, IDM_TOGGLE_ON_TOP, MF_BYCOMMAND | MFS_CHECKED);
            SetWindowPos(sys->hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
        } else if (!is_on_top && (GetWindowLong(sys->hwnd, GWL_EXSTYLE) & WS_EX_TOPMOST)) {
            CheckMenuItem(hMenu, IDM_TOGGLE_ON_TOP, MF_BYCOMMAND | MFS_UNCHECKED);
            SetWindowPos(sys->hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
        }
        sys->is_on_top = is_on_top;
        return VLC_SUCCESS;
    }
    case VOUT_DISPLAY_CHANGE_FULLSCREEN: {
        bool fs = va_arg(args, int);
        if (CommonControlSetFullscreen(vd, fs))
            return VLC_EGENERIC;
        UpdateRects(vd, NULL, NULL, false);
        return VLC_SUCCESS;
    }

    case VOUT_DISPLAY_HIDE_MOUSE:
        EventThreadMouseHide(sys->event);
        return VLC_SUCCESS;
    case VOUT_DISPLAY_RESET_PICTURES:
        vlc_assert_unreachable();
    default:
        return VLC_EGENERIC;
    }
}

static void DisableScreensaver(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;

    /* disable screensaver by temporarily changing system settings */
    sys->i_spi_screensaveactive = 0;
    if (var_GetBool(vd, "disable-screensaver")) {
        msg_Dbg(vd, "disabling screen saver");
        SystemParametersInfo(SPI_GETSCREENSAVEACTIVE, 0,
                             &sys->i_spi_screensaveactive, 0);

        if (LOWORD(GetVersion()) == 0x0005) {
            /* If this is NT 5.0 (i.e., Win2K), we need to hack around
             * KB318781 (see http://support.microsoft.com/kb/318781) */

            HKEY hKeyCP = NULL;

            if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER,
                                              TEXT("Control Panel\\Desktop"),
                                              0, KEY_QUERY_VALUE, &hKeyCP) &&
                ERROR_SUCCESS != RegQueryValueEx(hKeyCP, TEXT("SCRNSAVE.EXE"),
                                                 NULL, NULL, NULL, NULL)) {
                sys->i_spi_screensaveactive = FALSE;
            }
        }

        if (FALSE != sys->i_spi_screensaveactive) {
            SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, 0, NULL, 0);
        }
    }
}

static void RestoreScreensaver(vout_display_t *vd)
{
    vout_display_sys_t *sys = vd->sys;

    /* restore screensaver system settings */
    if (0 != sys->i_spi_screensaveactive) {
        SystemParametersInfo(SPI_SETSCREENSAVEACTIVE,
                             sys->i_spi_screensaveactive, NULL, 0);
    }
}

#else

int CommonControl(vout_display_t *vd, int query, va_list args)
{
    switch (query) {
    default:
        return VLC_EGENERIC;
    }
}

void CommonManage(vout_display_t *vd) {
    UpdateRects(vd, NULL, NULL, false);
}
void CommonClean(vout_display_t *vd) {}
void CommonDisplay(vout_display_t *vd) {}
void CommonChangeThumbnailClip(vout_display_t *vd, bool show) {}
#endif
