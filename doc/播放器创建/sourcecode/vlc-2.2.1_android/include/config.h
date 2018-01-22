/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


#ifndef _REENTRANT
# define _REENTRANT
#endif


#if defined(_WIN32) && !defined(_WIN32_WINNT)

# define _WIN32_WINNT 0x0502 /* Windows XP SP2 */

#endif

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define to 1 to allow running VLC as root (uid 0). */
/* #undef ALLOW_RUN_AS_ROOT */

/* Maximum supported data alignment */
#define ATTRIBUTE_ALIGNED_MAX 64

/* Define to 1 if 3D Now! inline assembly is available. */
/* #undef CAN_COMPILE_3DNOW */

/* Define to 1 if AltiVec inline assembly is available. */
/* #undef CAN_COMPILE_ALTIVEC */

/* Define to 1 if C AltiVec extensions are available. */
/* #undef CAN_COMPILE_C_ALTIVEC */

/* Define to 1 inline MMX assembly is available. */
/* #undef CAN_COMPILE_MMX */

/* Define to 1 if MMX EXT inline assembly is available. */
/* #undef CAN_COMPILE_MMXEXT */

/* Define to 1 if SSE inline assembly is available. */
/* #undef CAN_COMPILE_SSE */

/* Define to 1 if SSE2 inline assembly is available. */
/* #undef CAN_COMPILE_SSE2 */

/* Define to 1 if SSE3 inline assembly is available. */
/* #undef CAN_COMPILE_SSE3 */

/* Define to 1 if SSE4A inline assembly is available. */
/* #undef CAN_COMPILE_SSE4A */

/* Define to 1 if SSE4_1 inline assembly is available. */
/* #undef CAN_COMPILE_SSE4_1 */

/* Define to 1 if SSE4_2 inline assembly is available. */
/* #undef CAN_COMPILE_SSE4_2 */

/* Define to 1 if SSSE3 inline assembly is available. */
/* #undef CAN_COMPILE_SSSE3 */

/* The ./configure command line */
#define CONFIGURE_LINE "../configure  '--host=arm-linux-androideabi' '--build=x86_64-unknown-linux' '--enable-neon' '--disable-nls' '--enable-live555' '--enable-realrtsp' '--enable-avformat' '--enable-swscale' '--enable-avcodec' '--enable-opus' '--enable-opensles' '--enable-mkv' '--enable-taglib' '--enable-dvbpsi' '--disable-vlc' '--disable-shared' '--disable-update-check' '--disable-vlm' '--disable-dbus' '--disable-lua' '--disable-vcd' '--disable-v4l2' '--disable-gnomevfs' '--enable-dvdread' '--enable-dvdnav' '--disable-bluray' '--disable-linsys' '--disable-decklink' '--disable-libva' '--disable-dv1394' '--enable-mod' '--disable-sid' '--disable-gme' '--disable-tremor' '--enable-mad' '--disable-dca' '--disable-sdl-image' '--enable-zvbi' '--disable-fluidsynth' '--disable-jack' '--disable-pulse' '--disable-alsa' '--disable-samplerate' '--disable-sdl' '--disable-xcb' '--disable-atmo' '--disable-qt' '--disable-skins2' '--disable-mtp' '--disable-notify' '--enable-libass' '--disable-svg' '--disable-udev' '--enable-libxml2' '--disable-caca' '--disable-glx' '--enable-egl' '--enable-gles2' '--disable-goom' '--disable-projectm' '--disable-sout' '--enable-vorbis' '--disable-faad' '--disable-x264' '--disable-schroedinger' '--enable-debug' 'build_alias=x86_64-unknown-linux' 'host_alias=arm-linux-androideabi' 'CC=/home/user/source/vlcsrc/android/android-ndk-r10e/toolchains/arm-linux-androideabi-4.8/prebuilt/linux-x86/bin/arm-linux-androideabi-gcc --sysroot=/home/user/source/vlcsrc/android/android-ndk-r10e/platforms/android-9/arch-arm' 'CFLAGS=-g -O2 -fstrict-aliasing -funsafe-math-optimizations -mlong-calls -mfpu=vfpv3-d16 -mcpu=cortex-a8 -mthumb -mfloat-abi=softfp -I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/include -I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi-v7a/include' 'LDFLAGS=-Wl,-Bdynamic,-dynamic-linker=/system/bin/linker -Wl,--no-undefined -Wl,--fix-cortex-a8 -L/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi-v7a' 'CPPFLAGS=-I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/include -I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi-v7a/include' 'CXX=/home/user/source/vlcsrc/android/android-ndk-r10e/toolchains/arm-linux-androideabi-4.8/prebuilt/linux-x86/bin/arm-linux-androideabi-g++ --sysroot=/home/user/source/vlcsrc/android/android-ndk-r10e/platforms/android-9/arch-arm -D__cpp_static_assert=200410' 'CXXFLAGS=-g -O2 -fstrict-aliasing -funsafe-math-optimizations -mlong-calls -mfpu=vfpv3-d16 -mcpu=cortex-a8 -mthumb -mfloat-abi=softfp -I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/include -I/home/user/source/vlcsrc/android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi-v7a/include -D__STDC_FORMAT_MACROS=1 -D__STDC_CONSTANT_MACROS=1 -D__STDC_LIMIT_MACROS=1' 'PKG_CONFIG_LIBDIR=../contrib/arm-linux-androideabi/lib/pkgconfig'"

