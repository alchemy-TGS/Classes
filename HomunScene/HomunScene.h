#ifndef __Alchemy_TGS__HomunScene__
#define __Alchemy_TGS__HomunScene__

#include <stdio.h>
#include "cocos2d.h"

class HomunScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HomunScene);
};


#endif /* defined(__Alchemy_TGS__HomunScene__) */
