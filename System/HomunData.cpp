#include "HomunData.h"

USING_NS_CC;


std::string homunImage[] = {
	"AlchemyImg/Card/H2_Card_SD_Alchemy.png",
	"AlchemyImg/Card/O2_Card_SD_Alchemy.png",
	"AlchemyImg/Card/H2O_Card_SD_Alchemy.png",
	"AlchemyImg/Card/H2O2_Card_SD_Alchemy.png",
	"AlchemyImg/Card/C_Card_SD_Alchemy.png",
	"AlchemyImg/Card/CO2_Card_SD_Alchemy.png",
	"AlchemyImg/Card/C2H5OH_Card_SD_Alchemy.png",
	"AlchemyImg/Card/H2_Card_SD_Alchemy.png",//空なので代用
    "AlchemyImg/Card/NH3_Card_SD_Alchemy.png",
};

std::string skillImage[] = {
	"HomunImg/H2/H2_Card_big.png",
	"HomunImg/O2/O2_Card_big.png",
	"HomunImg/H2O/H2O_Card_big.png",
	"HomunImg/H2O2/H2O2_Card_big.png",
	"HomunImg/C/C_Card_big.png",
	"HomunImg/CO2/CO2_Card_big.png",
	"HomunImg/C2H5OH/C2H5OH_Card_big.png",
	"HomunImg/H2/H2_Card_big.png",          //空なので代用
    "HomunImg/NH3/NH3_Card_big.png",
};


int dropRate[][5] =
{
    //  H   O   C   N   last
    {
        0,  95, 5,  0,  -1,
    },
    {
        95, 0,  5,  0,  -1,
    },
    {
        0,  0,  100,0,  -1,
    },
    {
        0,  0,  95, 5,  -1,
    },
    {
        10, 85, 0,  5,  -1,
    },
    {
        90, 0,  0,  10, -1,
    },
    {
        0,  0,  0,  100,-1,
    },
    {
        90, 10, 0,  0,  -1,
    },
    {
        0,  90, 10, 0,  -1,
    },
};

int skillTrun[] = {
    5,
    5,
    6,
    6,
    6,
    7,
    7,
    8,
    8,
};

//スキル発動時の延長時間
int skillTimeExtension[] = {
    10,
	10,
    20,
    20,
    20,
    20,
    20,
    20,
    20,
};

//原子生成確率を変更する時間
int skillEffectTime[]{
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
};

//スキル発動時の原子生成確率　＊合計が100を超えないようにしてください
int skillDropRate[][5]{
    //  H   O   C   N   last
    {
        100,  0,  0,  0,  -1,
    },
    {
        0,  100,  0,  0,  -1,
    },
    {
        0,  0,  100,  0,  -1,
    },
    {
        0,  0,  80,  20,  -1,
    },
    {
        0,  0,  100,  0,  -1,
    },
    {
        0,  50,  50,  0,  -1,
    },
    {
        30,  30,  30, 10,  -1,
    },
    {
        0,  0,  0,  0,  -1,
    },
    {
        30,  0,  0,  70,  -1,
    },
};


std::string HomunData::getImageName(int num)
{
    return homunImage[num];
}

int* HomunData::GetDropRate()
{
    return dropRate[0];
}
std::string HomunData::getSkillImageName(int num)
{
    return skillImage[num];
}
int HomunData::getSkillTrun(int num)
{
    return skillTrun[num];
}
int HomunData::getSkillTimeExtension(int num)
{
    return skillTimeExtension[num];
}
int HomunData::getSkillEffectTime(int num)
{
    return skillEffectTime[num];
}
int* HomunData::getSkillDropRate()
{
    return skillDropRate[0];
}