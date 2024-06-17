#pragma once

// DEFINITIONS
// ADD IF YOU WANT
#define CLASS_MEMBER(__TYPE__, __GETTER__, __OFFSET__) \
 inline __TYPE__& _##__GETTER__() { \
  return *((__TYPE__*)((uintptr_t)this + __OFFSET__)); \
 }
 
#define PAD(size) char __STR_CAT__(__, __STR_CAT__(pad, __LINE__))[size] = {};
