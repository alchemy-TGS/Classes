#ifndef __Alchemy_TGS__QuestScene__
#define __Alchemy_TGS__QuestScene__

#include <stdio.h>
#include "cocos2d.h"

class QuestScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuestScene);
};


#endif /* defined(__Alchemy_TGS__QuestScene__) */
