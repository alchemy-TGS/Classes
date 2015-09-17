#include "QuestList.h"


std::string conditionImage[] = {
    "AlchemyImg/Header/QuestChar/quest_H2O.png",
};

int conditionType[] = {
    HOMUN_CO2,
};

int condition[] = {
    30,
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