/* Copyright string */
#define COPYRIGHT_MESSAGE "Copyright © 1996-2015 the VideoLAN team"

/* The copyright years */
#define COPYRIGHT_YEARS "1996-2015"

/* Default font family */
/* #undef DEFAULT_FAMILY */

/* Default font */
/* #undef DEFAULT_FONT_FILE */

/* Default monospace font family */
/* #undef DEFAULT_MONOSPACE_FAMILY */

/* Default monospace font */
/* #undef DEFAULT_MONOSPACE_FONT_FILE */

/* Binary specific version */
/* #undef DISTRO_VERSION */

/* Define if you want the addons manager modules */
#define ENABLE_ADDONMANAGERMODULES 1

/* Define if you want the HTTP daemon support */
#define ENABLE_HTTPD 1

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* Define to 1 for stream output support. */
/* #undef ENABLE_SOUT */

/* Define if you want the VideoLAN manager support */
/* #undef ENABLE_VLM */

/* Define to 1 if you have the <a52dec/a52.h> header file. */
#define HAVE_A52DEC_A52_H 1

/* Define to 1 if you have the `accept4' function. */
/* #undef HAVE_ACCEPT4 */

/* Define to 1 if you have the <altivec.h> header file. */
/* #undef HAVE_ALTIVEC_H */

/* Define to 1 if you have the <ApplicationServices/ApplicationServices.h>
   header file. */
/* #undef HAVE_APPLICATIONSERVICES_APPLICATIONSERVICES_H */

/* Define if libaribb24 is available. */
/* #undef HAVE_ARIBB24 */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have asprintf function */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the `atof' function. */
/* #undef HAVE_ATOF */

/* Define to 1 if you have the `atoll' function. */
#define HAVE_ATOLL 1

/* Support for __attribute__((packed)) for structs */
#define HAVE_ATTRIBUTE_PACKED 1

/* Define to 1 if you have the <audio_io.h> header file. */
/* #undef HAVE_AUDIO_IO_H */

/* Define if the d3d11va module is built */
/* #undef HAVE_AVCODEC_D3D11VA */

/* Define to 1 if you have the `av_vda_alloc_context' function. */
/* #undef HAVE_AV_VDA_ALLOC_CONTEXT */

/* Define to 1 if you have the `backtrace' function. */
/* #undef HAVE_BACKTRACE */

