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
	
	tapCounter = 0;
	
	initGra(size.width, size.height);
	talkEvent(size.width, size.height);
	
	return true;
}

void AlchemyScene::initGra(int winWidth, int winHeight){
	
	//	背景
	auto backGround = Sprite::create();
	Rect backGroundRect = Rect(0, 0, winWidth, winHeight);
	backGround->setTextureRect(backGroundRect);
	backGround->setColor(Color3B(188, 226, 232));
	backGround->setPosition(Point(winWidth / 2, winHeight / 2));
	addChild(backGround, ZO_BACKGROUND, TAG_BackGround);

	//	セリフ枠
	auto mesWin = Sprite::create();
	mesWin->setTextureRect(Rect(0, 0, winWidth - winWidth/10 , winHeight/2 - winHeight / 10));
	mesWin->setColor(Color3B(236,109,113));
	mesWin->setPosition(Point(winWidth / 2, winHeight / 4 * 3));
	addChild(mesWin, ZO_BALLOON, TAG_BALLOON);
	
	auto mes = Label::createWithSystemFont("クエスト01\n飲水がほしい","Arial", 90);
	mes->setColor(Color3B::WHITE);
	mes->setPosition(mesWin->getPosition());
	addChild(mes, ZO_TALKING_CHAR, TAG_TALKING_CHAR);
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

void AlchemyScene::balloonColorChange(HomunNo homunNo){
	auto spr = (Sprite*)this->getChildByTag(TAG_BALLOON);
	switch (homunNo) {
		case Homun_H2:
			spr->setColor(Color3B(236,109,113));
			break;
		case Homun_O2:
			spr->setColor(Color3B(39,146,195));
			break;
		default:break;
	}
}

void AlchemyScene::talkNowColor(cocos2d::Sprite *spr){
	if (spr->getTag() == TAG_L_TALKING_HOMUN) {
		spr->setColor(Color3B::WHITE);
		auto emo1 = (Sprite*)this->getChildByTag(TAG_L_EMOTION_ICON);
		emo1->setColor(Color3B::WHITE);
		auto spr2 = (Sprite*)this->getChildByTag(TAG_R_TALKING_HOMUN);
		auto emo2 = (Sprite*)this->getChildByTag(TAG_R_EMOTION_ICON);
		emo2->setColor(Color3B(128, 128, 128));
		spr2->setColor(Color3B(128, 128, 128));
	}
	if (spr->getTag() == TAG_R_TALKING_HOMUN) {
		auto emo1 = (Sprite*)this->getChildByTag(TAG_L_EMOTION_ICON);
		auto emo2 = (Sprite*)this->getChildByTag(TAG_R_EMOTION_ICON);

		spr->setColor(Color3B::WHITE);
		emo2->setColor(Color3B::WHITE);
		auto spr2 = (Sprite*)this->getChildByTag(TAG_L_TALKING_HOMUN);
		emo1->setColor(Color3B(128, 128, 128));
		spr2->setColor(Color3B(128, 128, 128));
	}
	
}

void AlchemyScene::talkEvent(int winWidth, int winHeight){
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();

	//	タグでスプライトを取得
	auto L_Char = (Sprite*)this->getChildByTag(TAG_L_TALKING_HOMUN);
	auto R_Char = (Sprite*)this->getChildByTag(TAG_R_TALKING_HOMUN);
	auto L_EmotionIcon = (Sprite*)this->getChildByTag(TAG_L_EMOTION_ICON);
	auto R_EmotionIcon = (Sprite*)this->getChildByTag(TAG_R_EMOTION_ICON);
	auto Balloon = (Sprite*)this->getChildByTag(TAG_BALLOON);
	
	//	スプライト入れ替え
	charChange(L_Char, HOMUN_O2, FACE_NORMAL);
	charChange(R_Char, HOMUN_H2, FACE_NORMAL);
	animationManager(L_Char, ANIMATION_IDLING);

	Sprite* tapAreaSpr = Sprite::create();
	tapAreaSpr->setContentSize(size);
	MenuItemSprite* tapArea = MenuItemSprite::create(tapAreaSpr,tapAreaSpr,[this](Ref*sender){
		auto L_Char = (Sprite*)this->getChildByTag(TAG_L_TALKING_HOMUN);
		auto R_Char = (Sprite*)this->getChildByTag(TAG_R_TALKING_HOMUN);
		auto L_EmotionIcon = (Sprite*)this->getChildByTag(TAG_L_EMOTION_ICON);
		auto R_EmotionIcon = (Sprite*)this->getChildByTag(TAG_R_EMOTION_ICON);
		auto Balloon = (Sprite*)this->getChildByTag(TAG_BALLOON);
		auto mes = (Label*)this->getChildByTag(TAG_TALKING_CHAR);
		log("now talkNo: %d", tapCounter);
			switch (tapCounter) {
			case 0:{
				//	todo:全部関数でまとめる　汚すぎ
				//	テキストから読み込んで、セリフ表示、アニメーションなど出来るように
				//	専用エディタを作る
					// セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
				
					//	感情アイコン張替え
				
					//	アニメーション切り替え
					animationManager(L_Char, ANIMATION_IDLING);
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			}
			case 1:{
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え

					//	感情アイコン張替え
				
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
					break;
			}
			case 2:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HomunNum::HOMUN_O2, FaceNum::FACE_TROUBLE);
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_TROUBLE);
					//	アニメーション切り替え
					L_EmotionIcon->setScale(0);
					L_EmotionIcon->runAction(ScaleTo::create(0.3, 1));
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
				tapCounter++;
				break;
			case 3:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(R_Char, HOMUN_H2, FACE_ANGRY);
					//	感情アイコン張替え
					emotionIconChange(R_EmotionIcon, EMOTION_ANGRY);
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					R_EmotionIcon->setScale(0);
					R_EmotionIcon->runAction(ScaleTo::create(0.3, 1));
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 4:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_HURRY);
					//	アニメーション切り替え
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					R_EmotionIcon->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);

					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 5:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(R_Char, HOMUN_H2, FACE_TROUBLE);
					//	感情アイコン張替え
					emotionIconChange(R_EmotionIcon, EMOTION_TROUBLE);
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 6:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HomunNum::HOMUN_O2, FaceNum::FACE_SMILE);
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_EXCLAMATION);
					//	アニメーション切り替え
					L_EmotionIcon->runAction(JumpBy::create(0.8, Vec2(0,0), 32, 3));
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 7:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(R_Char, HOMUN_H2, FACE_NORMAL);
					//	感情アイコン張替え
					emotionIconChange(R_EmotionIcon, EMOTION_IDEA);
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					R_EmotionIcon->runAction(Sequence::create(DelayTime::create(0.5),JumpBy::create(0.8, Vec2(0,0), 64, 3), NULL));
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 8:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HOMUN_O2, FACE_NORMAL);
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_DEFAULT);
					//	アニメーション切り替え
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 9:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					
					//	感情アイコン張替え
					emotionIconChange(R_EmotionIcon, EMOTION_DEFAULT);
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 10:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HOMUN_O2, FACE_TROUBLE);
					//	感情アイコン張替え
					
					//	アニメーション切り替え
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 11:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());

					//	ホムンの張替え
					
					//	感情アイコン張替え
					
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_H2);
					//	注目キャラ切り替え
					talkNowColor(R_Char);
					//	カウンター追加
					tapCounter++;
						break;
			case 12:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HOMUN_O2, FACE_SMILE);
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_EXCLAMATION);
					//	アニメーション切り替え
					L_EmotionIcon->runAction(JumpBy::create(0.8, Vec2(0,0), 32, 3));
					animationManager(L_Char, ANIMATION_IDLING);
					R_Char->stopAllActions();
					//	セリフ枠の色切り替え
					balloonColorChange(Homun_O2);
					//	注目キャラ切り替え
					talkNowColor(L_Char);
					//	カウンター追加
					tapCounter++;
					break;
			case 13:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					
					//	感情アイコン張替え
					emotionIconChange(L_EmotionIcon, EMOTION_DEFAULT);
					//	アニメーション切り替え
					animationManager(R_Char, ANIMATION_IDLING);
					L_Char->stopAllActions();
					//	セリフ枠の色切り替え
					//	注目キャラ切り替え
					//	カウンター追加
					tapCounter++;
					break;
			case 14:
					//	セリフの張替え
					mes->setString(eventImgData->getTalkLists(tapCounter).c_str());
					//	ホムンの張替え
					charChange(L_Char, HOMUN_O2, FACE_SMILE);
					charChange(R_Char, HOMUN_H2, FACE_SMILE);
					//	感情アイコン張替え
					
					//	アニメーション切り替え
					L_Char->stopAllActions();
					R_Char->stopAllActions();
					L_Char->runAction(JumpBy::create(0.8, Vec2(0,0), 32, 2));
					R_Char->runAction(JumpBy::create(0.8, Vec2(0,0), 32, 2));
					//	セリフ枠の色切り替え
					Balloon->setColor(Color3B(186, 85, 211));
					//	注目キャラ切り替え
					L_Char->setColor(Color3B::WHITE);
					R_Char->setColor(Color3B::WHITE);
					//	カウンター追加
					tapCounter++;
					break;
				case 15:{
					auto nextScene = PuzzleScene::createScene();
					auto pScene = TransitionFade::create(0.5f, nextScene);
					Director::getInstance()->replaceScene(pScene);
					break;
				}
			default:
    break;
		}
	});
	tapArea->setPosition(size/2);
	auto tapMenu = Menu::create(tapArea ,NULL);
	tapMenu->setPosition(Point::ZERO);
	this->addChild(tapMenu);
}