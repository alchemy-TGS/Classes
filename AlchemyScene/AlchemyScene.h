#ifndef __Alchemy_TGS__AlchemyScene__
#define __Alchemy_TGS__AlchemyScene__

#include <stdio.h>
#include "cocos2d.h"
#include "PuzzleScene.h"

class AlchemyScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	void Talk(int winWidth, int winHeight);
	void Event(Ref *pSrnder);
	
	
	int talkNo;
	CREATE_FUNC(AlchemyScene);
};


#endif /* defined(__Alchemy_TGS__AlchemyScene__) */
