#include "incl.h"
#include "MenuLayer.h"

bool (*MenuLayer_initO)(MenuLayer*);
bool MenuLayer_initH(MenuLayer* pThis) {
    if(!MenuLayer_initO(pThis)) return false;

    auto dir = CCDirector::sharedDirector();
    auto winSize = dir->getWinSize();

    auto label = CCLabelBMFont::create("Hello World", "bigFont.fnt");
    label->setScale(.8);
    label->setPosition(winSize / 2);
    pThis->addChild(label, 100);

    return true;
}

__attribute__((constructor))
void lib_gdmod() {

    hook("_ZN9MenuLayer4initEv", MenuLayer_initH, MenuLayer_initO);
    
}