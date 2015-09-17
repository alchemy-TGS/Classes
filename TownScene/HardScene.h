#ifndef __Alchemy_TGS__HardScene__
#define __Alchemy_TGS__HardScene__

#include <stdio.h>
#include "cocos2d.h"
#include "TItleScene.h"

class HardScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HardScene);
	
	int count;
	bool bgCangeFlag;
	void filip(cocos2d::MenuItemSprite* spr);
};


#endif /* defined(__Alchemy_TGS__HardScene__) */
