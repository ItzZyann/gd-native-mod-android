#include "incl.h"

#include "modules/HelloWorld.h"

/* There are 2 types of hooking.
First, is the returning the original hooking.
Second, is just a static hooking. (or whatever it called)
*/

// Lets hook the MenuLayer::init (The Main Menu)
// This hooking is Returning the Original.
// The O stands for "original"
// and the H stands for "Hook"
// But its your choice as long as you return,
// the Hook.
bool (*MenuLayer_initO)(MenuLayer*);
bool MenuLayer_initH(MenuLayer* self) {
 if(!MenuLayer_initO(self)) {
  return false;
 }
 
 /*
 Now, lets add a sprite on our Menu.
 There are 2 types of adding sprite.
 First is by getting the textures only in "assets"
 and Second is by getting the texture on "sprite sheet"
 
 to get the image on "assets" you should
 use the function "CCSprite::create(image filename)"
 
 to get the image on "sprite sheet" you should use
 the function "CCSprite::createWithSpriteFrameName(image name)"
 */
 
 CCDirector* dir = CCDirector::sharedDirector();
 CCSize winSize = dir->getWinSize();
 
 // Example on adding "assets" image.
 CCSprite* image1 = CCSprite::create("GJ_button_01.png");
 image1->setScale(1.3);
 image1->setPosition({
  winSize.width / 2, // Align in middle
  winSize.height / 2 - 30}); // Align in middle but lower - 30
  
 // Add the sprite, instead of using
 // "this", use the MenuLayer specified on top.
 // which is "self"
 
 self->addChild(image1, 100); // Now we added Image1 on our Menu
 
 // Now lets do getting the image on
 // sprite sheet.
 // Here is an Example.
 // And lets add a Function on the button.
 
 // First call CCMenu, to create a menu
 CCMenu* button = CCMenu::create();
 
 // Now position the button,
 // Instead of positioning the sprite, lets
 // position the button instead.
 
 button->setPosition({
  100, // This will be adding +100 start from left side
  winSize.height - 100}); // This will get the higher top screen, but with - 100
 
 /*
 Its your choice wether you use the sprite for
 positioning or not. But take note, that if you
 add a CCMenu dont forget to also add a position on it.
 */
 
 // Now lets create the sprite
 // And making it clickable.
 CCSprite* image2 = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
 image2->setColor({0, 255, 0});
 image2->setScale(.9);
 
 // This is a custom function
 // Made by RobTop itself, so lets call this.
 CCMenuItemSpriteExtra* imageClick = CCMenuItemSpriteExtra::create(
  image2, // Normal image, (unselected)
  image2, // Image but selected.
  self, // The Node that we use
  menu_selector(MenuLayer::onFullVersion)); // Callback, lets call the Full version Popup.
 
 // Now lets add this "imageClick" to CCMenu.
 button->addChild(imageClick);
 
 // And after adding the imageClick or the child
 // into our CCMenu, lets now add the CCMenu on our Main Menu.
 self->addChild(button, 100); // Now the button will be appear in Main Menu.
 
 return true;
}

// Now lets do the static Hook
// You dont need to return the original hook, its automatic
// Example, lets call the More Games button.
void MenuLayer_onMoreGames(CCObject* pSender) {
 /*
 Now, if you leave this function empty,
 the more games button will dont response anything.
 Because its empty, so now, lets add our
 "HelloWorld" layer, that if We click the
 "more games" button, it open the "HelloWorld" layer.
 */
 
 // Lets Initialize the Director
 CCDirector* dir = CCDirector::sharedDirector();
 
 // Now lets add the scene and the transition
 // theres too many types of transition, but lets
 // use the default one, which is Fade.
 
 // Theres, pushScene and replaceScene
 // so lets replace the MenuLayer scene to
 // HelloWorld scene.
 
 dir->replaceScene(
  CCTransitionFade::create(
  0.5, // Fade time interval.
  HelloWorld::scene()));
 
 // Now if we click the more games button
 // It will open the HelloWorld Layer.
 
 /*
 If you make a Custom Alert thing, you can
 check out the gd-headers and go to FLAlertLayer.h.
 There are instruction provided there on what the funtion to work.
 Like This example:
 
 (UNCOMMENT IT IF YOU WANT THIS TO WORK)
 (AND COMMENT THE REPLACE SCENE ONE)
 */
 
 /*
  FLAlertLayer::create(
   nullptr, // The Protocol (no need, aslong as you want instant)
   "Hello Mod", // The Title
   "ItzZyann here, this is cool!", // Description
   "Cancel", // Btn1, you can add a callback on this if you have protocol
   "OK", // Btn2, same as Btn1
   330)->show(); // The x_size, and call "show()" to show the alert.
 */
}

// To do the patcher, you should get
// the address of what you want to patch
void Patcher() {
 /* Example, we will patch the "ignore damage option"
 and always show in the settings.
 
 First is get the real address, and patch it
 in this func im gonna nop it.
 which is 00BF
 */
 
 patchLib(
  "libcocos2dcpp.so", // Name of the library
  0x00490e42, // The address of where to patch
  "00BF"); // Byte Patch (nop)
   
}

__attribute__((constructor))
void libgame_loader() {
 /* Now to do the hooking, we should
 get the function name, or string. Like
 for MenuLayer::init(), its "_ZN9MenuLayer4initEv",
 you should need like "IDA" or "GHIDRA", any times of
 dissasembler applications that load ".so" file.
 */
 
 // So lets hook the MenuLayer::init
 // Since its returning from Original Hook
 // lets use the default "hook"
 
 hook(
  "_ZN9MenuLayer4initEv", // The String or Function string name.
  MenuLayer_initH, // The Hook.
  MenuLayer_initO); // The Original Hook, for returning.
  
 // Now for static hook, we only need 
 // one name. But instead of using "hook"
 // lets add underscore on our hook name
 // Example:
 _hook("_ZN9MenuLayer11onMoreGamesEPN7cocos2d8CCObjectE",
  MenuLayer_onMoreGames);
  
 Patcher();
}