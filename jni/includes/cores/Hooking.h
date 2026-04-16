#pragma once
#include <jni.h>
#include <dlfcn.h>
#include <cstdio>
#include <pthread.h>

// include the hook file
// lets prio 64bit this time
// since google req. 64bit apps now.

#include "And64InlineHook/And64InlineHook.hpp"

#define hook(offset, hook, original) \
    A64HookFunction((void*)dlysm(dlopen("libcocos2dcpp.so", RTLD_LAZY), offset, (void*)hook, (void**)&original)) \

#define _hook(offset, hook) \
    A64HookFunction((void*)dlysm(dlopen("libcocos2dcpp.so", RTLD_LAZY), offset, (void*)hook, NULL)) \
