#pragma once
#include "gd.h"

// ItzZyann

class ButtonSprite : public CCSprite {
public:
 static ButtonSprite* create(const char* label);
 static ButtonSprite* create(const char* label, float scale);
 void updateBGImage(const char*);
};