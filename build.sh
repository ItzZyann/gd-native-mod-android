LUSR=$(whoami)
NDK=/user/idk/android-ndk-path
SRC=$PWD

$NDK/ndk-build NDK_PROJECT_PATH=$SRC NDK_APPLICATION_MK=$SRC/jni/Application.mk MAIN_LOCAL_PATH=$SRC/jni
