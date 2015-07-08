#ifndef __Alchemy_TGS__EventImgData__
#define __Alchemy_TGS__EventImgData__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunData.h"

enum FaceNum{
	FACE_NULL = -1,
	FACE_DEFAULT,
	FACE_NORMAL,
	FACE_SMILE,
	FACE_ANGRY,
	FACE_TROUBLE,
};

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

enum AnimetionListNum{
	ANIMATION_NULL = -1,
	ANIMATION_IDLING,
	ANIMATION_HOMUN_SCALE_BIG,
	ANIMATION_HOMUN_SCALE_MIDIUM,
	ANIMATION_HOMUN_SCALE_LARGE,
};

class EventImgData{
private:
	static EventImgData* mEventImgData;
public:
	static EventImgData* getInstance();
	
	std::string getFaceImgPath(HomunNum homunNum, FaceNum faceNum);
	std::string getEmotionIconImagePath(EmotionNum emotionNum);
};

#endif /* defined(__Alchemy_TGS__EventImgData__) */
