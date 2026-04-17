#include "incl.h"

// Simple example mod
// Simple example mod
// Simple example mod

// we're gonna hook the main menu (MenuLayer)
// and just add a "Hello World" text in the middle

// pointer to the original function
bool (*MenuLayer_initO)(MenuLayer*);

// our custom version of init
bool MenuLayer_initH(MenuLayer* self) {

    // always call the original first
    if(!MenuLayer_initO(self)) 
        return false;

    // get screen size
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();

    // make a text label
    auto label = CCLabelBMFont::create("Hello World", "bigFont.fnt");

    // make it a bit smaller and center it
    label->setScale(0.8f);
    label->setPosition(winSize / 2);

    // add it to the menu
    self->addChild(label, 100);

    return true;
}


// ==============================
// replacing a button
// ==============================

// this one completely replaces the original function
// no need to call the original here

void MenuLayer_onMoreGames() {

    // when "More Games" is clicked, show a popup instead
    FLAlertLayer::create(
        nullptr,
        "Alert",
        "This is an alert.",
        "OK",
        nullptr,
        330
    )->show();
}


// ==============================
// entry point (runs when mod loads)
// ==============================

[[gnu::constructor]]
void mod_init() {

    // you usually get these names from tools like
    // ghidra or ida (or just from Addr.txt if you have it)

    // hook the menu init
    hook(
        "_ZN9MenuLayer4initEv",
        MenuLayer_initH,
        MenuLayer_initO
    );

    // hook the "More Games" button
    _hook(
        "_ZN9MenuLayer11onMoreGamesEPN7cocos2d8CCObjectE",
        MenuLayer_onMoreGames
    );
}