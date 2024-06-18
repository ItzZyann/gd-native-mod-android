#pragma once
#include "incl.h"

class HelloWorld : public CCLayer {
public:
 static CCScene* scene();
 
 virtual bool init();
 virtual void keyBackClicked();
 
 void onBack(CCObject*);
 
 CREATE_FUNC(HelloWorld);
};