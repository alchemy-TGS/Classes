#include "TownScene.h"
USING_NS_CC;
Scene* TownScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TownScene::create();
	scene->addChild(layer);
	return scene;
}

bool TownScene::init()
{
	if ( !Layer::init() ){return false;}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return true;
}