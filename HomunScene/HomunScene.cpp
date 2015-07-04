#include "HomunScene.h"
USING_NS_CC;

Scene* HomunScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HomunScene::create();
	scene->addChild(layer);
	return scene;
}

bool HomunScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	return true;
}
