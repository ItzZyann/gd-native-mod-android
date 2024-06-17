#pragma once

// DEFAULT INCLUDES
#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <iostream>

// COCOS INCLUDES
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

// GEOMETRY DASH INCLUDES (HEADERS)
#include "gd-headers/gd.h"

// KITTY MEMORY (LIB PATCHER)
#include "cores/KittyMemory/KittyMemory.h"
#include "cores/KittyMemory/KittyUtils.h"
#include "cores/KittyMemory/MemoryBackup.h"
#include "cores/KittyMemory/MemoryPatch.h"
#include "cores/Patch.h"

// FOR HOOKING
#include "cores/Hooking.h"

/*
ADD MORE THINGS HERE IF YOU WANT
BUT THIS IS JUST A NORMAL INCLUDE HEADER
XD... NOW ITS SIMPLE.
*/