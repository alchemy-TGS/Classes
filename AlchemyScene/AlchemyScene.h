#ifndef __Alchemy_TGS__AlchemyScene__
#define __Alchemy_TGS__AlchemyScene__

#include <stdio.h>
#include "cocos2d.h"
//#include "PuzzleScene.h"
#include "TItleScene.h"
#include "EventImgData.h"
class AlchemyScene : public cocos2d::Layer
{
protected:
	enum ZOrder{
		ZOrder_NULL = -1,
		ZO_BACKGROUND,
		ZO_BALLOON,
		ZO_TALKING_CHAR,
		ZO_TALKING_HOMUN,
		ZO_EMOTION_ICON,
	};
	enum Tag{
		TAG_NULL = -1,
		TAG_BackGround,
		TAG_BALLOON,
		TAG_TALKING_CHAR,
		TAG_L_EMOTION_ICON,
		TAG_R_EMOTION_ICON,
		TAG_L_TALKING_HOMUN,
		TAG_R_TALKING_HOMUN,
	};
	
	enum AnimationListNum{
		ANIMATION_NULL = -1,
		ANIMATION_IDLING,
		ANIMATION_HOMUN_SCALE_BIG,
		ANIMATION_HOMUN_SCALE_MIDIUM,
		ANIMATION_HOMUN_SCALE_LITTLE,
	};
	enum HomunNo{
		Homun_NULL = -1,
		Homun_H2,
		Homun_O2,
	};

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	EventImgData* eventImgData = EventImgData::getInstance();
	
	
	//	画像の初期設置
	void initGra(int winWidth, int winHeight);
	
	//	画像の変更（ホムンの表情を変える）
	//	homunNumはホムンの種類		faceNumは表情の種類
	//	１通常、２笑顔、３怒り、４困る
	void charChange(cocos2d::Sprite* spr, HomunNum homunNum, FaceNum faceNum);
	
	void emotionIconChange(cocos2d::Sprite* spr, EmotionNum emotionNum);
	//	トークイベント
	void talkEvent(int winWidth, int winHeight);
	
	int tapCounter;
	
	void animationManager(cocos2d::Sprite*spr, AnimationListNum animationListNum);
	
	void talkNowColor(cocos2d::Sprite* spr);
	
	void balloonColorChange(HomunNo homunNo);
	CREATE_FUNC(AlchemyScene);
};


#endif /* defined(__Alchemy_TGS__AlchemyScene__) */
