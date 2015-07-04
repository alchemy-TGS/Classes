#include "QuestScene.h"
USING_NS_CC;

Scene* QuestScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuestScene::create();
	scene->addChild(layer);
	return scene;
}

bool QuestScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	return true;
}
