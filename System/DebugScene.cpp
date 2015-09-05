#include "DebugScene.h"
USING_NS_CC;

Scene* DebugScene::createScene()
{
	auto scene = Scene::create();
	auto layer = DebugScene::create();
	scene->addChild(layer);
	return scene;
}

bool DebugScene::init()
{
	if ( !Layer::init() ){return false;}
	
	return true;
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	BtnSet(size.width, size.height);
}

void DebugScene::BtnSet(int winWidth, int winHeight){
	

	
}