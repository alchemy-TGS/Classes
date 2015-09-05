#include "ResultScene.h"
USING_NS_CC;

Scene* ResultScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ResultScene::create();
	scene->addChild(layer);
	return scene;
}

bool ResultScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	
	auto charactor = Sprite::create("HomunImg/C/C_Card_SD_smile.png");
	charactor->setPosition(Point(size.width - charactor->getContentSize().width / 2, charactor->getContentSize().height / 2));
	addChild(charactor);
	auto mesWin = Sprite::create();
	mesWin->setTextureRect(Rect(0, 0, size.width - size.width/10 , size.height/2 - size.height / 10));
	mesWin->setColor(Color3B(112,108,170));
	mesWin->setPosition(Point(size.width / 2, size.height / 4 * 3));
	mesWin->setTag(100);
	mesWin->setZOrder(100);
	addChild(mesWin);
	
	auto mes = Label::createWithSystemFont("GameClear！", "Arial", 90);
	mes->setPosition(mesWin->getPosition());
	mes->setZOrder(101);
	mes->setTag(101);
	addChild(mes);

	return true;
}
