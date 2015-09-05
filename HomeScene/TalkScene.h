//
//  TalkScene.h
//  Alchemy_TGS
//
//  Created by 味噌汁馬子 on 2015/09/04.
//
//

#ifndef __Alchemy_TGS__TalkScene__
#define __Alchemy_TGS__TalkScene__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunChooseScene.h"
USING_NS_CC;

class TalkScene : public cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TalkScene);
	
};

#endif /* defined(__Alchemy_TGS__TalkScene__) */
