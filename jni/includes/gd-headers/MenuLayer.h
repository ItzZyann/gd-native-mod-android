#pragma once
#include "gd.h"

// ItzZyann

class MenuLayer : public CCLayer {
public:
 virtual bool init();
 void onOptions(CCObject*);
 void onFullVersion(CCObject*);
 void onPlay(CCObject*);
 void onCreator(CCObject*);
 void onStats(CCObject*);
 void onAchievements(CCObject*);
 void onNewgrounds(CCObject*);
 void onMyProfile(CCObject*);
 void onDaily(CCObject*);
 void onGarage(CCObject*);
 void onRobTop(CCObject*);
};
