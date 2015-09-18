#include "PuzzleScene.h"
#include <iostream>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace std;
USING_NS_CC;



Scene *PuzzleScene::createScene() {
	auto scene = Scene::create();
	auto layer = PuzzleScene::create();
	scene->addChild(layer);
	return scene;
};



bool PuzzleScene::init() {
	if (!Layer::init()) {
		return false;
	}
	
	static auto Bgm = SimpleAudioEngine::getInstance();
	
	Bgm->playBackgroundMusic("Sound/alchemy_Puzzle.mp3",true);
	
	
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
    
    
    //保存してあるデータの取得
    auto savedata = CCUserDefault::getInstance();
	
	
	//各種ステータスの初期化
	colorChangeFrag = false;
	groupResetFlag = false;
	nowPopInterval = atomPopInterval;
	for(int i=0;i<atoms;i++){
		atom[i] = NULL;
	}
	
	//	背景
	auto backGround = Sprite::create();
	Rect backGroundRect = Rect(0, 0, size.width, size.height);
	backGround->setTextureRect(backGroundRect);
	backGround->setColor(Color3B(178, 216, 222));
	backGround->setPosition(Point(size.width / 2, size.height / 2));
	addChild(backGround, 0);
	
	//ヘッダー
	//	白い画像にプログラム側で色をつけます。
	Sprite* header = Sprite::create("AlchemyImg/Header/header_Frame.png");
	header->setColor(Color3B(103, 167, 12));
	
	float headerx = size.width/2;
	float headery = size.height - header->getContentSize().height / 2;
	header->setPosition(Point(headerx, headery));
	header->setTag(1001);
	this->addChild(header);
	
	//	ヘッダー目標表示
	auto headerTarget = Sprite::create("AlchemyImg/Header/header_White.png");
	headerTarget->setPosition(header->getPosition());
	this->addChild(headerTarget);
	
	//	今回のクエスト
	auto QuestView = Sprite::create(QuestList::getconditionImageName(savedata->getIntegerForKey("QuestConditionKey", 0)));
	QuestView->setPosition(header->getPosition());
	this->addChild(QuestView);
	
	
	
	//フッター
	Sprite* footer = Sprite::create();
	footer->setTextureRect(Rect(0,0,size.width,size.height/6));
	footer->setColor(Color3B::GRAY);
	float footerx = size.width/2;
	float footery = size.height/12;
	footer->setPosition(Point(footerx, footery));
	this->addChild(footer);
	
	
	
	//todo カードの生成を配列とforで簡略化したい
	
	//Card表示
	//カード枠はヘッダーと同じく白い画像にプログラム側で色を付ける。
	Sprite* cardFrame1 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	Sprite* cardFrame2 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	Sprite* cardFrame3 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	
	cardFrame1->setTag(1100);
	cardFrame2->setTag(1101);
	cardFrame3->setTag(1102);
	
	cardFrame1->setColor(Color3B(22, 94, 131));
	cardFrame2->setColor(Color3B(22, 94, 131));
	cardFrame3->setColor(Color3B(22, 94, 131));
	
	int cardPosY = cardFrame1->getContentSize().height / 2;
	cardFrame1->setPosition(size.width / 3 - cardFrame1->getContentSize().width / 2,cardPosY);
	cardFrame2->setPosition(size.width / 3 * 2 - cardFrame1->getContentSize().width / 2,cardPosY);
	cardFrame3->setPosition(size.width / 3 * 3 - cardFrame1->getContentSize().width / 2,cardPosY);
	
	addChild(cardFrame1);
	addChild(cardFrame2);
	addChild(cardFrame3);
	
	
	//パーティホムンの初期化　　userDefault（？）で、もってくればいいか？
        
	partyHomun[0] = savedata->getIntegerForKey("PartyHomun_0");
	partyHomun[1] = savedata->getIntegerForKey("PartyHomun_1");
	partyHomun[2] = savedata->getIntegerForKey("PartyHomun_2");
	
	nowSkillTrun[0] = HomunData::getSkillTrun(partyHomun[0]);
	nowSkillTrun[1] = HomunData::getSkillTrun(partyHomun[1]);
	nowSkillTrun[2] = HomunData::getSkillTrun(partyHomun[2]);
	
	Sprite* card1 = Sprite::create(HomunData::getImageName(partyHomun[0]));
	Sprite* card2 = Sprite::create(HomunData::getImageName(partyHomun[1]));
	Sprite* card3 = Sprite::create(HomunData::getImageName(partyHomun[2]));
	
	auto card1Item = MenuItemSprite::create(card1, card1,CC_CALLBACK_1(PuzzleScene::Card1PushCallBack, this));
	auto card1Menu = Menu::create(card1Item, NULL);
	
	auto card2Item = MenuItemSprite::create(card2, card2,CC_CALLBACK_1(PuzzleScene::Card2PushCallBack, this));
	auto card2Menu = Menu::create(card2Item, NULL);
	
	auto card3Item = MenuItemSprite::create(card3, card3,CC_CALLBACK_1(PuzzleScene::Card3PushCallBack, this));
	auto card3Menu = Menu::create(card3Item, NULL);
	
	card1Menu->setPosition(cardFrame1->getPosition());
	card2Menu->setPosition(cardFrame2->getPosition());
	card3Menu->setPosition(cardFrame3->getPosition());
	
	addChild(card1Menu);
	addChild(card2Menu);
	addChild(card3Menu);
	
	
	//ノードの初期化
	lineNode = DrawNode::create();
	addChild(lineNode);
	drawlineFlag = false;
	for(int i=0;i<lines;i++){
		keepLineStartPos[i] = Vec2(-1,-1);
		keepLineGoalPos[i] = Vec2(-1,-1);
	}
	lineStartPosision = Vec2(0,0);
	lineGoalPosision = Vec2(0,0);
	
	
	//条件の表示
	condition = QuestList::getcondition(savedata->getIntegerForKey("QuestConditionKey"));
	conditionType = QuestList::getconditionType(savedata->getIntegerForKey("QuestConditionKey"));
	CCLOG("condi:%d",conditionType);
	conditionLabel = LabelTTF::create("", "fonts/mplus-2p-heavy.ttf", int(size.height/12));
	conditionLabel->setPosition(Point(header->getContentSize().width / 4 * 3,
									  header->getPosition().y - (header->getContentSize().height / 5)));
	conditionLabel->setColor(Color3B(60, 60, 60));
	this->addChild(conditionLabel);
	
	
	//タイマーの表示
	timerlabel = CCLabelTTF::create("∞", "fonts/mplus-2p-heavy.ttf", int(size.height/19));
	timerlabel->setPosition(Point(size.width/2,size.height/50*48));
	this->addChild(timerlabel);
	
	
	//初期タイマーのセット
	timeswitch = true;
	nowTime = 120;			//秒
    
    for(int i=0;i<homuns;i++){
        nowSkillEffectTime[i] = 0;
    }
	
	
	
	//画面タップ時のイベントリスナーを作成、登録
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PuzzleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PuzzleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PuzzleScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
    
	//	セーブデータから次のクリア時のシーンを判定
	sceneChangeCount = savedata->getIntegerForKey("ClearSceneKey");
	
	
	/////////
	
	this->scheduleUpdate();
	
	return true;
}