/* Define to 1 if you have the Mac OS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define to 1 if you have the <d2d1.h> header file. */
/* #undef HAVE_D2D1_H */

/* Define to 1 if you have the <d3d11.h> header file. */
/* #undef HAVE_D3D11_H */

/* Define to 1 if you have the <d3d9.h> header file. */
/* #undef HAVE_D3D9_H */

/* Define to 1 if you have the `daemon' function. */
#define HAVE_DAEMON 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the <ddraw.h> header file. */
/* #undef HAVE_DDRAW_H */

/* Define to 1 if you have the <DeckLinkAPIDispatch.cpp> header file. */
/* #undef HAVE_DECKLINKAPIDISPATCH_CPP */

/* Define to 1 if you have the declaration of `nanosleep', and to 0 if you
   don't. */
#define HAVE_DECL_NANOSLEEP 1

/* Define to 1 if you have the `dirfd' function. */
#define HAVE_DIRFD 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <dxgidebug.h> header file. */
/* #undef HAVE_DXGIDEBUG_H */

/* Define to 1 if you have the <dxva2api.h> header file. */
/* #undef HAVE_DXVA2API_H */

/* Define to 1 if you have the <ebml/EbmlVersion.h> header file. */
#define HAVE_EBML_EBMLVERSION_H 1

/* Define to 1 if evas is enabled. */
/* #undef HAVE_EVAS */

/* Define to 1 if you have the `eventfd' function. */
#define HAVE_EVENTFD 1

/* Define to 1 if you have the <execinfo.h> header file. */
/* #undef HAVE_EXECINFO_H */

/* Define to 1 if you have the `fcntl' function. */
#define HAVE_FCNTL 1

/* Define to 1 if you have the `fdatasync' function. */
#define HAVE_FDATASYNC 1

/* Define to 1 if you have the `fdopendir' function. */
#define HAVE_FDOPENDIR 1

/* Define to 1 if you have the `ffsll' function. */
/* #undef HAVE_FFSLL */

/* Define to 1 if you have the `flockfile' function. */
#define HAVE_FLOCKFILE 1

/* Define to 1 if you have the <fontconfig/fontconfig.h> header file. */
/* #undef HAVE_FONTCONFIG_FONTCONFIG_H */

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define to 1 if you have the `fstatvfs' function. */
/* #undef HAVE_FSTATVFS */

/* Define to 1 if you have the `fsync' function. */
#define HAVE_FSYNC 1

/* Defined if having gcrypt */
#define HAVE_GCRYPT 1

/* Define to 1 if you have the `getdelim' function. */
/* #undef HAVE_GETDELIM */

/* Define to 1 if you have the `getenv' function. */
#define HAVE_GETENV 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getpid' function. */
#define HAVE_GETPID 1

/* Define to 1 if you have the `getpwuid_r' function. */
/* #undef HAVE_GETPWUID_R */

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the <GL/wglew.h> header file. */
/* #undef HAVE_GL_WGLEW_H */

/* Define to 1 if you have gmtime_r function */
#define HAVE_GMTIME_R 1

/* Define if you have the iconv() function and it works. */
#define HAVE_ICONV 1

/* Define to 1 if the system has the type `ID3D11VideoDecoder'. */
/* #undef HAVE_ID3D11VIDEODECODER */

/* Define to 1 if you have GNU libidn. */
/* #undef HAVE_IDN */

/* Define to 1 if you have the `if_nameindex' function. */
/* #undef HAVE_IF_NAMEINDEX */

/* Define to 1 if you have the `if_nametoindex' function. */
#define HAVE_IF_NAMETOINDEX 1

/* Define to 1 if you have inet_pton function */
#define HAVE_INET_PTON 1

/* Define to 1 if you have the <interface/mmal/mmal.h> header file. */
/* #undef HAVE_INTERFACE_MMAL_MMAL_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* For FreeBSD VCD support */
/* #undef HAVE_IOC_TOC_HEADER_IN_SYS_CDIO_H */

