#ifndef __Alchemy_TGS__LibraryScene__
#define __Alchemy_TGS__LibraryScene__

#include <stdio.h>
#include "cocos2d.h"

class LibraryScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LibraryScene);
};


#endif /* defined(__Alchemy_TGS__LibraryScene__) */
