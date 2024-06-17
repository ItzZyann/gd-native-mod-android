#pragma once
#include "gd.h"

// ItzZyann

class SearchButton : public CCSprite {
public:
 static SearchButton* create(
  const char* buttonTexture,
  const char* label,
  float labelScale,
  const char* icon);
};