/* Define to 1 if you have the `isatty' function. */
#define HAVE_ISATTY 1

/* Define to 1 if you have the <jpeglib.h> header file. */
#define HAVE_JPEGLIB_H 1

/* Define to 1 if you have the <kai.h> header file. */
/* #undef HAVE_KAI_H */

/* Define to 1 if you have the <kva.h> header file. */
/* #undef HAVE_KVA_H */

/* Define to 1 if you have the <lauxlib.h> header file. */
/* #undef HAVE_LAUXLIB_H */

/* Define to 1 if you have the <libavcodec/avcodec.h> header file. */
#define HAVE_LIBAVCODEC_AVCODEC_H 1

/* Define to 1 if you have the <libavcodec/d3d11va.h> header file. */
/* #undef HAVE_LIBAVCODEC_D3D11VA_H */

/* Define to 1 if you have the <libavcodec/dxva2.h> header file. */
/* #undef HAVE_LIBAVCODEC_DXVA2_H */

/* Define to 1 if you have the <libavcodec/vaapi.h> header file. */
/* #undef HAVE_LIBAVCODEC_VAAPI_H */

/* Define to 1 if you have the <libavcodec/vda.h> header file. */
/* #undef HAVE_LIBAVCODEC_VDA_H */

/* Define to 1 if you have the <libavformat/avformat.h> header file. */
#define HAVE_LIBAVFORMAT_AVFORMAT_H 1

/* Define to 1 if you have the <libavformat/avio.h> header file. */
#define HAVE_LIBAVFORMAT_AVIO_H 1

/* Define to 1 if you have the <libavutil/avutil.h> header file. */
#define HAVE_LIBAVUTIL_AVUTIL_H 1

/* Define to 1 if you have the <libbpg.h> header file. */
/* #undef HAVE_LIBBPG_H */

/* Define this if you have libcddb installed */
/* #undef HAVE_LIBCDDB */

/* Define to 1 if you have the <libcrystalhd/bc_drv_if.h> header file. */
/* #undef HAVE_LIBCRYSTALHD_BC_DRV_IF_H */

/* Define to 1 if you have the <libcrystalhd/bc_dts_defs.h> header file. */
/* #undef HAVE_LIBCRYSTALHD_BC_DTS_DEFS_H */

/* Define to 1 if you have the `mingw32' library (-lmingw32). */
/* #undef HAVE_LIBMINGW32 */

/* Define to 1 if you have the <libswscale/swscale.h> header file. */
#define HAVE_LIBSWSCALE_SWSCALE_H 1

/* Define to 1 if you have the <libtar.h> header file. */
/* #undef HAVE_LIBTAR_H */

/* Define to 1 if you have the libvorbis */
#define HAVE_LIBVORBIS 1

/* Define to 1 if you have the <linux/dccp.h> header file. */
#define HAVE_LINUX_DCCP_H 1

/* Define to 1 if you have the <linux/magic.h> header file. */
#define HAVE_LINUX_MAGIC_H 1

/* Define to 1 if you have the <linux/videodev2.h> header file. */
/* #undef HAVE_LINUX_VIDEODEV2_H */

/* Define to 1 if you have the `lldiv' function. */
#define HAVE_LLDIV 1

/* Define to 1 if you have localtime_r function */
#define HAVE_LOCALTIME_R 1

/* Define to 1 if you have the lrintf function */
#define HAVE_LRINTF 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the <lualib.h> header file. */
/* #undef HAVE_LUALIB_H */

/* Define to 1 if you have the <lua.h> header file. */
/* #undef HAVE_LUA_H */

/* Define to 1 if you have the <mad.h> header file. */
#define HAVE_MAD_H 1

/* Define to 1 if you have the <matroska/KaxAttachments.h> header file. */
#define HAVE_MATROSKA_KAXATTACHMENTS_H 1

