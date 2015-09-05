#include "TalkScene.h"
USING_NS_CC;
Scene* TownScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TownScene::create();
	scene->addChild(layer);
	return scene;
}

bool TownScene::init()
{
	if ( !Layer::init() ){return false;}
	
	count = 0;
	
	bgCangeFlag = false;
	
	static auto view = Director::getInstance()->getOpenGLView();
	static auto size = view->getFrameSize();
	
	static auto bg1 = Sprite::create("TownImg/sample01.png");
	bg1->setPosition(size/2);
	bg1->setZOrder(1);
	addChild(bg1, 1, 1);
	
	static auto bg2 = Sprite::create("TownImg/sample02.png");
	bg2->setPosition(size/2);
	bg2->setZOrder(1);
	bg2->setVisible(false);
	addChild(bg2, 1, 1);
	
	static auto mesWin = Sprite::create("SystemImg/talkWindow.png");
	mesWin->setPosition(Point(size.width / 2, size.height / 4 * 3));
	mesWin->setVisible(false);
	addChild(mesWin, 2, 2);
	
	static auto mes = Label::createWithSystemFont("","fonts/mplus-1m-medium.ttf", 90);
	mes->setColor(Color3B::BLACK);
	mes->setPosition(mesWin->getPosition());
	mes->setVisible(false);
	addChild(mes, 3, 3);
	
	/*
	auto arrowspr = Sprite::create("TownImg/arrow.png");
	arrowspr->setPosition(Point::ZERO);
	static auto* arrowItem = MenuItemSprite::create(arrowspr,arrowspr,[this](Ref*sender){
		if(bgCangeFlag == false){
			bg1->setVisible(false);
			bg2->setVisible(true);
			bgCangeFlag = true;
		}else{
			bg1->setVisible(true);
			bg2->setVisible(false);
			bgCangeFlag = false;
		}
	});
	
	arrowItem->setPosition(visibleSize/2);
	auto arrowMenu = Menu::create(arrowItem ,NULL);
	arrowMenu->setPosition(Point::ZERO);
	arrowMenu->setZOrder(2);
	this->addChild(arrowMenu);
	*/
	
	static auto homun1spr1 = Sprite::create("HomunImg/H2/H2_Card_SD_normal.png");
	homun1spr1->setPosition(Point(size.width / 2, size.height/5));
	homun1spr1->setScale(0.8);
	addChild(homun1spr1, 4,4);

	Sprite* tapAreaSpr = Sprite::create();
	
	tapAreaSpr->setContentSize(size);
	
	MenuItemSprite* tapArea = MenuItemSprite::create(tapAreaSpr,tapAreaSpr,[this](Ref*sender){
		switch (count) {
			case 0:
				log("TapOK");
				
				mes->setVisible(true);
				mesWin->setVisible(true);
				break;
			case 1:
				homun1spr1->setTexture("HomunImg/H2/H2_Card_SD_smile.png");
				mes->setString("はじめまして！\nあるけみぃの世界へようこそ！"); break;
			case 2:
				homun1spr1->setTexture("HomunImg/H2/H2_Card_SD_normal.png");
				mes->setString("私は、H2\n（エイチ・ツー・オー）です。\n物質名は水素です。"); break;
			case 3:
				
				mes->setString("あなたは錬金術士として、\nこの街にやって来ました。"); break;
			case 4:
				homun1spr1->setTexture("HomunImg/H2/H2_Card_SD_smile.png");
				mes->setString("これから、\n一緒に街を発展させましょう！");
				break;
			case 5:
				mesWin->setVisible(false);
				mes->setVisible(false);
				static auto stil = Sprite::create("TownImg/H2_s.png");
				stil->setPosition(size/2);
				stil->setZOrder(5);
				this->addChild(stil);
				stil->runAction(FadeIn::create(0.5));
				break;
			
			case 6:
				stil->runAction(FadeOut::create(0.5));
				mesWin->setVisible(true);
				mes->setVisible(true);
				homun1spr1->setTexture("HomunImg/H2/H2_Card_SD_normal.png");
				mes->setString("では早速、\n簡単な錬金をしてみましょうか。");
				break;
				
			case 7:
				mes->setString("操作説明チュートリアル\n（省略）");
				break;
			case 8:{
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
	
	/*	auto homun1spr2 = Sprite::create("HomunImg/H2/H2_Card_SD_smile.png");
	homun1spr1->setPosition(Point::ZERO);
	homun1spr2->setPosition(Point::ZERO);
	auto homun1Item = MenuItemSprite::create(homun1spr1, homun1spr2,[this](Ref*sender){
		log("homun1Tap!");
		mesWin->setVisible(true);
		mes->setVisible(true);
		tapspr->setVisible(true);
	});
	homun1Item->setPosition(visibleSize/2);
	auto homun1Menu = MenuItemSprite::create(homun1Item, NULL);
	homun1Menu->setPosition(Point::ZERO);
	addChild(homun1Menu, 5, 1);
*/
	return true;
}