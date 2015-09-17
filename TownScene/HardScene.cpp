#include "HardScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
Scene* HardScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HardScene::create();
	scene->addChild(layer);
	return scene;
}

bool HardScene::init()
{
	if ( !Layer::init() ){return false;}
	
	count = 0;
	
	bgCangeFlag = false;
	
	static auto view = Director::getInstance()->getOpenGLView();
	static auto size = view->getFrameSize();
	
	static auto bg1 = Sprite::create("TownImg/s2.png");
	bg1->setPosition(size/2);
	bg1->setZOrder(1);
	addChild(bg1, 1, 1);
	
	static auto mesWin = Sprite::create("SystemImg/talkWindow.png");
	mesWin->setPosition(Point(size.width / 2, size.height / 6));
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
				log("TapOK");
				
				mes->setVisible(true);
				mesWin->setVisible(true);
				
				mes->setString("あなたは……？"); break;
				break;
			case 1:
				mes->setString("……そうですか。\nあなたが噂の錬金術士さん……。"); break;
			case 2:
				mes->setString("私は、エタノールです。\nよろしくお願いしますね。"); break;
			case 3:
				mes->setString("えっと、本日のあるけみぃの\n試遊はここまでになります。"); break;
			case 4:
				mes->setString("今後はもっともっと\n私達の仲間が増える予定です。");break;
			case 6:
				mes->setString("よろしければ\nまた、遊んでください。");break;
			case 7:
				mes->setString("ありがとうございました。");break;
			case 8:
			{
				auto nextScene = TitleScene::createScene();
				auto pScene = TransitionFade::create(0.5f, nextScene);
				Director::getInstance()->replaceScene(pScene);
				break;
			}
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