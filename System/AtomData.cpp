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

std::string image[] = {
	"AlchemyImg/AtomImg/atom_01.png",
	"AlchemyImg/AtomImg/atom_02.png",
	"AlchemyImg/AtomImg/atom_03.png",
	"AlchemyImg/AtomImg/atom_04.png",
	"AlchemyImg/AtomImg/atom_05.png",
	"AlchemyImg/AtomImg/atom_06.png",
	"AlchemyImg/AtomImg/atom_07.png",
	"AlchemyImg/AtomImg/atom_09.png",       //9?
};

std::string safeImage  = "AlchemyImg/BondImg/bond_01.png";
std::string pinchImage = "AlchemyImg/BondImg/bond_02.png";


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

int destroyPattern[8][8] = {
    //  H   He  li  Be  B   C   N   O   last
    {
        2,  0,  0,  0,  0,  0,  0,  0,
    },
    {
        0,  0,  0,  0,  0,  0,  0,  2,
    },
    {
        2,  0,  0,  0,  0,  0,  0,  1,
    },
    {
        2,  0,  0,  0,  0,  0,  0,  2,
    },
    {
        0,  0,  0,  0,  0,  4,  0,  0, //C単体て消したらまずいので解なし
    },
    {
        0,  0,  0,  0,  0,  1,  0,  2,
    },
    {
        0,  0,  0,  0,  0,  0,  2,  0,
    },
    {
        3,  0,  0,  0,  0,  0,  1,  0,
    },
};

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
int* AtomData::GetDestroyPattern()
{
    return *destroyPattern;
}