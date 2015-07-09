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
	"",
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
	"",
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
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
};


HomunData* HomunData::mHomunData = NULL;
HomunData* HomunData::getInstance()
{
	
	if(mHomunData == NULL)
	{
		mHomunData = new HomunData();
	}
	
	return mHomunData;
}

std::string HomunData::getImageName(HomunNum num)
{
    return homunImage[num];
}

int* HomunData::GetDropRate()
{
    return dropRate[0];
}
std::string HomunData::getSkillImageName(HomunNum num)
{
    return skillImage[num];
}
int HomunData::getSkillTrun(HomunNum num)
{
    return skillTrun[num];
}
