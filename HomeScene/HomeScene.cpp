#include "HomeScene.h"
USING_NS_CC;

Scene* HomeScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HomeScene::create();
	scene->addChild(layer);
	return scene;
}

bool HomeScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	initBackGround(size.width, size.height);
	initFotterBtn(size.width, size.height);
	return true;
}



void HomeScene::initBackGround(int winWidth, int winHeight){
	auto backGround = Sprite::create();
	Rect backGroundRect = Rect(0, 0, winWidth, winHeight);
	backGround->setTextureRect(backGroundRect);
	backGround->setColor(Color3B(188, 226, 232));
	backGround->setPosition(Point(winWidth / 2, winHeight / 2));
	addChild(backGround, ZOrder::backGround);
	}

void HomeScene::initFotterBtn(int winWidth, int winHeight){
	
	std::string fotterImgName[5]{
		"SystemImg/FotterImg/fotter_Home.png",
		"SystemImg/FotterImg/fotter_Homun.png",
		"SystemImg/FotterImg/fotter_Alchemy.png",
		"SystemImg/FotterImg/fotter_Quest.png",
		"SystemImg/FotterImg/fotter_Town.png"
	};
	
	int fotterImgSize;
	if (winHeight == 1024) {
		fotterImgSize = 128;
	}else{
		fotterImgSize = 256;
	}
	//	力技スタート　あとで修正
	int fotterPosY = winHeight / 16;
	int fotterPosXHint = winWidth / 12;
	
	
	auto homeSpr = Sprite::create(fotterImgName[0]);
	auto homePushSpr = Sprite::create(fotterImgName[0]);
	homePushSpr->setColor(Color3B(102, 102, 102));
	auto fotterHomeItem = MenuItemSprite::create(homeSpr, homePushSpr,CC_CALLBACK_1(HomeScene::fotter_Home_Push, this));
	auto fotterHomeMenu = Menu::create(fotterHomeItem, NULL);
	fotterHomeMenu->setPosition(Point(winWidth / 2 -(fotterPosXHint * 5), fotterPosY));
	this->addChild(fotterHomeMenu, ZOrder::Fotter, TAG_HOME);
	
	
	auto homunSpr = Sprite::create(fotterImgName[1]);
	auto homunPushSpr = Sprite::create(fotterImgName[1]);
	homunPushSpr->setColor(Color3B(102, 102, 102));
	auto fotterhomunItem = MenuItemSprite::create(homunSpr, homunPushSpr,CC_CALLBACK_1(HomeScene::fotter_Homun_Push, this));
	auto fotterhomunMenu = Menu::create(fotterhomunItem, NULL);
	fotterhomunMenu->setPosition(Point(winWidth / 2 -(fotterPosXHint * 3), fotterPosY));
	this->addChild(fotterhomunMenu, ZOrder::Fotter, TAG_HOMUN);
	
	auto AlchemySpr = Sprite::create(fotterImgName[2]);
	auto AlchemyPushSpr = Sprite::create(fotterImgName[2]);
	AlchemyPushSpr->setColor(Color3B(102, 102, 102));
	auto fotterAlchemyItem = MenuItemSprite::create(AlchemySpr, AlchemyPushSpr,CC_CALLBACK_1(HomeScene::fotter_Alchemy_Push, this));
	auto fotterAlchemyMenu = Menu::create(fotterAlchemyItem, NULL);
	fotterAlchemyMenu->setPosition(Point(winWidth / 2, fotterPosY));
	this->addChild(fotterAlchemyMenu, ZOrder::Fotter, TAG_ALCHEMY);
	
	auto QuestSpr = Sprite::create(fotterImgName[3]);
	auto QuestPushSpr = Sprite::create(fotterImgName[3]);
	QuestPushSpr->setColor(Color3B(102, 102, 102));
	auto fotterQuestItem = MenuItemSprite::create(QuestSpr, QuestPushSpr,CC_CALLBACK_1(HomeScene::fotter_Quest_Push, this));
	auto fotterQuestMenu = Menu::create(fotterQuestItem, NULL);
	fotterQuestMenu->setPosition(Point(winWidth / 2 +(fotterPosXHint * 3), fotterPosY));
	this->addChild(fotterQuestMenu, ZOrder::Fotter, TAG_QUEST);
	
	auto TownSpr = Sprite::create(fotterImgName[4]);
	auto TownPushSpr = Sprite::create(fotterImgName[4]);
	TownPushSpr->setColor(Color3B(102, 102, 102));
	auto fotterTownItem = MenuItemSprite::create(TownSpr, TownPushSpr,CC_CALLBACK_1(HomeScene::fotter_Town_Push, this));
	auto fotterTownMenu = Menu::create(fotterTownItem, NULL);
	fotterTownMenu->setPosition(Point(winWidth / 2 +(fotterPosXHint * 5), fotterPosY));
	this->addChild(fotterTownMenu, ZOrder::Fotter, TAG_TOWN);
	
	
	/*
	for (int i = 0; i < 5; i++) {
		auto fotterItem = MenuItemImage::create(fotterImgName[i], fotterImgName[i],
												CC_CALLBACK_1(HomeScene::transitionScene, this));
		Menu* fotterMenu = Menu::create(fotterItem, NULL);
		float fotterPosX;
		
		switch (i) {
			case 0: fotterPosX = winWidth / 2 -(fotterPosXHint * 5);
			case 1:	fotterPosX = winWidth / 2 -(fotterPosXHint * 3);
			case 3:	fotterPosX = winWidth / 2 +(fotterPosXHint * 3);
			case 4:	fotterPosX = winWidth / 2 +(fotterPosXHint * 5);
			default:	fotterPosX = winWidth / 2;
		}
		fotterMenu->setPosition(Point(fotterPosX, fotterPosY));
		this->addChild(fotterMenu, HomeScene::ZOrder::Fotter, i);
	}
	 */
}

void HomeScene::transitionScene(Ref* pSender){
	
}
void HomeScene::fotter_Home_Push(Ref* pSender){
	
	auto nextScene = HomeScene::createScene();
	auto pScene = TransitionProgressHorizontal::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	
}

void HomeScene::fotter_Homun_Push(Ref* pSender){
	
	auto nextScene = HomunScene::createScene();
	auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	
}

void HomeScene::fotter_Alchemy_Push(Ref* pSender){
	
	auto nextScene = PuzzleScene::createScene();
	auto pScene = TransitionSlideInR::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	
}

void HomeScene::fotter_Quest_Push(Ref* pSender){
	
	auto nextScene = PuzzleChooseScene::createScene();
	auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
	
}

void HomeScene::fotter_Town_Push(Ref* pSender){
	
	auto nextScene = AlchemyScene::createScene();
	auto pScene = TransitionProgressInOut::create(0.5f, nextScene);
	Director::getInstance()->replaceScene(pScene);
}


HomeScene* HomeScene::mHomeScene = NULL;
HomeScene* HomeScene::getInstance(){
	if (mHomeScene == NULL) {
		mHomeScene = new HomeScene();
	}
	return mHomeScene;
}