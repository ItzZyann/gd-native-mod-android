LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := dobby
LOCAL_SRC_FILES := includes/prebuilts/libdobby.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := hooking
LOCAL_SHARED_LIBRARIES := dobby
LOCAL_SRC_FILES := includes/prebuilts/libhooking.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := fmod
LOCAL_SRC_FILES := includes/prebuilts/libfmod.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
COCOS_PATH := $(LOCAL_PATH)/includes/cocos2d-x
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := cocos2dcpp
LOCAL_SRC_FILES := includes/prebuilts/libcocos2dcpp.so 
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/includes/cocos2d-x/include \
						   $(LOCAL_PATH)/includes/gd-headers \
						   $(COCOS_PATH)/includes \
						   $(COCOS_PATH)/include \
						   $(COCOS_PATH)/kazmath/include \
						   $(COCOS_PATH)/platform/android \
						   $(COCOS_PATH)/support \
						   $(COCOS_PATH)/ \
						   $(COCOS_PATH)/base_nodes \
						   $(COCOS_PATH)/extensions/DS_Dictionary \
						   $(COCOS_PATH)/platform \
						   $(COCOS_PATH)/extensions \

include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CFLAGS := -w
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := game
LOCAL_DISABLE_FORMAT_STRING_CHECKS := true
LOCAL_SHARED_LIBRARIES := cocos2dcpp hooking
TARGET_ARCH_ABI := all
LOCAL_C_INCLUDES += $(LOCAL_PATH)/includes \
                    $(LOCAL_PATH)/includes/cores \

LOCAL_SRC_FILES := source/main.cpp \
                   source/modules/HelloWorld.cpp \
				   includes/cores/KittyMemory/KittyMemory.cpp \
				   includes/cores/KittyMemory/KittyUtils.cpp \
				   includes/cores/KittyMemory/MemoryBackup.cpp \
				   includes/cores/KittyMemory/MemoryPatch.cpp \

LOCAL_LDLIBS := -llog \
				-frtti \
				-lEGL \
				-lGLESv2

include $(BUILD_SHARED_LIBRARY)