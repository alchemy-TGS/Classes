#include "QuestList.h"


std::string conditionImage[] = {
    "AlchemyImg/Header/QuestChar/quest_H2O.png",
	"AlchemyImg/Header/QuestChar/quest_CO2.png",
	"AlchemyImg/Header/QuestChar/quest_NH3.png",
	"AlchemyImg/Header/QuestChar/quest_C2H5OH.png",
};

int conditionType[] = {
    HOMUN_H2O,
	HOMUN_CO2,
	HOMUN_NH3,
	HOMUN_C2H5OH,
};

int condition[] = {
     5,
	 5,
	 5,
	 5,
};


std::string QuestList::getconditionImageName(int num)
{
    return conditionImage[num];
}

int QuestList::getconditionType(int num)
{
    return conditionType[num];
}

int QuestList::getcondition(int num)
{
    return condition[num];
}