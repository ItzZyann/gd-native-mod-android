#pragma once
#include "gd.h"

#include "macros.h"

class GJGameLevel : public CCNode {
public:
 CLASS_MEMBER(int, levelID, 0x114);
 
public:
 static GJGameLevel* create();
 
 void setStars(int);
 void setLevelID(int);
 int getLevelID() { return this->_levelID(); }
};