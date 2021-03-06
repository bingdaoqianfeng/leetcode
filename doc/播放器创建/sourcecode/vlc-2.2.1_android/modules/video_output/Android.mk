LOCAL_PATH := $(call my-dir)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME)
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -O2 -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=

libfb_plugin_la_SOURCES := fb.c
libvdummy_plugin_la_SOURCES := vdummy.c
libvmem_plugin_la_SOURCES := vmem.c
libyuv_plugin_la_SOURCES := yuv.c

libnativewindow_plugin_la_SOURCES := android/nativewindow.c android/utils.c android/utils.h
libandroidwindow_plugin_la_SOURCES := android/android_window.c android/android_window.h android/utils.ci android/utils.h

###############################################################################
include $(CLEAR_VARS)
MODULE_NAME := nativewindow
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

LOCAL_SHARED_LIBRARIES += libutils libz
LOCAL_SHARED_LIBRARIES += libcutils libdl
LOCAL_SHARED_LIBRARIES += libmedia libgui libcutils libstagefright_foundation

include $(BUILD_STATIC_LIBRARY)

###############################################################################

include $(CLEAR_VARS)
MODULE_NAME := androidwindow
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

LOCAL_SHARED_LIBRARIES += libutils libz
LOCAL_SHARED_LIBRARIES += libcutils libdl
LOCAL_SHARED_LIBRARIES += libmedia libgui libcutils libstagefright_foundation

#include $(BUILD_STATIC_LIBRARY)

