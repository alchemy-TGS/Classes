#include "AlchemyScene.h"
USING_NS_CC;
using namespace std;
#include <iostream>
Scene* AlchemyScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AlchemyScene::create();
	scene->addChild(layer);
	return scene;
}

bool AlchemyScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	
	initGra(size.width, size.height);
	initChar(size.width, size.height);
	Talk(size.width, size.height);
	
	talkNo = 0;
	return true;
}

void AlchemyScene::initGra(int winWidth, int winHeight){
	
	auto mesWin = Sprite::create();
	mesWin->setTextureRect(Rect(0, 0, winWidth - winWidth/10 , winHeight/2 - winHeight / 10));
	mesWin->setColor(Color3B(236,109,113));
	mesWin->setPosition(Point(winWidth / 2, winHeight / 4 * 3));
	mesWin->setTag(100);
	mesWin->setZOrder(100);
	addChild(mesWin);
}

void AlchemyScene::initChar(int winWidth, int winHeight){
	
	auto H2_normal	= Sprite::create("HomunImg/H2/H2_Card_SD_normal.png");
	auto H2_smile	= Sprite::create("HomunImg/H2/H2_Card_SD_smile.png");
	auto H2_trouble	= Sprite::create("HomunImg/H2/H2_Card_SD_trouble.png");
	auto H2_angry	= Sprite::create("HomunImg/H2/H2_Card_SD_angry.png");
	
	auto O2_normal	= Sprite::create("HomunImg/O2/O2_Card_SD_normal.png");
	auto O2_smile	= Sprite::create("HomunImg/O2/O2_Card_SD_smile.png");
	auto O2_trouble	= Sprite::create("HomunImg/O2/O2_Card_SD_trouble.png");
	auto O2_angry	= Sprite::create("HomunImg/O2/O2_Card_SD_angry.png");
	
	O2_normal->setFlippedX(true);
	O2_smile->setFlippedX(true);
	O2_trouble->setFlippedX(true);
	O2_angry->setFlippedX(true);
	
	H2_normal->setVisible(true);
	H2_smile->setVisible(false);
	H2_trouble->setVisible(false);
	H2_angry->setVisible(false);
	
	O2_normal->setVisible(true);
	O2_smile->setVisible(false);
	O2_trouble->setVisible(false);
	O2_angry->setVisible(false);
	
	H2_normal->setTag(11);
	H2_smile->setTag(12);
	H2_trouble->setTag(13);
	H2_angry->setTag(14);
	O2_normal->setTag(21);
	O2_smile->setTag(22);
	O2_trouble->setTag(23);
	O2_angry->setTag(24);
	
	H2_normal->setPosition(Point(winWidth - H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	H2_smile->setPosition(Point(winWidth - H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	H2_trouble->setPosition(Point(winWidth - H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	H2_angry->setPosition(Point(winWidth - H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	
	O2_normal->setPosition(Point(H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	O2_smile->setPosition(Point(H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	O2_trouble->setPosition(Point(H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	O2_angry->setPosition(Point(H2_normal->getContentSize().width / 2, H2_normal->getContentSize().height / 2));
	
	addChild(H2_normal);
	addChild(H2_smile);
	addChild(H2_trouble);
	addChild(H2_angry);
	addChild(O2_normal);
	addChild(O2_smile);
	addChild(O2_trouble);
	addChild(O2_angry);

}

void AlchemyScene::CharChange(int CharNo, int FaceNo, bool visible){
	auto H2_N = (Sprite*)this->getChildByTag(11);
	auto H2_S = (Sprite*)this->getChildByTag(12);
	auto H2_T = (Sprite*)this->getChildByTag(13);
	auto H2_A = (Sprite*)this->getChildByTag(14);
	auto O2_N = (Sprite*)this->getChildByTag(21);
	auto O2_S = (Sprite*)this->getChildByTag(22);
	auto O2_T = (Sprite*)this->getChildByTag(23);
	auto O2_A = (Sprite*)this->getChildByTag(24);

	
	
	
}

void AlchemyScene::Talk(int winWidth, int winHeight){
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	//	todo	もっと綺麗に。セリフ枠の
	
	auto tapArea = Sprite::create();

	tapArea->setContentSize(size);
	auto tapAreaItem = MenuItemSprite::create(tapArea, tapArea, CC_CALLBACK_1(AlchemyScene::Event, this));
	auto tapAreaMenu = Menu::create(tapAreaItem, NULL);
	addChild(tapAreaMenu);
	
	tapAreaMenu->setPosition(winWidth/2,winHeight/2);
	
	//		auto H2_N = (Sprite*)this->getChildByTag(11);
	auto mesWin = (Sprite*)this->getChildByTag(100);
	auto mes = Label::createWithSystemFont("イベントシーンイメージ", "Arial", 90);
	
	if (winHeight == 1024) {
		mes->setSystemFontSize(45);
	}
	
	mes->setPosition(mesWin->getPosition());
	mes->setZOrder(101);
	mes->setTag(101);
	addChild(mes);
	
	
	

}

void AlchemyScene::Event(Ref *pSrnder){
	auto H2_N = (Sprite*)this->getChildByTag(11);
	auto H2_S = (Sprite*)this->getChildByTag(12);
	auto H2_T = (Sprite*)this->getChildByTag(13);
	auto H2_A = (Sprite*)this->getChildByTag(14);
	auto O2_N = (Sprite*)this->getChildByTag(21);
	auto O2_S = (Sprite*)this->getChildByTag(22);
	auto O2_T = (Sprite*)this->getChildByTag(23);
	auto O2_A = (Sprite*)this->getChildByTag(24);

	auto mesWin = (Sprite*)this->getChildByTag(100);
	auto mes = (Label*)this->getChildByTag(101);
	log("%d",talkNo);
	
	switch (talkNo) {
		case 0:{
			O2_N->setColor(Color3B(128,128,128));
			mes->setString("タップで読み進める\n二行目");
			talkNo++;
			break;}
		case 1:{
			mesWin->setColor(Color3B(39,146,195));
			H2_N->setColor(Color3B(128,128,128));
			O2_N->setColor(Color3B::WHITE);
			mes->setString("俺はO2！");
			talkNo++;
			break;}
		case 2:{
			O2_N->setVisible(false);
			O2_S->setVisible(true);
			mes->setString("よろしくな！");
			talkNo++;
			break;}
		case 3:{
			mesWin->setColor(Color3B(236,109,113));
			O2_S->setColor(Color3B(128,128,128));
			H2_N->setColor(Color3B::WHITE);
			mes->setString("私はH2、水素です。");
			talkNo++;
			break;}
		case 4:{
			H2_N->setVisible(false);
			H2_T->setVisible(true);
			mes->setString("黒背景だったり、\n未完成な部分が多いのです……");
			talkNo++;
			break;}
		case 5:{
			H2_T->setVisible(false);
			H2_S->setVisible(true);
			mes->setString("パズルの基本部分は完成しました。\nでは……");
			talkNo++;
			break;}
		case 6:{
			mesWin->setColor(Color3B(39,146,195));
			H2_S->setColor(Color3B(128,128,128));
			O2_S->setColor(Color3B::WHITE);
			auto scale = ScaleTo::create(0.2,1.3);
			O2_S->runAction(scale);
			mes->setString("パズル画面をみてもらうぜ！");
			talkNo++;
			break;}
		case 7:{
			mesWin->setColor(Color3B(236,109,113));
			O2_S->setColor(Color3B(128, 128, 128));
			H2_S->setColor(Color3B::WHITE);
			H2_S->setVisible(false);
			H2_A->setVisible(true);
			H2_A->runAction(ScaleTo::create(0.2, 1.3));
			mes->setString("なんで先に言うのよー！");
			talkNo++;
			break;}
		case 8:{
			mesWin->setColor(Color3B(39,146,195));
			O2_S->setColor(Color3B::WHITE);
			H2_A->setColor(Color3B(128,128,128));
			O2_S->setVisible(false);
			O2_A->setScale(1.3);
			O2_A->setVisible(true);
			mes->setString("そんくらいいいだろ！\nドケチ！");
			talkNo++;
			break;}
		default:{
			auto nextScene = PuzzleScene::createScene();
			auto pScene = TransitionSlideInR::create(0.5f, nextScene);
			Director::getInstance()->replaceScene(pScene);
			break;}
	}
	
}