#ifndef __Alchemy_TGS__AtomClass__
#define __Alchemy_TGS__AtomClass__

#include <stdio.h>
#include "cocos2d.h"
#include "AtomData.h"

USING_NS_CC;

class Atom :public Layer {
private:
	
	int group;
	int initialGroup;
	
	CCLabelTTF* bondlabel;
	
	Rect getRect();
	
public:
	Sprite *atom;
	
	int bondCount;
	int initialBondCount;
	
	AtomNum atomnum;
	
	bool init(AtomNum type, int groupnum);
	void update(float delta);
	
	//  CREATE_FUNC(AtomData);
	
	bool isTapped(Point point);
	int getGroup();
	int getInitialGroup();
	void setGroup(int setgroup);
	void groupReset();
	void bondCountReset();
};


#endif /* defined(__Alchemy_TGS__AtomClass__) */