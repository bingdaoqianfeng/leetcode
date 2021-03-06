LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

DEFS := -DHAVE_CONFIG_H
AM_CFLAGS :=
AM_CPPFLAGS :=
VLC_CFLAGS := -g -O2 -fstrict-aliasing -funsafe-math-optimizations -Wall -Wextra -Wsign-compare -Wundef -Wpointer-arith -Wvolatile-register-var -fvisibility=hidden -ffast-math -funroll-loops -std=gnu99
VLC_CPPFLAGS :=
LOCAL_CFLAGS := $(DEFS) $(VLC_CFLAGS) $(VLC_CPPFLAGS) $(AM_CFLAGS) $(AM_CPPFLAGS) 
LOCAL_ARM_MODE := arm
LOCAL_MODULE := libvlc_compat
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
$(info miplayer build  [$(MODULE_TARGET)]for [$(TARGET_PRODUCT)])
LOCAL_SRC_FILES := atof.c getdelim.c strtof.c swab.c tdestroy.c strverscmp.c
AMPLAYER_APK_DIR=$(TOP)/packages/amlogic/LibPlayer
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

LOCAL_SHARED_LIBRARIES += libutils libz libbinder
LOCAL_SHARED_LIBRARIES += liblog libcutils libdl
LOCAL_SHARED_LIBRARIES += libbinder

include $(BUILD_STATIC_LIBRARY)
