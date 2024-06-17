#pragma once
#include "gd.h"

// ItzZyann

class FLAlertLayerProtocol;
class FLAlertLayer : public CCLayerColor {
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