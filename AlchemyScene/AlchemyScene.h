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
		ZO_TALKING_HOMUN,
		ZO_EMOTION_ICON,
	};
	enum Tag{
		TAG_NULL = -1,
		TAG_BackGround,
		TAG_BALLOON,
		TAG_L_EMOTION_ICON,
		TAG_R_EMOTION_ICON,
		TAG_L_TALKING_HOMUN,
		TAG_R_TALKING_HOMUN,
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
	void charChange(Tag tag, HomunNum homunNum, FaceNum faceNum);
	
	void emotionIconChange(Tag tag, EmotionNum emotionNum);
	//	トークイベント
	void talkEvent(int winWidth, int winHeight);
	
	CREATE_FUNC(AlchemyScene);
};


#endif /* defined(__Alchemy_TGS__AlchemyScene__) */
