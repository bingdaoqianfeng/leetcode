#!/bin/sh

#############
# FUNCTIONS #
#############

checkfail()
{
    if [ ! $? -eq 0 ];then
        echo "$1"
        exit 1
    fi
}

#############
# ARGUMENTS #
#############

RELEASE=0
GDB_FILE=""
while [ $# -gt 0 ]; do
    case $1 in
        help|--help)
            echo "Use -a to set the ARCH"
            echo "Use --release to build in release mode"
            exit 1
            ;;
        a|-a)
            ANDROID_ABI=$2
            shift
            ;;
        -c)
            CHROME_OS=1
            ;;
        release|--release)
            RELEASE=1
            ;;
        --gdb)
            GDB_FILE="$2"
            shift
            ;;
    esac
    shift
done

if [ -z "$ANDROID_NDK" ]; then
    echo "Please set the ANDROID_NDK environment variable with its path."
    exit 1
fi

#ANDROID_ABI="armeabi-v7a"
if [ -z "$ANDROID_ABI" ]; then
    echo "Please pass the ANDROID ABI to the correct architecture, using
                cross_build.sh -a ARCH
    ARM:     armeabi-v7a, armeabi, armeabi-v5, armeabi-nofpu
    ARM64:   arm64-v8a
    X86:     x86, x86_64
    MIPS:    mips, mips64."
    exit 1
fi

# Set up ABI variables
if [ "${ANDROID_ABI}" = "x86" ] ; then
    TARGET_TUPLE="i686-linux-android"
    PATH_HOST="x86"
    PLATFORM_SHORT_ARCH="x86"
    CPU="i686"
elif [ "${ANDROID_ABI}" = "x86_64" ] ; then
    TARGET_TUPLE="x86_64-linux-android"
    PATH_HOST="x86_64"
    PLATFORM_SHORT_ARCH="x86_64"
    HAVE_64=1
    CPU="i686"
elif [ "${ANDROID_ABI}" = "mips" ] ; then
    TARGET_TUPLE="mipsel-linux-android"
    PATH_HOST=$TARGET_TUPLE
    PLATFORM_SHORT_ARCH="mips"
elif [ "${ANDROID_ABI}" = "mips64" ] ; then
    TARGET_TUPLE="mips64el-linux-android"
    PATH_HOST=$TARGET_TUPLE
    PLATFORM_SHORT_ARCH="mips64"
    HAVE_64=1
elif [ "${ANDROID_ABI}" = "arm64-v8a" ] ; then
    TARGET_TUPLE="aarch64-linux-android"
    PATH_HOST=$TARGET_TUPLE
    HAVE_ARM=1
    HAVE_64=1
    PLATFORM_SHORT_ARCH="arm64"
    CPU="cortex-a8"
elif [ "${ANDROID_ABI}" = "armeabi-v7a" -o "${ANDROID_ABI}" = "armeabi" ] ; then
    TARGET_TUPLE="arm-linux-androideabi"
    PATH_HOST=$TARGET_TUPLE
    HAVE_ARM=1
    PLATFORM_SHORT_ARCH="arm"
    CPU="cortex-a8"
else
    echo "Unknown ABI: '${ANDROID_ABI}'. Die, die, die!"
    exit 2
fi

# try to detect NDK version
GCCVER=4.9
REL=$(grep -o '^Pkg.Revision.*[0-9]*.*' $ANDROID_NDK/source.properties |cut -d " " -f 3 | cut -d "." -f 1)
if [ $REL -ge 11 ] ; then
        if [ "${HAVE_64}" = 1 ];then
            ANDROID_API=android-21
        else
            ANDROID_API=android-9
        fi
else
    echo "You need the NDKv11 or later"
    exit 1
fi

SYSROOT=$ANDROID_NDK/platforms/$ANDROID_API/arch-$PLATFORM_SHORT_ARCH
SRC_DIR=$PWD
# Add the NDK toolchain to the PATH, needed both for contribs and for building
# stub libraries
NDK_TOOLCHAIN_PATH=`echo ${ANDROID_NDK}/toolchains/${PATH_HOST}-${GCCVER}/prebuilt/\`uname|tr A-Z a-z\`-*/bin`
CROSS_COMPILE=${NDK_TOOLCHAIN_PATH}/${TARGET_TUPLE}-
export PATH=${NDK_TOOLCHAIN_PATH}:${PATH}