void PuzzleScene::update(float delta)
{
	
	
	//生成
	atomGenerate(delta);
	
	//分子の削除処理
	groupDelete();
	
	//ノードを初期化して書き直す
	nodeReWrite();
	
	//条件を達成したらシーン遷移
	clearCheck();
	
	//クリア条件文字列の更新
	String *str = String::createWithFormat("%d",condition);
	conditionLabel->setString(str->getCString());
	
	//タイマー処理
	timerUpdate(delta);
	
	//スキルが溜まったら色変更
	cardChangeColor();
}



bool PuzzleScene::onTouchBegan(Touch *touch, Event *event)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	
	
	//
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->isTapped(touchPoint)){
			if(atom[i]->bondCount > 0){
				drawlineFlag = true;
				keepAtomGroup = atom[i]->getGroup();
				keepAtom = atom[i];
				lineStartPosision = atom[i]->atom->getPosition();
				lineGoalPosision  = atom[i]->atom->getPosition();
				auto sound = SimpleAudioEngine::getInstance();
				sound->playEffect("Sound/selected.mp3");
			}
			else
			{
				groupResetFlag = true;
			}
		}
	}
	
	
	//	log("touch:%f,%f",touchPoint.x, touchPoint.y);
	
	return true;
}



void PuzzleScene::onTouchMoved(Touch *touch, Event *event)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	
	
	//線の終点に現在のタップ位置をセットします
	if(drawlineFlag){
		lineGoalPosision = touchPoint;
	}
}



