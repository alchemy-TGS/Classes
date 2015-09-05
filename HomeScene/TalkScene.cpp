#include "TalkScene.h"
USING_NS_CC;

Scene* TalkScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TalkScene::create();
	scene->addChild(layer);
	return scene;
}

bool TalkScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	return true;
}