###############
# DISPLAY ABI #
###############

echo "ABI:        $ANDROID_ABI"
echo "API:        $ANDROID_API"
echo "SYSROOT:    $SYSROOT"
if [ ! -z "$NO_FPU" ]; then
echo "FPU:        NO"
fi
if [ ! -z "$ARMV5" ]; then
echo "ARMv5:       YES"
fi
echo "NDK_TOOLCHAIN_PATH:       $NDK_TOOLCHAIN_PATH"
echo "CROSS_COMPILE:        $CROSS_COMPILE"
echo "PATH:       $PATH"

##########
# CFLAGS #
##########
if [ "$NO_OPTIM" = "1" ];
then
     CFLAGS="-g -O0"
else
     CFLAGS="-g -O2"
fi

CFLAGS="${CFLAGS} -fstrict-aliasing -funsafe-math-optimizations"
if [ -n "$HAVE_ARM" -a ! -n "$HAVE_64" ]; then
    CFLAGS="${CFLAGS} -mlong-calls"
fi

# Setup EXTRA_CFLAGS= per ABI
EXTRA_CFLAGS=""
if [ "${ANDROID_ABI}" = "armeabi-v7a" ] ; then
    EXTRA_CFLAGS="-mfpu=vfpv3-d16 -mcpu=cortex-a8"
    EXTRA_CFLAGS="${EXTRA_CFLAGS} -mthumb -mfloat-abi=softfp"
elif [ "${ANDROID_ABI}" = "armeabi" ] ; then
    if [ -n "${ARMV5}" ]; then
        EXTRA_CFLAGS="-march=armv5te -mtune=arm9tdmi -msoft-float"
    else
        if [ -n "${NO_FPU}" ]; then
            EXTRA_CFLAGS="-march=armv6j -mtune=arm1136j-s -msoft-float"
        else
            EXTRA_CFLAGS="-mfpu=vfp -mcpu=arm1136jf-s -mfloat-abi=softfp"
        fi
    fi
elif [ "${ANDROID_ABI}" = "x86" ] ; then
    EXTRA_CFLAGS="-mtune=atom -msse3 -mfpmath=sse -m32"
elif [ "${ANDROID_ABI}" = "mips" ] ; then
    EXTRA_CFLAGS="-march=mips32 -mtune=mips32r2 -mhard-float"
    # All MIPS Linux kernels since 2.4.4 will trap any unimplemented FPU
    # instruction and emulate it, so we select -mhard-float.
    # See http://www.linux-mips.org/wiki/Floating_point#The_Linux_kernel_and_floating_point
fi

EXTRA_CFLAGS="${EXTRA_CFLAGS} -I${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/include"
EXTRA_CFLAGS="${EXTRA_CFLAGS} -I${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/libs/${ANDROID_ABI}/include"

# XXX: remove when ndk C++11 is updated
EXTRA_CXXFLAGS="-D__STDC_FORMAT_MACROS=1 -D__STDC_CONSTANT_MACROS=1 -D__STDC_LIMIT_MACROS=1"

CPPFLAGS="-I${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/include -I${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/libs/${ANDROID_ABI}/include"

#################
# Setup LDFLAGS #
#################

EXTRA_LDFLAGS="-L${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/libs/${ANDROID_ABI} -lgnustl_static"

LDFLAGS="-Wl,-Bdynamic,-dynamic-linker=/system/bin/linker -Wl,--no-undefined"

if [ -n "$HAVE_ARM" ]; then
    if [ ${ANDROID_ABI} = "armeabi-v7a" ]; then
        EXTRA_PARAMS=" --enable-neon"
        LDFLAGS="$LDFLAGS -Wl,--fix-cortex-a8"
    fi
fi

LDFLAGS="$LDFLAGS -L${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/${GCCVER}/libs/${ANDROID_ABI}"