void PuzzleScene::onTouchEnded(Touch *touch, Event *event)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	
	//原子があるところで指を離したときの処理
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->isTapped(touchPoint)){
			if(drawlineFlag){
				lineGoalPosision  = atom[i]->atom->getPosition();
                
				if(keepAtom->bondCount > 0 &&
                   atom[i]->bondCount > 0 &&
                   atom[i]->getInitialGroup() != keepAtom->getInitialGroup()){
                    
					setGroup(atom[i]->getGroup(),keepAtomGroup);
					keepAtom->bondCount--;
					atom[i]->bondCount--;
					for(int line_i=0;line_i<lines;line_i++){
						if(keepLineStartPos[line_i] == Vec2(-1,-1)){
							keepLineStartPos[line_i] = lineStartPosision;
							keepLineGoalPos[line_i] = lineGoalPosision;
							break;
						}
					}
				}
			}
			
			if(groupResetFlag) {
				groupReset();
			}
		}
	}
	
	
	groupResetFlag = false;
	
	//lineNodeの頂点を全削除
	lineNode->clear();
	lineStartPosision = Vec2(-1,-1);
	lineGoalPosision = Vec2(-1,-1);
	drawlineFlag = false;
	//log("Touch Ended!");
}


void PuzzleScene::Card1PushCallBack(Ref *pSender){
	CardEffect(0);
}

void PuzzleScene::Card2PushCallBack(Ref *pSender){
	CardEffect(1);
}

void PuzzleScene::Card3PushCallBack(Ref *pSender){
	CardEffect(2);
}



//タイマー処理
void PuzzleScene::timerUpdate(float delta){
	if(timeswitch){
		nowTime -= delta;
        for(int i=0;i<homuns;i++){
            nowSkillEffectTime[i] -= delta;
        }
	}
	int timeM = int(nowTime)/60;
	int timeS = int(nowTime)%60;
	
//	String *timestr = String::createWithFormat("%2.2d:%2.2d",timeM,timeS);
//	timerlabel->setString(timestr->getCString());
	
	// タイマーの色
	if(nowTime < 60){
		timeColorChange();
	}
}

//タイマーの背景の変更
void PuzzleScene::timeColorChange(){
	if (colorChangeFrag == false) {
		auto frame = (Sprite*)this->getChildByTag(1001);
		frame->runAction(TintTo::create(30, 204, 47, 58));
		colorChangeFrag = true;
		//log("colorChange");
	}
}

//スキルが溜まってたらカード背景の色を変更
void PuzzleScene::cardChangeColor(){
	for(int i=0;i<homuns;i++){
		if(partyHomun[i] != HOMUN_NULL){
			if(nowSkillTrun[i] <= 0){
				auto cardFrame = (Sprite*)this->getChildByTag(1100 + i);
				cardFrame->setColor(Color3B(228, 94, 50));
			}
		}
	}
}

//ノードの書き直し
void PuzzleScene::nodeReWrite(){
	lineNode->clear();
	lineNode->drawSegment(lineStartPosision, lineGoalPosision, 30, Color4F(1, 1, 1, 0.5));
	for (int i= 0;i<lines; i++)
	{
		lineNode->drawSegment(keepLineStartPos[i],keepLineGoalPos[i], 30, Color4F(1,1,1,1));
	}
}

//クリア判定
void PuzzleScene::clearCheck(){
	if(condition == 0){
		//ここにシーン遷移
		log("Claer!!");
		if (flag == 0) {
			switch(sceneChangeCount){
				case 0:{
					auto nextScene = TownScene2::createScene();
					auto pScene = TransitionCrossFade::create(1.5, nextScene);
					Director::getInstance()->replaceScene(pScene);
					break;
				}
				case 1:{
					auto nextScene = HardScene::createScene();
					auto pScene = TransitionCrossFade::create(1.5, nextScene);
					Director::getInstance()->replaceScene(pScene);
					break;
				}
			}
					
			flag++;
		}
	}
}


//ゲームオーバー判定
void PuzzleScene::gameOverCheck(){
    if(nowTime < 0){
        log("GameOver");
		auto nextScene = HardScene::createScene();
		auto pScene = TransitionCrossFade::create(1.5, nextScene);
		Director::getInstance()->replaceScene(pScene);
    }
}

