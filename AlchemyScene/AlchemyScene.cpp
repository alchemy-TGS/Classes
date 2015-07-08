#include "AlchemyScene.h"
#include <iostream>
USING_NS_CC;
using namespace std;
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
	talkEvent(size.width, size.height);
	
	return true;
}

void AlchemyScene::initGra(int winWidth, int winHeight){
	
	//	背景
	
	//	セリフ枠
	
	//	感情アイコン
	
	//	ホムン初期配置		透明画像
	//	左側のキャラ
	auto L_Char = Sprite::create("HomunImg/Default.png");
	L_Char->setPosition(Point(L_Char->getContentSize().width / 2,
							  L_Char->getContentSize().height / 2));
	this->addChild(L_Char, ZO_TALKING_HOMUN, TAG_L_TALKING_HOMUN);
	
	auto R_Char = Sprite::create("HomunImg/Default.png");
	R_Char->setPosition(Point(winWidth - R_Char->getContentSize().width / 2,
							  R_Char->getContentSize().height / 2));
	this->addChild(R_Char, ZO_TALKING_HOMUN, TAG_R_TALKING_HOMUN);
}

void AlchemyScene::charChange(Tag tag, HomunNum homunNum, FaceNum faceNum){
	EventImgData* eventImgData = EventImgData::getInstance();
	auto spr = (Sprite*)this->getChildByTag(tag);
	Texture2D *tex = TextureCache::sharedTextureCache()->addImage(eventImgData->getFaceImgPath(homunNum, faceNum));
	//	スプライトの画像を変更する
	spr->setTexture(tex);
}

void AlchemyScene::talkEvent(int winWidth, int winHeight){
	auto L_Char = (Sprite*)this->getChildByTag(TAG_L_TALKING_HOMUN);
	auto R_Char = (Sprite*)this->getChildByTag(TAG_R_TALKING_HOMUN);

	charChange(TAG_L_TALKING_HOMUN, HOMUN_O2, FACE_NORMAL);
	charChange(TAG_R_TALKING_HOMUN, HOMUN_H2, FACE_NORMAL);
}