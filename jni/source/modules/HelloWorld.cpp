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
 
 /*
 To make it this layer like, really
 alive, lets add Background, the Back Button.
 And some stuffs.
 */
 
 // First lets get the "GJ_gradientBG.png" first
 // Since this sprite is not on sprite sheet, lets use
 // the CCSprite::create(filename)
 
 CCSprite* bg = CCSprite::create("GJ_gradientBG.png");
 CCSize bgSize = bg->getTextureRect().size; // Now lets get the Sprite Size

 // Now lets setup the positioning
 // and scaling.
 bg->setAnchorPoint({0, 0});
 bg->setScaleX((winSize.width + 10) / bgSize.width);
 bg->setScaleY((winSize.height + 10) / bgSize.height);
 bg->setPosition({-5, -5});
 
 // Now the default bg Color.
 // The format is rgb
 // check out the main.cpp for more
 // instructions
 bg->setColor({0, 102, 255});
 
 // Now lets add the child.
 this->addChild(bg, -1);
 // I put -1 because it should be lower
 // But its your choice what z layer you want.
 
 /*
 Now lets setup the back button.
 Since we get the sprite on sprite sheet. We will
 use the "CCSprite::createWithSpriteFrameName(filename)
 Example:
 */
 
 CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
 
 // Now lets link the sprite
 // with CCMenuItemSpriteExtra so that
 // we can add callback.
 CCMenuItemSprite* backBtn = CCMenuItemSpriteExtra::create(
  backSpr, // unselected sprite
  backSpr, // selected sprite
  menu_selector(HelloWorld::onBack)); // the call back

 // Now lets create a menu for our back button
 // and we will add the backBtn.
 CCMenu* menu = CCMenu::create();
 menu->addChild(backBtn); // Adding the button

 // Set the position to the top left of the screen
 menu->setPosition({25, winSize.height - 25});

 this->addChild(menu); // Now lets add the menu.
 
 // Now everything we do
 // will be shown in HelloWorld Layer.
    
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

// Now to add a function on our
// custom function which is "onBack(CCObject*)"
// we should do the same as keyBackClicked.
void HelloWorld::onBack(CCObject* pSender) {
 keyBackClicked(); // Lets just call this function.
}