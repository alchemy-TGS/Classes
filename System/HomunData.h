#ifndef __Alchemy_TGS__HomunData__
#define __Alchemy_TGS__HomunData__

#include <stdio.h>
#include "cocos2d.h"


enum HomunNum{
    HOMUN_NULL = -1,
    HOMUN_H2,
    HOMUN_O2,
    HOMUN_H2O,
    HOMUN_H2O2,
    HOMUN_C,
    HOMUN_CO2,
    HOMUN_C2H5OH,
    HOMUN_N2,
    HOMUN_NH3,
    HOMUN_LAST_NUM,
};

class HomunData{
private:
    
public:
    
    static int* GetDropRate();
    static std::string getImageName(int num);
    static std::string getSkillImageName(int num);
    static int getSkillTrun(int num);
    //todo skillの効果を返し値or処理する方法を考える
};



#endif /* defined(__Alchemy_TGS__HomunData__) */