/* Define to 1 if you have the <matroska/KaxVersion.h> header file. */
#define HAVE_MATROSKA_KAXVERSION_H 1

/* Define to 1 if you have the `memalign' function. */
#define HAVE_MEMALIGN 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mkostemp' function. */
/* #undef HAVE_MKOSTEMP */

/* Define to 1 if you have the `mmap' function. */
#define HAVE_MMAP 1

/* Define to 1 if MMX intrinsics are available. */
/* #undef HAVE_MMX_INTRINSICS */

/* Define to 1 if you have the <mntent.h> header file. */
#define HAVE_MNTENT_H 1

/* Define to 1 if you have the <mpcdec/mpcdec.h> header file. */
/* #undef HAVE_MPCDEC_MPCDEC_H */

/* Define to 1 if you have the <mpc/mpcdec.h> header file. */
/* #undef HAVE_MPC_MPCDEC_H */

/* Define to 1 if you have the NANF function */
/* #undef HAVE_NANF */

/* Define to 1 if you have the <neaacdec.h> header file. */
/* #undef HAVE_NEAACDEC_H */

/* Define to 1 if you have the <netinet/udplite.h> header file. */
/* #undef HAVE_NETINET_UDPLITE_H */

/* Define to 1 if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define to 1 if you have the `nrand48' function. */
#define HAVE_NRAND48 1

/* Define to 1 if you have the `openat' function. */
#define HAVE_OPENAT 1

/* Define to 1 if you have the `open_memstream' function. */
/* #undef HAVE_OPEN_MEMSTREAM */

/* Define to 1 if you have the `pipe2' function. */
#define HAVE_PIPE2 1

/* Define to 1 if you have the <png.h> header file. */
#define HAVE_PNG_H 1

/* Define to 1 if you have the `poll' function. */
#define HAVE_POLL 1

/* Define to 1 if you have the `posix_fadvise' function. */
/* #undef HAVE_POSIX_FADVISE */

/* Define to 1 if you have the `posix_madvise' function. */
/* #undef HAVE_POSIX_MADVISE */

/* Define to 1 if you have the `posix_memalign' function. */
/* #undef HAVE_POSIX_MEMALIGN */

/* Define to 1 if you have the <postproc/postprocess.h> header file. */
/* #undef HAVE_POSTPROC_POSTPROCESS_H */

/* Define to 1 if you have the `pread' function. */
#define HAVE_PREAD 1

/* Define to 1 if using libprojectM 2.x */
/* #undef HAVE_PROJECTM2 */

/* Define to 1 if you have the `pthread_condattr_setclock' function. */
/* #undef HAVE_PTHREAD_CONDATTR_SETCLOCK */

/* Define to 1 if you have the `pthread_cond_timedwait_monotonic_np' function.
   */
#define HAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC_NP 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the <QuickTime/QuickTime.h> header file. */
/* #undef HAVE_QUICKTIME_QUICKTIME_H */

/* Define to 1 if you have the `rewind' function. */
#define HAVE_REWIND 1

/* Define to 1 if you have the <sapi.h> header file. */
/* #undef HAVE_SAPI_H */

/* Define to 1 if you have the `sched_getaffinity' function. */
/* #undef HAVE_SCHED_GETAFFINITY */

/* For NetBSD VCD support */
/* #undef HAVE_SCSIREQ_IN_SYS_SCSIIO_H */

/* Define to 1 if you have the <search.h> header file. */
/* #undef HAVE_SEARCH_H */

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the <SLES/OpenSLES.h> header file. */
#define HAVE_SLES_OPENSLES_H 1

/* Define to 1 if you have the <soundcard.h> header file. */
/* #undef HAVE_SOUNDCARD_H */

/* Define to 1 if sparkle is enabled. */
/* #undef HAVE_SPARKLE */

/* Define to 1 if SSE2 intrinsics are available. */
/* #undef HAVE_SSE2_INTRINSICS */

