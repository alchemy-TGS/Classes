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
}

void DebugScene::BtnSet(){
	
}