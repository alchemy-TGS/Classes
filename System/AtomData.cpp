#include "AtomData.h"

USING_NS_CC;

std::string name[] = {
	"AlchemyImg/Char/char_H.png",
	"He",
	"Li",
	"Be",
	"B",
	"AlchemyImg/Char/char_C.png",
	"AlchemyImg/Char/char_N.png",
	"AlchemyImg/Char/char_O.png",
};


int bondCount[] = {
	1,
	0,
	1,
	2,
	5,
	4,
	3,
	2,
};

std::string image[] = {
	"AlchemyImg/AtomImg/atom_01.png",
	"",
	"",
	"",
	"",
	"",
	"",
	"AlchemyImg/AtomImg/atom_09.png",
};

std::string safeImage  = "AlchemyImg/BondImg/bond_01.png";
std::string pinchImage = "AlchemyImg/BondImg/bond_02.png";


AtomData* AtomData::mAtomData = NULL;
AtomData* AtomData::getInstance()
{
	
	if(mAtomData == NULL)
	{
		mAtomData = new AtomData();
	}
	
	return mAtomData;
}



std::string AtomData::GetName(AtomNum atomnum)
{
	return name[atomnum];
}

int AtomData::GetBondCount(AtomNum atomnum)
{
	return bondCount[atomnum];
}

std::string AtomData::GetImageName(AtomNum atomnum)
{
	return image[atomnum];
}

std::string AtomData::GetSafeBondImageName()
{
	return safeImage;
}

std::string AtomData::GetPinchBondImageName()
{
	return pinchImage;
}
