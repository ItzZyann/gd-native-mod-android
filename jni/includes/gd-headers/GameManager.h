#pragma once
#include "gd.h"

#include "macros.h"

// ItzZyann

class PlayLayer;
class GameManager : public CCNode {
public:
 CLASS_MEMBER(PlayLayer*, playLayer, 0x16c);
 
public:
 static GameManager* sharedState();
 void setGameVariable(const char*, bool);
 void setIntGameVariable(const char*, int);
 
 void toggleGameVariable(const char*);
 
 int getGameVariable(const char*);
 int getIntGameVariable(const char*);
 
 void loadBackground(int);
 void loadGround(int);
 void loadMiddleground(int);
 
 void setHasRatingPower(int);
 
 void safePopScene(void);
};