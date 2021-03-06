LOCAL_PATH := $(call my-dir)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
#AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME)
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=


libflacsys_plugin_la_SOURCES := flac.c xiph_metadata.h xiph_metadata.c
libdemuxdump_plugin_la_SOURCES = demux/demuxdump.c
librawdv_plugin_la_SOURCES = rawdv.c rawdv.h
librawvid_plugin_la_SOURCES = rawvid.c
libau_plugin_la_SOURCES = au.c
librawaud_plugin_la_SOURCES = rawaud.c
libwav_plugin_la_SOURCES = wav.c windows_audio_commons.h
libnsv_plugin_la_SOURCES = nsv.c
libreal_plugin_la_SOURCES = real.c
libps_plugin_la_SOURCES = ps.c ps.h
libpva_plugin_la_SOURCES = pva.c
libaiff_plugin_la_SOURCES = aiff.c
libmjpeg_plugin_la_SOURCES = mjpeg.c mxpeg_helper.h
libsubtitle_plugin_la_SOURCES = subtitle.c
libty_plugin_la_SOURCES = ty.c codec/cc.h
libvobsub_plugin_la_SOURCES = vobsub.c vobsub.h
libvoc_plugin_la_SOURCES = voc.c
libxa_plugin_la_SOURCES = xa.c
libnuv_plugin_la_SOURCES = nuv.c
libnsc_plugin_la_SOURCES = nsc.c
libtta_plugin_la_SOURCES = tta.c
libvc1_plugin_la_SOURCES = vc1.c
libdemux_cdg_plugin_la_SOURCES = cdg.c
libsmf_plugin_la_SOURCES = smf.c
libdiracsys_plugin_la_SOURCES = dirac.c
libimage_plugin_la_SOURCES = image.c mxpeg_helper.h
libdemux_stl_plugin_la_SOURCES = stl.c
libasf_plugin_la_SOURCES = asf/asf.c asf/libasf.c asf/libasf.h asf/libasf_guid.h
libavi_plugin_la_SOURCES = avi/avi.c avi/libavi.c avi/libavi.h
libcaf_plugin_la_SOURCES = caf.c
libts_plugin_la_SOURCES = ts.c mpeg/csa.c mpeg/dvbpsi_compat.h dvb-text.h
libes_plugin_la_SOURCES  = mpeg/es.c ../codec/dts_header.c ../codec/dts_header.h
libh264_plugin_la_SOURCES = mpeg/h264.c
libhevc_plugin_la_SOURCES = mpeg/hevc.c mpeg/mpeg_parser_helpers.h
libmpgv_plugin_la_SOURCES = mpeg/mpgv.c

libavformat_plugin_la_SOURCES = avformat/demux.c \
    ../codec/avcodec/fourcc.c \
    ../codec/avcodec/chroma.c \
    ../codec/avcodec/avcommon.h \
    ../codec/avcodec/avcommon_compat.h \
    vobsub.h \
    avformat/avformat.c avformat/avformat.h

libmp4_plugin_la_SOURCES = mp4/mp4.c mp4/mp4.h \
                           mp4/libmp4.c mp4/libmp4.h \
                           mp4/id3genres.h mp4/languages.h

libplaylist_plugin_la_SOURCES = \
    playlist/asx.c \
    playlist/b4s.c \
    playlist/dvb.c \
    playlist/gvp.c \
    playlist/ifo.c \
    playlist/itml.c \
    playlist/itml.h \
    playlist/m3u.c \
    playlist/pls.c \
    playlist/podcast.c \
    playlist/qtl.c \
    playlist/ram.c \
    playlist/sgimb.c \
    playlist/shoutcast.c \
    playlist/wpl.c \
    playlist/xspf.c \
    playlist/zpl.c \
    playlist/playlist.c demux/playlist/playlist.h



###############################################################################
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := es
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME)
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET)
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include
#LOCAL_SHARED_LIBRARIES += libutils libz libbinder
#LOCAL_SHARED_LIBRARIES += libcutils libdl
include $(BUILD_STATIC_LIBRARY)

