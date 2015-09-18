#ifndef __Alchemy_TGS__TownScene2__
#define __Alchemy_TGS__TownScene2__

#include <stdio.h>
#include "cocos2d.h"
#include "PuzzleChooseScene.h"

class TownScene2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TownScene2);
	
	int count;
	bool bgCangeFlag;
	void filip(cocos2d::MenuItemSprite* spr);
};


#endif /* defined(__Alchemy_TGS__TownScene2__) */
