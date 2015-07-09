#include "PuzzleChooseScene.h"
#include <iostream>
using namespace std;
using namespace ui;
USING_NS_CC;

Scene* PuzzleChooseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PuzzleChooseScene::create();
	scene->addChild(layer);
	return scene;
}

bool PuzzleChooseScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	initGra(size.width, size.height);
	initBtn(size.width, size.height);
	
	Sprite* test = Sprite::create("HomunImg/NH3/NH3_Card_SD_smile.png");
	test->setPosition(size.width / 2, size.height / 2);
	addChild(test);
	test->setScale(0);
	test->runAction(EaseBackOut::create(ScaleTo::create(0.5f, 1)));
	test->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1.2, 1.1), ScaleTo::create(1.2, 0.9), NULL)));
	return true;
}



void PuzzleChooseScene::initGra(int winWidth, int winHeight){
	
	//	背景
	auto backGround = Sprite::create();
	Rect backGroundRect = Rect(0, 0, winWidth, winHeight);
	backGround->setTextureRect(backGroundRect);
	backGround->setColor(Color3B(188, 226, 232));
	backGround->setPosition(Point(winWidth / 2, winHeight / 2));
	addChild(backGround, ZOrder::ZO_BACKGROUND, Tag::TAG_BACKGROUND);
}


void PuzzleChooseScene::initBtn(int winWidth, int winHeight){
	//	ボタンのセット
	//	ホムンは　H2とO2とNH3
	auto List01 = Button::create("QuestImg/Quest_List_01.png");
	List01->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:{
				auto nextScene = PuzzleScene::createScene();
				auto pScene = TransitionFade::create(0.5f, nextScene);
				Director::getInstance()->replaceScene(pScene);
			}
				break;
			default:
				break;
		}
	});
	List01->setPosition(Point(winWidth / 2 , winHeight -512));
	this->addChild(List01);
	
	auto List02 = Button::create("QuestImg/Quest_List_02.png");
	List02->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:{
				auto nextScene = PuzzleScene::createScene();
				auto pScene = TransitionFade::create(0.5f, nextScene);
				Director::getInstance()->replaceScene(pScene);
			}

				break;
			default:
				break;
		}
	});
	List02->setPosition(Point(winWidth / 2 , List01->getPosition().y - 512));
	this->addChild(List02);

	auto List03 = Button::create("QuestImg/Quest_List_03.png");
	List03->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:{
				auto nextScene = PuzzleScene::createScene();
				auto pScene = TransitionFade::create(0.5f, nextScene);
				Director::getInstance()->replaceScene(pScene);
			}

				break;
			default:
				break;
		}
	});
	List03->setPosition(Point(winWidth / 2 , List02->getPosition().y - 512));
	this->addChild(List03);
	
	List02->setColor(Color3B(102, 102, 102));
	List02->setEnabled(false);
	List03->setColor(Color3B(102, 102, 102));
	List03->setEnabled(false);
}