/* Define to 1 if <assert.h> defines static_assert. */
/* #undef HAVE_STATIC_ASSERT */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strcasestr' function. */
#define HAVE_STRCASESTR 1

/* Define to 1 if you have the `strcoll' function and it is properly defined.
   */
/* #undef HAVE_STRCOLL */

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* For dvdnav demux support */
#define HAVE_STREAM_CB_IN_DVDNAV_H 1

/* Define to 1 if you have the `stricmp' function. */
/* #undef HAVE_STRICMP */

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP 1

/* Define to 1 if you have the `strnicmp' function. */
/* #undef HAVE_STRNICMP */

/* Define to 1 if you have the `strnlen' function. */
#define HAVE_STRNLEN 1

/* Define to 1 if you have the `strnstr' function. */
/* #undef HAVE_STRNSTR */

/* Define to 1 if you have the `strptime' function. */
#define HAVE_STRPTIME 1

/* Define to 1 if you have the `strsep' function. */
#define HAVE_STRSEP 1

/* Define to 1 if you have the `strtof' function. */
/* #undef HAVE_STRTOF */

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if the system has the type `struct pollfd'. */
#define HAVE_STRUCT_POLLFD 1

/* Define to 1 if you have the `strverscmp' function. */
/* #undef HAVE_STRVERSCMP */

/* Define to 1 if you have the `swab' function. */
/* #undef HAVE_SWAB */

/* Define to 1 if you have the <sys/eventfd.h> header file. */
#define HAVE_SYS_EVENTFD_H 1

/* Define to 1 if you have the <sys/mount.h> header file. */
#define HAVE_SYS_MOUNT_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/shm.h> header file. */
/* #undef HAVE_SYS_SHM_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/soundcard.h> header file. */
/* #undef HAVE_SYS_SOUNDCARD_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/videoio.h> header file. */
/* #undef HAVE_SYS_VIDEOIO_H */

/* Define to 1 if you have the `tdestroy' function. */
/* #undef HAVE_TDESTROY */

/* Define if libtiger is available. */
/* #undef HAVE_TIGER */

/* Define to 1 if vlc is built against Tizen SDK */
/* #undef HAVE_TIZEN_SDK */

/* Define to 1 if you have the <tremor/ivorbiscodec.h> header file. */
/* #undef HAVE_TREMOR_IVORBISCODEC_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <unzip.h> header file. */
/* #undef HAVE_UNZIP_H */

/* Define to 1 if you have the `uselocale' function. */
/* #undef HAVE_USELOCALE */

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef HAVE_VALGRIND_VALGRIND_H */

/* Define to 1 if you have vasprintf function */
#define HAVE_VASPRINTF 1

/* Define to 1 if you have the <VideoDecodeAcceleration/VDADecoder.h> header
   file. */
/* #undef HAVE_VIDEODECODEACCELERATION_VDADECODER_H */

/* Define to 1 if you have the <VideoToolbox/VideoToolbox.h> header file. */
/* #undef HAVE_VIDEOTOOLBOX_VIDEOTOOLBOX_H */

/* Define to 1 if you have the `vmsplice' function. */
/* #undef HAVE_VMSPLICE */

/* Define to 1 if you have the <X11/Xlib.h> header file. */
/* #undef HAVE_X11_XLIB_H */

