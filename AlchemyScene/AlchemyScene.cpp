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
	
	
	//	ホムン初期配置		透明画像
	//	左側のキャラ
	auto L_Char = Sprite::create(eventImgData->getFaceImgPath(HomunNum::HOMUN_H2, FaceNum::FACE_DEFAULT));
	L_Char->setPosition(Point(L_Char->getContentSize().width / 2, L_Char->getContentSize().height / 2));
	this->addChild(L_Char, ZO_TALKING_HOMUN, TAG_L_TALKING_HOMUN);
	//	右側のキャラ
	auto R_Char = Sprite::create(eventImgData->getFaceImgPath(HomunNum::HOMUN_H2, FaceNum::FACE_DEFAULT));
	R_Char->setPosition(Point(winWidth - R_Char->getContentSize().width / 2,R_Char->getContentSize().height / 2));
	this->addChild(R_Char, ZO_TALKING_HOMUN, TAG_R_TALKING_HOMUN);
	
	//	感情アイコンの初期配置　透明画像
	//	左側キャラ
	auto L_EmotionIcon = Sprite::create(eventImgData->getEmotionIconImagePath(EMOTION_DEFAULT));
	L_EmotionIcon->setPosition(Point(L_Char->getPosition().x + L_Char->getContentSize().width / 2.8, L_Char->getPosition().y + L_Char->getContentSize().height / 3.3));
	this->addChild(L_EmotionIcon, ZO_EMOTION_ICON, TAG_L_EMOTION_ICON);
	//	右側キャラ
	auto R_EmotionIcon = Sprite::create(eventImgData->getEmotionIconImagePath(EmotionNum::EMOTION_DEFAULT));
	R_EmotionIcon->setPosition(Point(R_Char->getPosition().x + R_Char->getContentSize().width / 2.8, R_Char->getPosition().y + R_Char->getContentSize().height / 3.3));
	this->addChild(R_EmotionIcon, ZO_EMOTION_ICON, TAG_R_EMOTION_ICON);
}

void AlchemyScene::charChange(Sprite *spr, HomunNum homunNum, FaceNum faceNum){
	Texture2D *tex = TextureCache::sharedTextureCache()->addImage(eventImgData->getFaceImgPath(homunNum, faceNum));
	//	スプライトの画像を変更する
	spr->setTexture(tex);
}

void AlchemyScene::emotionIconChange(Sprite *spr, EmotionNum emotionNum){
	Texture2D *tex = TextureCache::sharedTextureCache()->addImage(eventImgData->getEmotionIconImagePath(emotionNum));
	//	スプライトの画像を変更する
	spr->setTexture(tex);
}

void AlchemyScene::animationManager(Sprite *spr, AnimationListNum animationListNum){
	switch (animationListNum) {
		case ANIMATION_IDLING:
			spr->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1.2, 1.02), ScaleTo::create(1.2, 0.98), NULL)));
			break;
		case ANIMATION_HOMUN_SCALE_BIG:
			spr->runAction(ScaleTo::create(0.5, 1.2));
			break;
		case ANIMATION_HOMUN_SCALE_MIDIUM:
			spr->runAction(ScaleTo::create(0.5, 1));
			break;
		case ANIMATION_HOMUN_SCALE_LITTLE:
			spr->runAction(ScaleTo::create(0.5, 0.8));
			break;
		default: break;
	}
}

void AlchemyScene::talkEvent(int winWidth, int winHeight){
	//	タグでスプライトを取得
	auto L_Char = (Sprite*)this->getChildByTag(TAG_L_TALKING_HOMUN);
	auto R_Char = (Sprite*)this->getChildByTag(TAG_R_TALKING_HOMUN);
	auto L_EmotionIcon = (Sprite*)this->getChildByTag(TAG_L_EMOTION_ICON);
	auto R_EmotionIcon = (Sprite*)this->getChildByTag(TAG_R_EMOTION_ICON);
	
	//	スプライト入れ替え
	charChange(L_Char, HOMUN_O2, FACE_NORMAL);
	charChange(R_Char, HOMUN_H2, FACE_NORMAL);
	emotionIconChange(L_EmotionIcon, EmotionNum::EMOTION_EXCLAMATION);
	emotionIconChange(R_EmotionIcon, EmotionNum::EMOTION_ANGRY);
	
	//	アイドリングアニメーションセット
	animationManager(L_Char, ANIMATION_IDLING);
	animationManager(R_Char, ANIMATION_IDLING);
	animationManager(L_EmotionIcon, ANIMATION_IDLING);
	animationManager(R_EmotionIcon, ANIMATION_IDLING);
}