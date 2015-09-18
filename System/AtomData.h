#ifndef __Alchemy_TGS__AtomData__
#define __Alchemy_TGS__AtomData__

#include <stdio.h>
#include "cocos2d.h"


USING_NS_CC;

enum AtomNum{
	ATOM_H,
	ATOM_He,
	ATOM_Li,
	ATOM_Be,
	ATOM_B,
	ATOM_C,
	ATOM_N,
	ATOM_O,
};





class AtomData{
private:
	
public:
	static std::string GetName(AtomNum atomnum);
	static int GetBondCount(AtomNum atomnum);
	static std::string GetImageName(AtomNum atomnum);
	static std::string GetSafeBondImageName();
	static std::string GetPinchBondImageName();
    static int* GetDestroyPattern();
	static int GetDestroyPatternNum();
};
#endif /* defined(__Alchemy_TGS__AtomData__) */
