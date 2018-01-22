LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS = -DMODULE_STRING=\"main\" \
    -DLOCALEDIR=\"$(LOCAL_PATH)/../share/locale\" -DPKGDATADIR=\"$(LOCAL_PATH)/../vlc\" \
    -DPKGLIBDIR=\"$(LOCAL_PATH)/../vlc\"
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS := -Wno-error=return-type
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS)

VLC_NULL =
VLC_SOURCES_libvlc_common = \
    libvlc.c \
    libvlc-module.c \
    missing.c \
    revision.c \
    version.c \
    interface/dialog.c \
    interface/interface.c \
    playlist/art.c \
    playlist/aout.c \
    playlist/thread.c \
    playlist/control.c \
    playlist/engine.c \
    playlist/fetcher.c \
    playlist/sort.c \
    playlist/loadsave.c \
    playlist/preparser.c \
    playlist/tree.c \
    playlist/item.c \
    playlist/search.c \
    playlist/services_discovery.c \
    input/item.c \
    input/access.c \
    input/clock.c \
    input/control.c \
    input/decoder.c \
    input/decoder_synchro.c \
    input/demux.c \
    input/es_out.c \
    input/es_out_timeshift.c \
    input/event.c \
    input/input.c \
    input/meta.c \
    input/resource.c \
    input/stats.c \
    input/stream.c \
    input/stream_demux.c \
    input/stream_filter.c \
    input/stream_memory.c \
    input/subtitles.c \
    input/var.c \
    video_output/control.c \
    video_output/display.c \
    video_output/inhibit.c \
    video_output/interlacing.c \
    video_output/snapshot.c \
    video_output/video_output.c \
    video_output/video_text.c \
    video_output/video_epg.c \
    video_output/video_widgets.c \
    video_output/vout_subpictures.c \
    video_output/window.c \
    video_output/opengl.c \
    video_output/vout_intf.c \
    video_output/vout_wrapper.c \
    audio_output/common.c \
    audio_output/dec.c \
    audio_output/filters.c \
    audio_output/output.c \
    audio_output/volume.c \
    network/getaddrinfo.c \
    network/io.c \
    network/tcp.c \
    network/udp.c \
    network/rootbind.c \
    network/tls.c \
    text/charset.c \
    text/strings.c \
    text/unicode.c \
    text/url.c \
    text/filesystem.c \
    text/iso_lang.c \
    text/iso-639_def.h \
    misc/md5.c \
    misc/probe.c \
    misc/rand.c \
    misc/mtime.c \
    misc/block.c \
    misc/fourcc.c \
    misc/es_format.c \
    misc/picture.c \
    misc/picture_fifo.c \
    misc/picture_pool.c \
    misc/threads.c \
    misc/cpu.c \
    misc/epg.c \
    misc/exit.c \
    misc/events.c \
    misc/image.c \
    misc/messages.c \
    misc/mime.c \
    misc/objects.c \
    misc/variables.c \
    misc/error.c \
    misc/update.c \
    misc/update_crypto.c \
    misc/xml.c \
    misc/addons.c \
    misc/filter.c \
    misc/filter_chain.c \
    misc/http_auth.c \
    misc/fingerprinter.c \
    misc/text_style.c \
    misc/subpicture.c \
    modules/modules.c \
    modules/bank.c \
    modules/cache.c \
    modules/entry.c \
    modules/textdomain.c \
    config/core.c \
    config/chain.c \
    config/file.c \
    config/help.c \
    config/intf.c \
    config/keys.c \
    config/cmdline.c \
    config/getopt.c \
    extras/libc.c \
    extras/tdestroy.c \
    $(VLC_NULL)

VLC_SOURCES_libvlc_android = \
    android/dirs.c \
    android/thread.c \
    android/error.c \
    posix/filesystem.c \
    android/netconf.c \
    posix/plugin.c \
    posix/timer.c \
    posix/linux_cpu.c \
    posix/linux_specific.c \
    posix/specific.c \
    posix/rand.c \
    $(VLC_NULL)


LOCAL_ARM_MODE := arm
LOCAL_MODULE := libvlccore
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(VLC_SOURCES_libvlc_common) $(VLC_SOURCES_libvlc_android)

#AMPLAYER_APK_DIR=$(TOP)/packages/amlogic/LibPlayer
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

#LOCAL_SHARED_LIBRARIES += libutils libz libbinder
#LOCAL_SHARED_LIBRARIES += liblog libcutils libdl
#LOCAL_SHARED_LIBRARIES += libbinder

include $(BUILD_STATIC_LIBRARY)
