#include "TownScene2.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
Scene* TownScene2::createScene()
{
	auto scene = Scene::create();
	auto layer = TownScene2::create();
	scene->addChild(layer);
	return scene;
}

bool TownScene2::init()
{
	if ( !Layer::init() ){return false;}
	
	count = 0;
	
	auto savedata = CCUserDefault::getInstance();
	savedata->setIntegerForKey("ClearSceneKey", 1);
	savedata->setIntegerForKey("QuestConditionKey", 2);
	savedata->flush();
	
	static auto titleBgm = SimpleAudioEngine::getInstance();
	titleBgm->setBackgroundMusicVolume(2.0f);
	titleBgm->playBackgroundMusic("Sound/Title.mp3",true);
	
	bgCangeFlag = false;
	
	static auto view = Director::getInstance()->getOpenGLView();
	static auto size = view->getFrameSize();
	
	static auto bg1 = Sprite::create("TownImg/H2_s.png");
	bg1->setPosition(size/2);
	bg1->setZOrder(1);
	addChild(bg1, 1, 1);

	
	static auto mesWin = Sprite::create("SystemImg/talkWindow.png");
	mesWin->setPosition(Point(size.width / 2, size.height / 8));
	mesWin->setVisible(false);
	addChild(mesWin, 2, 2);
	
	static auto mes = Label::createWithSystemFont("","fonts/mplus-1m-medium.ttf", 90);
	mes->setColor(Color3B::BLACK);
	mes->setPosition(mesWin->getPosition());
	mes->setVisible(false);
	addChild(mes, 3, 3);

	Sprite* tapAreaSpr = Sprite::create();
	
	tapAreaSpr->setContentSize(size);
	
	MenuItemSprite* tapArea = MenuItemSprite::create(tapAreaSpr,tapAreaSpr,[this](Ref*sender){
		switch (count) {
			case 0:
				mes->setVisible(true);
				mesWin->setVisible(true);
				mes->setString("おみごとです！"); break;
			case 1:
				mes->setString("次はアンモニアを\nつくってみましょう。"); break;
			case 2:
				
				mes->setString("アンモニアは\nNが１つ、Hが３つ必要です。"); break;
			case 3:
				mes->setString("がんばってくださいね！");
				break;
			case 4:{
				SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
				auto nextScene = HomunChooseScene::createScene();
				auto pScene = TransitionFade::create(0.5f, nextScene);
				Director::getInstance()->replaceScene(pScene);
				break;}
			default:break;
		}
		count++;
	});
	tapArea->setPosition(size/2);
	auto tapMenu = Menu::create(tapArea ,NULL);
	tapMenu->setPosition(Point::ZERO);
	this->addChild(tapMenu);

	return true;
}