#pragma once
#include <dlfcn.h>

// include the hook file
// lets prio 64bit this time
// since google req. 64bit apps now.

#include "And64InlineHook/And64InlineHook.hpp"

#define hook(offset, hook, original) \
    A64HookFunction((void*)dlsym(dlopen("libcocos2dcpp.so", RTLD_LAZY), offset), (void*)hook, (void**)&original) \

#define _hook(offset, hook) \
    A64HookFunction((void*)dlsym(dlopen("libcocos2dcpp.so", RTLD_LAZY), offset), (void*)hook, NULL) \