echo "CFLAGS:            ${CFLAGS}"
echo "EXTRA_CFLAGS:      ${EXTRA_CFLAGS}"
echo "LDFLAGS:           ${LDFLAGS}"

echo "Building FFmpeg"

#ANDROID_API=android-9
#SYSROOT=${NDK_ROOT}/platforms/${ANDROID_API}/arch-arm
#CROSS_PREFIX=${PREBUILT}/bin/arm-linux-androideabi-
#ARM_INCLUDE=${SYSROOT}/usr/include
#ARM_LIB=${SYSROOT}/usr/lib
PREFIX=$(pwd)/build_$PLATFORM_SHORT_ARCH
#OPTIMIZE_CFLAGS=" -marm -march=armv6 "
ADDITIONAL_CONFIGURE_FLAG=
SRC_PATH=ffmpeg-2.2.16-$PLATFORM_SHORT_ARCH
echo "SRC_PATH=$SRC_PATH"
echo "PREFIX=$PREFIX"
cd $SRC_PATH


./configure \
 --enable-version3 \
 --enable-gpl \
 --enable-nonfree \
 --disable-muxers \
 --disable-encoders \
 --disable-filters \
 --disable-bsfs \
 --disable-decoders \
 --enable-decoder=iac \
 --enable-decoder=mp3 \
 --enable-decoder=cook \
 --enable-decoder=atrac3 \
 --enable-decoder=aac \
 --enable-decoder=mp2 \
 --enable-decoder=mp1 \
 --enable-decoder=ac3 \
 --enable-decoder=pcm_s24le \
 --enable-decoder=pcm_s16le \
 --enable-decoder=pcm_s16be \
 --enable-decoder=pcm_u8 \
 --enable-decoder=pcm_s8 \
 --enable-decoder=pcm_mulaw \
 --enable-decoder=adpcm_ms \
 --enable-decoder=adpcm_ima_wav \
 --enable-decoder=flac \
 --enable-decoder=ape \
 --enable-decoder=vorbis \
 --enable-decoder=truehd \
 --enable-decoder=dca \
 --enable-decoder=ac3 \
 --enable-decoder=eac3 \
 --enable-decoder=wmalossless \
 --enable-decoder=wmapro \
 --enable-decoder=wmav1 \
 --enable-decoder=wmav2 \
 --enable-decoder=wmavoice \
 --enable-decoder=alac \
 --enable-decoder=flv \
 --enable-decoder=rv10 \
 --enable-decoder=rv20 \
 --enable-decoder=rv30 \
 --enable-decoder=rv40 \
 --enable-decoder=vp6 \
 --enable-decoder=vp6f \
 --enable-decoder=mpeg1video \
 --enable-decoder=vc1 \
 --enable-decoder=vc1image \
 --enable-decoder=mjpeg \
 --enable-decoder=cinepak \
 --enable-decoder=tscc \
 --enable-decoder=wmv1 \
 --enable-decoder=wmv2 \
 --enable-decoder=vp3 \
 --enable-decoder=vp5 \
 --enable-decoder=vp6 \
 --enable-decoder=vp6a \
 --enable-decoder=vp6f \
 --enable-decoder=vp8 \
 --enable-decoder=h264 \
 --enable-decoder=h264_crystalhd \
 --enable-decoder=h264_vda \
 --enable-decoder=h264_vdpau \
 --enable-decoder=mpeg4 \
 --enable-decoder=mpeg4_crystalhd \
 --enable-decoder=mpeg4_vdpau \
 --enable-decoder=dvdsub \
 --enable-decoder=dvbsub \
 --enable-decoder=pgssub \
 --enable-decoder=xsub \
 --cross-prefix=${CROSS_COMPILE} \
 --enable-cross-compile \
 --sysroot=${SYSROOT} \
 --target-os=linux \
 --arch=${PLATFORM_SHORT_ARCH} \
 --prefix=${PREFIX} \
 --cpu=${CPU} \
 --extra-cflags=" -DANDROID " \
 ${ADDITIONAL_CONFIGURE_FLAG}

make -j
make install
