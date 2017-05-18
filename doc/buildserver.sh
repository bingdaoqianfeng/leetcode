#!/bin/sh
PACKAGEPATH="/home/user/source/ndk/7.5.3.351"

TARGETPATH="libs/armeabi/"
cp  $PACKAGEPATH/libanw.*.so                  $TARGETPATH
cp  $PACKAGEPATH/libffmpeg-miplayer.so        $TARGETPATH
cp  $PACKAGEPATH/libxiaomimediaplayer.so      $TARGETPATH
cp  $PACKAGEPATH/libxiaomiplayerwrapper.so    $TARGETPATH
cp  $PACKAGEPATH/libmediandk_*.so             $TARGETPATH
cp  $PACKAGEPATH/libmiomxinterface*.so        $TARGETPATH

TARGETPATH="libs/armeabi-v7a/"
cp  $PACKAGEPATH/libanw.*.so                  $TARGETPATH
cp  $PACKAGEPATH/libffmpeg-miplayer.so        $TARGETPATH
cp  $PACKAGEPATH/libxiaomimediaplayer.so      $TARGETPATH
cp  $PACKAGEPATH/libxiaomiplayerwrapper.so    $TARGETPATH
cp  $PACKAGEPATH/libmediandk_*.so             $TARGETPATH
cp  $PACKAGEPATH/libmiomxinterface*.so        $TARGETPATH

TARGETPATH="phoneV6/videoplayer/libs/armeabi-v7a/"
cp  $PACKAGEPATH/libanw.*.so                  $TARGETPATH
cp  $PACKAGEPATH/libffmpeg-miplayer.so        $TARGETPATH
cp  $PACKAGEPATH/libxiaomimediaplayer.so      $TARGETPATH
cp  $PACKAGEPATH/libxiaomiplayerwrapper.so    $TARGETPATH
cp  $PACKAGEPATH/libmediandk_*.so             $TARGETPATH
cp  $PACKAGEPATH/libmiomxinterface*.so        $TARGETPATH

cp  $PACKAGEPATH/miui-mediaplayer.jar         phoneV6/common/libs/miui-mediaplayer.jar
