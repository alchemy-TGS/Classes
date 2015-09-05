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
	titleBgm->playBackgroundMusic("Sound/Title.mp3",true);

	return true;
}


void TitleScene::btnCreate(){
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
    
	auto bg = Sprite::create("SystemImg/title_bg.png");
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bg);
    
	auto bgCharactor = Sprite::create("SystemImg/title_homun.png");
	bgCharactor->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(bgCharactor);
	bgCharactor->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1.2, 1.01, 0.99),
																  ScaleTo::create(1.2, 1),
																  ScaleTo::create(1.2, 0.99, 1.01),
																  ScaleTo::create(1.2, 1),
																  NULL)));
	bg->setZOrder(0);
	bgCharactor->setZOrder(1);
	Sprite* Title = Sprite::create("SystemImg/title2.png");
	Title->setPosition(Point(visibleSize.width / 2, visibleSize.height / 4));
	addChild(Title);
	Title->setScale(1);
	Title->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1.2, 1.1),
															ScaleTo::create(1.2, 1),
															NULL)));
	Title->setZOrder(2);
	
	Sprite* tapChar = Sprite::create("SystemImg/title_tap.png");
	tapChar->setPosition(Point(visibleSize.width / 2, visibleSize.height / 15));
	addChild(tapChar);
	tapChar->setZOrder(3);
	
	tapChar->runAction(RepeatForever::create(Sequence::create(JumpBy::create(0.6, Vec2(0, 0), 32, 2),
															  DelayTime::create(3),
															  NULL)));
	Sprite* tapAreaSpr = Sprite::create();
	tapAreaSpr->setContentSize(visibleSize);
	MenuItemSprite* tapArea = MenuItemSprite::create(tapAreaSpr,tapAreaSpr,[](Ref*sender){
		auto nextScene = TownScene::createScene();
		auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
		Director::getInstance()->replaceScene(pScene);
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		auto sound = SimpleAudioEngine::getInstance();
		sound->playEffect("Sound/start.mp3");
		
	});
	tapArea->setPosition(visibleSize/2);
	auto tapMenu = Menu::create(tapArea ,NULL);
	tapMenu->setPosition(Point::ZERO);
	this->addChild(tapMenu);
	
}

void TitleScene::toHomeBtn(Ref *pSender){
	auto nextScene = HomeScene::createScene();
	auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}