LOCAL_PATH := $(call my-dir)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME)
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=

#libopensles_android_plugin_la_SOURCES := opensles_android.c
#libjava_audiotrack_plugin_la_SOURCES := audiotrack.c
#libandroid_audiosink_plugin_la_SOURCES := android_audiosink.cpp
libandroid_audiotrack_plugin_la_SOURCES := audiotrack.c
libadummy_plugin_la_SOURCES := adummy.c
libafile_plugin_la_SOURCES := file.c
libamem_plugin_la_SOURCES := amem.c

###############################################################################
include $(CLEAR_VARS)
MODULE_NAME := android_audiotrack
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) \
               -DHAVE_POSIX_MEMALIGN
LOCAL_CFLAGS := $(DEFS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET)
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include \
    $(LOCAL_PATH)/.. \
#    frameworks/wilhelm/include
LOCAL_SHARED_LIBRARIES += libutils libz libbinder
LOCAL_SHARED_LIBRARIES += libcutils libdl
include $(BUILD_STATIC_LIBRARY)

###############################################################################
include $(CLEAR_VARS)
MODULE_NAME := android_audiosink
MODULE_TARGET := libvlc_plugin_$(MODULE_NAME)
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) \
               -DHAVE_POSIX_MEMALIGN
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) 
LOCAL_ARM_MODE := arm
LOCAL_MODULE := $(MODULE_TARGET)
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(lib$(MODULE_NAME)_plugin_la_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include \
#                    $(TOP)/frameworks/av/include  \
                    $(TOP)/frameworks/av/include/media/stagefright  \
                    $(TOP)/frameworks/native/include  \
                    $(TOP)/system/core/include  \
                    $(TOP)/hardware/libhardware/include

LOCAL_SHARED_LIBRARIES += libutils libz
LOCAL_SHARED_LIBRARIES += libcutils libdl
LOCAL_SHARED_LIBRARIES += libmedia libgui libcutils libstagefright_foundation
#include $(BUILD_STATIC_LIBRARY)

