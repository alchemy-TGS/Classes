#ifndef __Alchemy_TGS__ResultScene__
#define __Alchemy_TGS__ResultScene__

#include <stdio.h>
#include "cocos2d.h"

class ResultScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ResultScene);
};


#endif /* defined(__Alchemy_TGS__ResultScene__) */
