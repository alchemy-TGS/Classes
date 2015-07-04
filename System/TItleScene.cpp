#include "TItleScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
Scene* TitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

bool TitleScene::init()
{
	if ( !Layer::init() ){return false;}
	
	btnCreate();
	
	//	サウンドテスト
	static auto titleBgm = SimpleAudioEngine::getInstance();
	titleBgm->setBackgroundMusicVolume(1.0f);
	titleBgm->playBackgroundMusic("Sound/Title_BGM.mp3",true);

	return true;
}


void TitleScene::btnCreate(){
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	Rect bgRect = Rect(0, 0, visibleSize.width, visibleSize.height);
	auto bg = Sprite::create();
	bg->setTextureRect(bgRect);
	bg->setColor(Color3B(158, 196, 202));
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bg);
	
	auto bgCharactor = Sprite::create("HomunImg/H2/H2_Card_big.png");
	bgCharactor->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(bgCharactor);
	
	//ボタンの大きさを設定
	Rect toHomeBtnRect = Rect(0, 0, visibleSize.height / 4, visibleSize.width / 8);
	
	auto toHomeSpr1 = Sprite::create();
	toHomeSpr1->setTextureRect(toHomeBtnRect);
	toHomeSpr1->setColor(Color3B(22, 94, 180));
	
	auto toHomeSpr2 = Sprite::create();
	toHomeSpr2->setTextureRect(toHomeBtnRect);
	toHomeSpr2->setColor(Color3B(33, 60, 99));
	
	auto toHomeBtnItem = MenuItemSprite::create(toHomeSpr1, toHomeSpr2, CC_CALLBACK_1(TitleScene::toHomeBtn, this));
	auto toHomeBtnMenu = Menu::create(toHomeBtnItem, NULL);
	
	auto toHomeBtnLavel = Label::createWithSystemFont("Tap To Start!", "Arial", 64);
	if (visibleSize.height == 1024)
		toHomeBtnLavel->setScale(0.5f);
	toHomeBtnLavel->setColor(Color3B::WHITE);
	
	addChild(toHomeBtnLavel);
	
	toHomeBtnMenu->setPosition(Point(visibleSize.width / 2, visibleSize.height / 10));
	toHomeBtnLavel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 10));
	this->addChild(toHomeBtnMenu);
	
	bg->setZOrder(0);
	bgCharactor->setZOrder(1);
	toHomeBtnMenu->setZOrder(2);
	toHomeBtnLavel->setZOrder(3);
}

void TitleScene::toHomeBtn(Ref *pSender){
	auto nextScene = HomeScene::createScene();
	auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}