//原子生成処理
void PuzzleScene::atomGenerate(float delta){
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	nowPopInterval -= delta;
	if(nowPopInterval < 0){
		for(int i=0;i<atoms;i++){
			
			if(atom[i] != NULL) continue;
			
			atom[i] = new Atom;
			atom[i]->init(popAtomSelect(), i);
			int posRandX;
			int posRandY;
			
			//ポップできる位置が乱数で取得できるまで繰り返す
			do
			{
				posRandX = rand()%((int)size.width - (int)size.width/5);
				posRandY = rand()%((int)size.height*2/3 - (int)size.height/8);
				atom[i]->atom->setPosition(posRandX + size.width/14, posRandY + size.height/6 + size.height/16);
			} while (popPosCheck(i,posRandX,posRandY));
			
			addChild(atom[i]);
			
			//	ポップのアニメーションようにスケールを0に
			atom[i]->atom->setScale(0);
			//	ポップと、アイドリングアニメーション
			atom[i]->atom->runAction(
				RepeatForever::create(
					Sequence::create(
						EaseIn::create(ScaleTo::create(1.2, 1.05),2),
						EaseIn::create(ScaleTo::create(1.2, 0.95),2), NULL)));
			
			nowPopInterval = atomPopInterval;
			break;
			
		}
	}
}




//グループの削除判定確認から削除まで         ※とても汚い...
void PuzzleScene::groupDelete(){
	auto pPattern = AtomData::GetDestroyPattern();
	auto pPatternNum = AtomData::GetDestroyPatternNum();
	for(int group_i=0;group_i<atoms;group_i++){
		for(int arra_i = 0;arra_i<pPatternNum;arra_i++){
			int arra[] = {
				*(pPattern + arra_i * 8),
				*(pPattern + arra_i * 8 + 1),
				*(pPattern + arra_i * 8 + 2),
				*(pPattern + arra_i * 8 + 3),
				*(pPattern + arra_i * 8 + 4),
				*(pPattern + arra_i * 8 + 5),
				*(pPattern + arra_i * 8 + 6),
				*(pPattern + arra_i * 8 + 7),
			};
			
            /*
			for(int i=0;i<8;i++){
				log("%d",*(pPattern + arra_i * 8+i));
			}*/
			int arraCount = 0;
			
			for(int i=0;i<atoms;i++){
				if(atom[i] == NULL) continue;
				if(atom[i]->getGroup() == group_i){
					arra[atom[i]->atomnum]--;
				}
			}
			for(int i=0;i<8;i++){
				if(arra[i] == 0){
					arraCount++;
				}
			}
			if(arraCount == 8){
				if(bondCountCheck(group_i)){
					if(arra_i == conditionType){
						condition--;
					}
					for(int i=0;i<homuns;i++){
						nowSkillTrun[i]--;
					}
					
					for(int i=0;i<atoms;i++){
						if(atom[i] == NULL) continue;
						if(atom[i]->getGroup() == group_i){
							
                            //削除アニメーション
							auto anime1 = EaseIn::create(ScaleBy::create(0.3, 1.3),2);
                            auto anime2 = EaseIn::create(ScaleBy::create(0.2, 0),2);
							
                            cocos2d::CallFunc *compCallFunc = CallFunc::create([=](){
                                // アニメーション終了後にやりたいこと
                                atom[i]->removeFromParentAndCleanup(true);
                                atom[i] = NULL;
                            });
                            
                            auto sequence = Sequence::create(anime1, anime2, compCallFunc, NULL);
                            
                            atom[i]->atom->runAction(sequence);
                            
                            
                            
                            
														
						}
					}
					auto sound = SimpleAudioEngine::getInstance();
					sound->playEffect("Sound/alchemyOK.mp3");
					groupReset();
				}
			}
            
		}
        
        if(bondCountCheck(group_i)){
            log("HUANTEI");
            //結合不安定時の処理
			auto sound = SimpleAudioEngine::getInstance();
			sound->playEffect("Sound/alchemyCancel.mp3");
            //ここに結合が不安定時のエフェクトがあれば入れて下さい
            groupReset();
        }
	}
}




//ポップ位置に既に原子があるかの真偽を返します
bool PuzzleScene::popPosCheck(int num, int x, int y){
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(i==num) continue;
		
		Rect rect = atom[i]->atom->boundingBox();
		if(rect.intersectsRect(atom[num]->atom->boundingBox())){
			return true;
		}
	}
	
	return false;
}

