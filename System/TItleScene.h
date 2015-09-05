#ifndef __Alchemy_TGS__TItleScene__
#define __Alchemy_TGS__TItleScene__

#include <stdio.h>
#include "cocos2d.h"
#include "HomeScene.h"
#include "TownScene.h"
class TitleScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	
	void btnCreate();
	
	
	void toHomeBtn(Ref* pSender);
	
	
	CREATE_FUNC(TitleScene);
};

#endif /* defined(__Alchemy_TGS__TItleScene__) */