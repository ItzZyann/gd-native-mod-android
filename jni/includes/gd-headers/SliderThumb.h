#pragma once
#include "gd.h"

// ItzZyann
// From Geode

class SliderThumb : public CCMenuItemImage {
public:
 static SliderThumb* create(CCNode*, SEL_MenuHandler, char const*, char const*);
 
 float getValue() {
  return (this->getScaleX() * m_length * .5f +
   (m_vertical ?
	this->getPositionY() :
	this->getPositionX())
   ) / (this->getScaleX() * m_length);
 }
 bool init(CCNode*, SEL_MenuHandler, char const*, char const*);
 void setMaxOffset(float);
 void setRotated(bool);
 void setValue(float);

 float m_length;
 bool m_vertical;
};