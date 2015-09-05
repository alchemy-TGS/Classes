#ifndef __Alchemy_TGS__HomunChooseScene__
#define __Alchemy_TGS__HomunChooseScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "HomeScene.h"
#include "HomunData.h"

#include "ScrollMenuView.h"

class HomunChooseScene : public cocos2d::Layer
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
	
	enum SoundNo{
		SOUND_NULL = -1,
		SOUND_OK,
		SOUND_NO,
		SOUND_SELECT,
	};

private:
    static const int homuns = 3;
    int partyHomun[homuns];
    
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	void initGra(int winWidth, int winHeight);
	void initScrollView();
    void addHomunButton(int i, int num);
	void soundManager(SoundNo soundNo);
	
	CREATE_FUNC(HomunChooseScene);
};

#endif /* defined(__Alchemy_TGS__HomunChooseScene__) */
