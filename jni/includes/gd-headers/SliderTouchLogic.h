#pragma once
#include "gd.h"

#include "Slider.h"
#include "SliderThumb.h"

// ItzZyann
// From Geode

class SliderTouchLogic : public CCMenu {
public:
 static SliderTouchLogic* create(CCNode*, SEL_MenuHandler, char const*, char const*, float);

 bool init(CCNode*, SEL_MenuHandler, char const*, char const*, float);
 void setMaxOffset(float);
 void setRotated(bool);

 virtual bool ccTouchBegan(CCTouch*, CCEvent*);
 virtual void ccTouchMoved(CCTouch*, CCEvent*);
 virtual void ccTouchEnded(CCTouch*, CCEvent*);
 virtual void registerWithTouchDispatcher();

 float m_unknownUnused;
 float m_length;
 SliderThumb* m_thumb;
 Slider* m_slider;
 bool m_activateThumb;
 CCPoint m_position;
 bool m_rotated;
};