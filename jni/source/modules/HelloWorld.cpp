#include "HelloWorld.h"

CCScene* HelloWorld::scene() {
 CCScene* scene = CCScene::create();
 HelloWorld* layer = HelloWorld::create();
 
 scene->addChild(layer);
 
 return scene;
}

bool HelloWorld::init() {
 // Initialize super init first
 if(!CCLayer::init()) {
  return false;
 }
 
 CCDirector* dir = CCDirector::sharedDirector();
 CCSize winSize = dir->getWinSize();
 
 // Label arguments is "The Text you Want"
 // and the Font, which is ".fnt" files
 auto label = CCLabelBMFont::create(
  "Hello World!\nPress the back key to exit.",
  "bigFont.fnt");
 
 label->setScale(.7); // Set the scale of the label
 label->setPosition(winSize / 2); // This puts the label in the mid
 label->setColor({255, 255, 0}); // The format on setting color is RGB
 
 // The addChild function have 2 useful things
 // first is the node, and second is the z layering.
 
 this->addChild(label, 100);
 
 
 // If you enable this to true, it will
 // now uses the "keyBackClicked()" function
 // when we click the Back Button on our
 // phone.
 this->setKeypadEnabled(true);
 
 return true;
}

void HelloWorld::keyBackClicked() {
 /*
 Since GameManager already have a built in
 function that exits the Layer after executing
 this func, we can use it.
 */
 
 GameManager* manager = GameManager::sharedState();
 manager->safePopScene();
}