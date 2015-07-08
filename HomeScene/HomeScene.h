#ifndef __Alchemy_TGS__HomeScene__
#define __Alchemy_TGS__HomeScene__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunScene.h"
#include "QuestScene.h"
#include "TownScene.h"
#include "AlchemyScene.h"
#include "PuzzleScene.h"
#include "HomeScene.h"
#include "DebugScene.h"

class HomeScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HomeScene);
	
	//	重なり順
	enum ZOrder{
		backGround = 0,
		Fotter,
	};
	
	void initBackGround(float winWidth, float winHeight);
	void initFotterBtn(float winWidth, float winHeight);
	
	void FotterCreate(int winSizeWidth, int winSizeHeight);
	void transitionScene(Ref* pSender);
	
	void fotter_Home_Push(Ref* pSender);
	void fotter_Homun_Push(Ref* pSender);
	void fotter_Alchemy_Push(Ref* pSender);
	void fotter_Quest_Push(Ref* pSender);
	void fotter_Town_Push(Ref* pSender);
};


#endif /* defined(__Alchemy_TGS__HomeScene__) */
