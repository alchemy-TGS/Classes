#include "EventImgData.h"
USING_NS_CC;
using namespace std;
#include <iostream>

string homunFaceImgPath[] = {
	"HomunImg/Default.png",
	"HomunImg/H2/H2_Card_SD_normal.png",
	"HomunImg/H2/H2_Card_SD_smile.png",
	"HomunImg/H2/H2_Card_SD_angry.png",
	"HomunImg/H2/H2_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/O2/O2_Card_SD_normal.png",
	"HomunImg/O2/O2_Card_SD_smile.png",
	"HomunImg/O2/O2_Card_SD_angry.png",
	"HomunImg/O2/O2_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/H2O/H2O_Card_SD_normal.png",
	"HomunImg/H2O/H2O_Card_SD_smile.png",
	"HomunImg/H2O/H2O_Card_SD_angry.png",
	"HomunImg/H2O/H2O_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/H2O2/H2O2_Card_SD_normal.png",
	"HomunImg/H2O2/H2O2_Card_SD_smile.png",
	"HomunImg/H2O2/H2O2_Card_SD_angry.png",
	"HomunImg/H2O2/H2O2_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/C/C_Card_SD_normal.png",
	"HomunImg/C/C_Card_SD_smile.png",
	"HomunImg/C/C_Card_SD_angry.png",
	"HomunImg/C/C_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/CO2/CO2_Card_SD_normal.png",
	"HomunImg/CO2/CO2_Card_SD_smile.png",
	"HomunImg/CO2/CO2_Card_SD_angry.png",
	"HomunImg/CO2/CO2_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/C2H5OH/C2H5OH_Card_SD_normal.png",
	"HomunImg/C2H5OH/C2H5OH_Card_SD_smile.png",
	"HomunImg/C2H5OH/C2H5OH_Card_SD_angry.png",
	"HomunImg/C2H5OH/C2H5OH_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/H2/H2_Card_SD_normal.png",
	"HomunImg/H2/H2_Card_SD_smile.png",
	"HomunImg/H2/H2_Card_SD_angry.png",
	"HomunImg/H2/H2_Card_SD_trouble.png",
	"","","","","",
	"HomunImg/Default.png",
	"HomunImg/NH3/NH3_Card_SD_normal.png",
	"HomunImg/NH3/NH3_Card_SD_smile.png",
	"HomunImg/NH3/NH3_Card_SD_angry.png",
	"HomunImg/NH3/NH3_Card_SD_trouble.png",
	"","","","","",
};

string emotionIconImagePath[] = {
	"SystemImg/IconImg/iconDefault.png",
	"SystemImg/IconImg/exclamation.png",
	"SystemImg/IconImg/trouble.png",
	"SystemImg/IconImg/sad.png",
	"SystemImg/IconImg/angry.png",
	"SystemImg/IconImg/shy.png",
	"SystemImg/IconImg/hurry.png",
	"SystemImg/IconImg/idea.png",
};

EventImgData* EventImgData::mEventImgData = NULL;
EventImgData* EventImgData::getInstance(){
	if (mEventImgData == NULL) {
		mEventImgData = new EventImgData();
	}
	return mEventImgData;
}

string EventImgData::getFaceImgPath(HomunNum homunNum, FaceNum faceNum){
	return homunFaceImgPath[10 * homunNum + faceNum];
};

string EventImgData::getEmotionIconImagePath(EmotionNum emotionNum){
	return emotionIconImagePath[emotionNum];
}