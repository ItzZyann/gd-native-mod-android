#pragma once
#include "gd.h"

#include "macros.h"

// ItzZyann

class FLAlertLayerProtocol { };
class ScrollingLayer;
class FLAlertLayer : public CCLayerColor {
public:
 CLASS_MEMBER(CCMenu*, btnMenu, 0x1b8);
 CLASS_MEMBER(CCLayer*, internalLayer, 0x1c8);
 CLASS_MEMBER(ButtonSprite*, btn1, 0x1d4);
 CLASS_MEMBER(ButtonSprite*, btn2, 0x1d8);
 CLASS_MEMBER(ScrollingLayer*, scrollingLayer, 0x1dc);
 
 /*
 To get the members, its like
 this->_btnMenu()
 */
 
public:
 virtual bool init(int);
 
 static FLAlertLayer* create(
  FLAlertLayerProtocol* protocol,
  const char* title,
  std::string caption,
  const char* b1_title,
  const char* b2_title,
  float x_size);
  
 static FLAlertLayer* create(
  FLAlertLayerProtocol* protocol,
  const char* title,
  std::string caption,
  const char* b1_title,
  const char* b2_title,
  float x_size,
  bool add_border,
  float y_size,
  float unk);
    
 void show(void);
};