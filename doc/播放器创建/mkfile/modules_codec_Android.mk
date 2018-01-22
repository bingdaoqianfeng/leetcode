LOCAL_PATH := $(call my-dir)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME)
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=



libddummy_plugin_la_SOURCES := ddummy.c
### Audio codecs ###
liba52_plugin_la_SOURCES := a52.c a52.h
libadpcm_plugin_la_SOURCES := adpcm.c
libaes3_plugin_la_SOURCES := aes3.c
libaraw_plugin_la_SOURCES := araw.c
#libdts_plugin_la_SOURCES := dts.c dts_header.c dts_header.h
libg711_plugin_la_SOURCES := g711.c
liblpcm_plugin_la_SOURCES := lpcm.c
libmpeg_audio_plugin_la_SOURCES := mpeg_audio.c
libuleaddvaudio_plugin_la_SOURCES := uleaddvaudio.c


### Video codecs ###
libcdg_plugin_la_SOURCES := cdg.c
librawvideo_plugin_la_SOURCES := rawvideo.c
### SPU ###
libcc_plugin_la_SOURCES := cc.c cc.h substext.h
libcvdsub_plugin_la_SOURCES := cvdsub.c
libdvbsub_plugin_la_SOURCES := dvbsub.c
libscte27_plugin_la_SOURCES := scte27.c
libspudec_plugin_la_SOURCES := spudec/spudec.c spudec/parse.c spudec/spudec.h
libstl_plugin_la_SOURCES := stl.c
libsubsdec_plugin_la_SOURCES := subsdec.c substext.h
libsubsusf_plugin_la_SOURCES := subsusf.c
libsvcdsub_plugin_la_SOURCES := svcdsub.c
libtelx_plugin_la_SOURCES := telx.c
### FFmpeg/libav ###
libavcodec_plugin_la_SOURCES := \
        avcodec/avcommon_compat.h \
        avcodec/avcommon.h \
        avcodec/video.c \
        avcodec/subtitle.c \
        avcodec/audio.c \
        avcodec/cpu.c \
        avcodec/fourcc.c \
        avcodec/chroma.c avcodec/chroma.h \
        avcodec/va.c avcodec/va.h \
        avcodec/avcodec.c avcodec/avcodec.h

### OpenMAX ###
libomxil_plugin_la_SOURCES := \
    omxil/utils.c omxil/omxil_utils.h \
    h264_nal.h \
    omxil/qcom.c omxil/qcom.h \
    omxil/omxil.c omxil/omxil.h omxil/omxil_core.c omxil/omxil_core.h
#    video_chroma/copy.c
#libiomx_plugin_la_SOURCES := $(libomxil_plugin_la_SOURCES)
#libmicodec_plugin_la_SOURCES := omxil/micodec.c omxil/utils.c
libmediacodec_plugin_la_CPPFLAGS := $(AM_CPPFLAGS) -I$(srcdir)/omxil
#libmediacodec_plugin_la_SOURCES := omxil/android_mediacodec.c omxil/utils.c

###############################################################################
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := avcodec
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) 
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) 
LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET) 
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
$(info miplayer build  [$(MODULE_TARGET)]for [$(TARGET_PRODUCT)])
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include  \
                    $(LOCAL_PATH)/../../third-party/include/dvbpsi

ifeq ($(MIPLAYER_BINARY_FFMPEG),true)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../third-party/include
endif

ifneq ($(MIPLAYER_BINARY_FFMPEG),true)
LOCAL_C_INCLUDES += external/ffmpeg2-2
endif

include $(BUILD_STATIC_LIBRARY)

###############################################################################
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := micodec
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) \
         -DUSE_MICODEC
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(AM_CFLAGS) $(VLC_CPPFLAGS) $(AM_CPPFLAGS) 


LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET) 
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include \
                    $(LOCAL_PATH)/omxil \
                    $(LOCAL_PATH)/avcodec

ifeq ($(MIPLAYER_BINARY_FFMPEG),true)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../third-party/include
endif

ifneq ($(MIPLAYER_BINARY_FFMPEG),true)
LOCAL_C_INCLUDES += external/ffmpeg2-2
endif


LOCAL_SHARED_LIBRARIES += libutils libz
LOCAL_SHARED_LIBRARIES += libcutils libdl
include $(BUILD_STATIC_LIBRARY)

###############################################################################
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := subsdec
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) 
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) 
LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET) 
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include
LOCAL_SHARED_LIBRARIES += libutils libz libbinder
LOCAL_SHARED_LIBRARIES += libcutils libdl
include $(BUILD_STATIC_LIBRARY)

###############################################################################
# omxinterface
include $(CLEAR_VARS)

#findMatchingCodecs changed in android 4.2
LOCAL_CPPFLAGS := $(DEFS) -Wno-psabi
LOCAL_ARM_MODE := arm
LOCAL_MODULE := libmiomxinterface
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_SRC_FILES := omxil/omxcodecinterface.cpp
LOCAL_SHARED_LIBRARIES := libstagefright libmedia libutils libbinder \
                          libcutils libstagefright_foundation libui

PRODUCT_DIR := dummy
PRODUCT_INCLUDE :=

include $(BUILD_SHARED_LIBRARY)
