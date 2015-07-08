#ifndef __Alchemy_TGS__EventImgData__
#define __Alchemy_TGS__EventImgData__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunData.h"

enum FaceNum{
	FACE_NULL = -1,
	FACE_NORMAL = 1,
	FACE_SMILE,
	FACE_ANGRY,
	FACE_TROUBLE,
};

class EventImgData{
private:
	static EventImgData* mEventImgData;
public:
	static EventImgData* getInstance();
	
	std::string getFaceImgPath(HomunNum homunNum, FaceNum faceNum);
	
};

#endif /* defined(__Alchemy_TGS__EventImgData__) */