/* Define to 1 if you have the <xlocale.h> header file. */
/* #undef HAVE_XLOCALE_H */

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Define to 1 if you have the `_lock_file' function. */
/* #undef HAVE__LOCK_FILE */

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* Dynamic object extension */
#define LIBEXT ".so"

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to 1 if debug code should NOT be compiled */
/* #undef NDEBUG */

/* Define if <sys/param.h> defines ntohl. */
/* #undef NTOHL_IN_SYS_PARAM_H */

/* Define if you want to optimize memory usage over performance */
/* #undef OPTIMIZE_MEMORY */

/* Name of package */
#define PACKAGE "vlc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "vlc"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "vlc 3.0.0-git"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "vlc"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.0.0-git"

/* version development string */
#define PACKAGE_VERSION_DEV "git"

/* version extra number */
#define PACKAGE_VERSION_EXTRA 0

/* version major number */
#define PACKAGE_VERSION_MAJOR 3

/* version minor number */
#define PACKAGE_VERSION_MINOR 0

/* version revision number */
#define PACKAGE_VERSION_REVISION 0

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 for Unicode (Wide Chars) APIs. */
/* #undef UNICODE */

/* Define if you want to use the VLC update mechanism */
/* #undef UPDATE_CHECK */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "3.0.0-git"

/* Simple version string */
#define VERSION_MESSAGE "3.0.0-git Vetinari"

/* compiler */
#define VLC_COMPILER "gcc version 4.8 (GCC)"

/* user who ran configure */
#define VLC_COMPILE_BY "user"

/* host which ran configure */
#define VLC_COMPILE_HOST "user-OptiPlex-9020"

/* Define to 1 if you want to build for Windows Store apps */
#define VLC_WINSTORE_APP 0

/* Define to limit the scope of <windows.h>. */
#define WIN32_LEAN_AND_MEAN /**/

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if the X Window System is missing or not being used. */
#define X_DISPLAY_MISSING 1

/* Define if the zvbi module is built */
#define ZVBI_COMPILED 1

/* ISO C, POSIX, and 4.3BSD things. */
/* #undef _BSD_SOURCE */

/* Define to 64 for large files support. */
#define _FILE_OFFSET_BITS 64

/* Define to 2 to get glibc warnings. */
#define _FORTIFY_SOURCE 2

/* Extensions to ISO C99 from ISO C11. */
/* #undef _ISOC11_SOURCE */

/* Extensions to ISO C89 from ISO C99. */
/* #undef _ISOC99_SOURCE */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* IEEE Std 1003.1. */
/* #undef _POSIX_C_SOURCE */

/* IEEE Std 1003.1. */
/* #undef _POSIX_SOURCE */

/* ISO C, POSIX, and SVID things. */
/* #undef _SVID_SOURCE */

/* Same as _REENTANT for some other OSes. */
#define _THREAD_SAFE /**/

/* Define to 1 for Unicode (Wide Chars) APIs. */
/* #undef _UNICODE */

/* Define to '0x0600' for IE 6.0 (and shell) APIs. */
/* #undef _WIN32_IE */

/* POSIX and XPG 7th edition */
/* #undef _XOPEN_SOURCE */

/* XPG things and X/Open Unix extensions. */
/* #undef _XOPEN_SOURCE_EXTENDED */

/* Define within the LibVLC source code tree. */
#define __LIBVLC__ /**/

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Alias fdatasync() to fsync() if missing. */
/* #undef fdatasync */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#define restrict __restrict
/* Work around a bug in Sun C++: it does not support _Restrict or
   __restrict__, even though the corresponding Sun C compiler ends up with
   "#define restrict _Restrict" or "#define restrict __restrict__" in the
   previous line.  Perhaps some future version of Sun C++ will work with
   restrict; if so, hopefully it defines __RESTRICT like Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
# define __restrict__
#endif

/* Define to `sockaddr' if <sys/socket.h> does not define. */
/* #undef sockaddr_storage */

/* Define to `int' if <sys/socket.h> does not define. */
/* #undef socklen_t */

/* Define to `sa_family' if <sys/socket.h> does not define. */
/* #undef ss_family */

/* Define to `int' if <stddef.h> does not define. */
/* #undef ssize_t */

#include <vlc_fixups.h>


#ifndef __FAST_MATH__
# ifndef _MSC_VER
#  pragma STDC FENV_ACCESS OFF
#  pragma STDC FP_CONTRACT ON
# else
#  pragma fenv_access(off)
#  pragma fp_contract(on)
# endif
#endif

