LOCAL_PATH := $(call my-dir)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS := -DMODULE_STRING=\"$(MODULE_NAME)\" -DMODULE_NAME=$(MODULE_NAME) 
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=

libfloat_mixer_plugin_la_SOURCES := float.c
libinteger_mixer_plugin_la_SOURCES := integer.c

###############################################################################
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := float_mixer
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
# attachment plugins
include $(CLEAR_VARS)
MODULE_NAME := integer_mixer
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

