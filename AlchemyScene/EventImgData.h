#ifndef __Alchemy_TGS__EventImgData__
#define __Alchemy_TGS__EventImgData__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunData.h"

//	表情番号
enum FaceNum{
	FACE_NULL = -1,
	FACE_DEFAULT,
	FACE_NORMAL,
	FACE_SMILE,
	FACE_ANGRY,
	FACE_TROUBLE,
};

//	感情アイコン
enum EmotionNum{
	EMOTION_NULL = -1,
	EMOTION_DEFAULT,
	EMOTION_EXCLAMATION,
	EMOTION_TROUBLE,
	EMOTION_SAD,
	EMOTION_ANGRY,
	EMOTION_SHY,
	EMOTION_HURRY,
	EMOTION_IDEA,
};


class EventImgData{
private:
	static EventImgData* mEventImgData;
public:
	static EventImgData* getInstance();
	
	//	会話用画像
	std::string getFaceImgPath(HomunNum homunNum, FaceNum faceNum);
	
	//	感情アイコン画像
	std::string getEmotionIconImagePath(EmotionNum emotionNum);
	
	//	セリフ
	std::string getTalkLists(int talkNo);
};

#endif /* defined(__Alchemy_TGS__EventImgData__) */
