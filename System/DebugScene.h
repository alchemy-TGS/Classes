#ifndef __Alchemy_TGS__DebugScene__
#define __Alchemy_TGS__DebugScene__

#include <stdio.h>
#include "cocos2d.h"
class DebugScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	void BtnSet(int winWidth, int winHeight);
	
	
	CREATE_FUNC(DebugScene);
};




#endif /* defined(__Alchemy_TGS__DebugScene__) */
