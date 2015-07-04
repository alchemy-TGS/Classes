#ifndef __Alchemy_TGS__TownScene__
#define __Alchemy_TGS__TownScene__

#include <stdio.h>
#include "cocos2d.h"

class TownScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TownScene);
};


#endif /* defined(__Alchemy_TGS__TownScene__) */
