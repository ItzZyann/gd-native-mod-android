#pragma once
#include "gd.h"

#include "macros.h"

// ItzZyann

class GJAccountManager : public CCNode {
public:
 CLASS_MEMBER(int, accId_rand, 0x110);
 CLASS_MEMBER(int, accId_seed, 0x114);
 
public:
 static GJAccountManager* sharedState();

 const char* getPassword();
 const char* getUsername();
 
 int accID() {
  // For some reason, I just created this
  // function just for my Zyann GDPS.
  return this->_accId_rand() + this->_accId_seed();
 } 
};