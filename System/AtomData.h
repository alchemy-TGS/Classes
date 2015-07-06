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
	static AtomData* mAtomData;
	
public:
	static AtomData* getInstance();
	
	std::string GetName(AtomNum atomnum);
	int GetBondCount(AtomNum atomnum);
	std::string GetImageName(AtomNum atomnum);
	std::string GetSafeBondImageName();
	std::string GetPinchBondImageName();
    int* GetDestroyPattern();
};
#endif /* defined(__Alchemy_TGS__AtomData__) */