//ポップさせる原子を返します
AtomNum PuzzleScene::popAtomSelect(){
    for (int i=0; i<homuns; i++) {
        
        log("%f",nowSkillEffectTime[0]);
        log("%f",nowSkillEffectTime[1]);
        log("%f",nowSkillEffectTime[2]);
        if(nowSkillEffectTime[i] > 0){
            
            int count = arc4random()%100 + 1;
            int* droprate = HomunData::getSkillDropRate();
            for(int droprate_i = 0;*(droprate + droprate_i) != -1;droprate_i++){
                    if(partyHomun[i] != HOMUN_NULL){
                        
                    count -= *(droprate + partyHomun[i]*5 + droprate_i );
                    if(count < 0){
                        if(droprate_i == 0){
                            return ATOM_H;
                        }
                        if(droprate_i == 1){
                            return ATOM_O;
                        }
                        if(droprate_i == 2){
                            return ATOM_C;
                        }
                        if(droprate_i == 3){
                            return ATOM_N;
                        }
                    }
                }
            }
        }
    }
    
	int randRange = 0;
	for(int f=0;f<homuns;f++){
		if(partyHomun[f] != HOMUN_NULL){
			randRange += 100;
		}
	}
	int count = (arc4random()%randRange) +1;
	int* droprate = HomunData::GetDropRate();
	for(int droprate_i = 0;*(droprate + droprate_i) != -1;droprate_i++){
		for(int party_i =0;party_i<homuns;party_i++){
			if(partyHomun[party_i] != HOMUN_NULL){
                //log("%d,%d",*(droprate + (partyHomun[party_i]*5) + droprate_i),count);
				
                count -= *(droprate + partyHomun[party_i]*5 + droprate_i );
				if(count < 0){
					if(droprate_i == 0){
						return ATOM_H;
					}
					if(droprate_i == 1){
						return ATOM_O;
					}
					if(droprate_i == 2){
						return ATOM_C;
					}
					if(droprate_i == 3){
						return ATOM_N;
					}
				}
			}
		}
	}
	log("DropGenerateError");
	return ATOM_H;
}

//引数のグループの原子の結合手が全て0になっているかの真偽を返します
bool PuzzleScene::bondCountCheck(int group){
    
    bool checkPointFlag = false;
    
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->getGroup() == group){
            checkPointFlag = true;
			if(atom[i]->bondCount > 0){
				return false;
			}
		}
	}
    if(checkPointFlag){
        return true;
    }else{
        return false;
    }
	
}



//スキルの効果を処理します
void PuzzleScene::CardEffect(int cardnum){
	if(partyHomun[cardnum] == HOMUN_NULL){
		return;
	}
	if(nowSkillTrun[cardnum] > 0){
		return;
	}
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//アニメーション画像の用意
	auto CutIn = Sprite::create(HomunData::getSkillImageName(partyHomun[cardnum]));
	
	CutIn->setPosition(size.width/2, size.height + CutIn->getContentSize().height);
	CutIn->setZOrder(1000);
	addChild(CutIn);
	
	//	アニメーション
	auto act1 = MoveTo::create(1, Point(size.width/2, size.height/2));
	auto delay1 = DelayTime::create(0.5);
	auto act2 = MoveTo::create(1, Point(size.width / 2, -(CutIn->getContentSize().height / 2)));
	
	auto easeAct1 = EaseOut::create(act1,3);
	auto easeAct2 = EaseIn::create(act2,5);
	
	auto remove = RemoveSelf::create(true);
	auto sequence = Sequence::create(easeAct1, delay1, easeAct2, remove, NULL);
	
	CutIn->runAction(sequence);
	auto sound = SimpleAudioEngine::getInstance();
	sound->playEffect("Sound/skil.mp3");
	

	//スキル使用後の画像リセット
	nowSkillTrun[cardnum] = HomunData::getSkillTrun(partyHomun[cardnum]);
	auto cardFrame = (Sprite*)this->getChildByTag(1100 + cardnum);
	cardFrame->setColor(Color3B(22, 94, 131));
	
    //スキル効果
	nowTime += HomunData::getSkillTimeExtension(partyHomun[cardnum]);
    nowSkillEffectTime[cardnum] = HomunData::getSkillEffectTime(partyHomun[cardnum]);
}


//全ての原子のグループを解除する
void PuzzleScene::groupReset()
{
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		atom[i]->groupReset();
		atom[i]->bondCountReset();
	}
	
	for(int line_i=0;line_i<lines;line_i++){
		keepLineStartPos[line_i] = Vec2(-1,-1);
		keepLineGoalPos[line_i] = Vec2(-1,-1);
	}
}

//第一引数のグループに第二引数のグループをセットします
void PuzzleScene::setGroup(int set, int get)
{
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->getGroup() == set){
			atom[i]->setGroup(get);
		}
	}
}