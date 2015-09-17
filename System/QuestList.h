#ifndef __Alchemy_TGS__QuestList__
#define __Alchemy_TGS__QuestList__

#include <stdio.h>
#include "cocos2d.h"
#include "HomunData.h"

class QuestList{
private:
    
public:
    
    static std::string getconditionImageName(int num);
    static int getconditionType(int num);
    static int getcondition(int num);
};

#endif /* defined(__Alchemy_TGS__QuestList__) */
