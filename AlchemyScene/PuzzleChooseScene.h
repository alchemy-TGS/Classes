#ifndef __Alchemy_TGS__PuzzleChooseScene__
#define __Alchemy_TGS__PuzzleChooseScene__

#include <stdio.h>
#include "cocos2d.h"
#include "HomeScene.h"

class PuzzleChooseScene : public cocos2d::Layer
{
protected:
	enum ZOrder{
		ZO_NULL = -1,
		ZO_BACKGROUND,
		ZO_LIST_FRAME,
		ZO_LIST_WHITE,
		ZO_LIST_CHAR,
	};
	enum Tag{
		TAG_NULL = -1,
		TAG_BACKGROUND,
		TAG_LIST_FRAME,
		TAG_LIST_WHITE,
		TAG_LIST_CHAR,
	};
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	void initGra(int winWidth, int winHeight);
	void initBtn(int winWidth, int winHeight);
	
	CREATE_FUNC(PuzzleChooseScene);
};



#endif /* defined(__Alchemy_TGS__PuzzleChooseScene__) */
