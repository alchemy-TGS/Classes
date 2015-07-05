#include "PuzzleScene.h"
#include <iostream>
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
	
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	colorChangeFrag = false;
	
	//ヘッダー
	//	白い画像にプログラム側で色をつけます。
	Sprite* header = Sprite::create("AlchemyImg/Header/header_Frame.png");
	header->setColor(Color3B(103, 167, 12));
    //	header->setTextureRect(Rect(0,0,size.width,size.height/6));
    //	header->setColor(Color3B::GRAY);
    
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
	auto QuestView = Sprite::create("AlchemyImg/Header/QuestChar/quest_H2O.png");
	QuestView->setPosition(header->getPosition());
	this->addChild(QuestView);
	
	//Card表示
	/*
     汚くてごめん。
     クエストを選択した後の編成画面で選んだカードが下に並びます。
     カード枠はヘッダーと同じく白い画像にプログラム側で色を付ける。
     ここらへんの作りは任せます。
     並びかた（数値的な）参考にしてもらえれば……
	 */
	Sprite* footer = Sprite::create();
	footer->setTextureRect(Rect(0,0,size.width,size.height/6));
	footer->setColor(Color3B::GRAY);
    
	float footerx = size.width/2;
	float footery = size.height/12;
	footer->setPosition(Point(footerx, footery));
	this->addChild(footer);
	
	Sprite* cardFrame1 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	Sprite* cardFrame2 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	Sprite* cardFrame3 = Sprite::create("AlchemyImg/Card/card_Frame.png");
	
	auto card3Item = MenuItemSprite::create(cardFrame3, cardFrame3,
											CC_CALLBACK_1(PuzzleScene::Card3PushCallBack, this));
	auto card3Menu = Menu::create(card3Item, NULL);
	
	cardFrame1->setColor(Color3B(22, 94, 131));
	cardFrame2->setColor(Color3B(22, 94, 131));
	cardFrame3->setColor(Color3B(228, 94, 50));
	
	int cardPosY = cardFrame1->getContentSize().height / 2;
	cardFrame1->setPosition(size.width / 3 - cardFrame1->getContentSize().width / 2,
							cardPosY);
	cardFrame2->setPosition(size.width / 3 * 2 - cardFrame1->getContentSize().width / 2,
							cardPosY);
	card3Menu->setPosition(size.width / 3 * 3 - cardFrame1->getContentSize().width / 2,
                           cardPosY);
	
	addChild(cardFrame1);
	addChild(cardFrame2);
	addChild(card3Menu);
	
	Sprite* card1 = Sprite::create("AlchemyImg/Card/H2_Card_SD_Alchemy.png");
	Sprite* card2 = Sprite::create("AlchemyImg/Card/C2H5OH_Card_SD_Alchemy.png");
	Sprite* card3 = Sprite::create("AlchemyImg/Card/O2_Card_SD_Alchemy.png");
	
	card1->setPosition(cardFrame1->getPosition());
	card2->setPosition(cardFrame2->getPosition());
	card3->setPosition(card3Menu->getPosition());
	
	addChild(card1);
	addChild(card2);
	addChild(card3);
	
	//　汚いのここまで
	
	//ノードの初期化
	lineNode = DrawNode::create();
	addChild(lineNode);
	drawlineFlag = false;
	for(int i=0;i<lines;i++){
		keepLineStartPos[i] = Vec2(-1,-1);
		keepLineGoalPos[i] = Vec2(-1,-1);
	}
	/*
	 for(int i=0;i<lines;i++){
     saveLineNode[i] = DrawNode::create();
     saveLineNode[i]->clear();
     addChild(saveLineNode[i]);
     saveLineGroup[i] = -1;
	 }
	 */
	
	
	
	//条件の表示
	atomCondition = 5;
	conditionLabel = LabelTTF::create("", "Arial", int(size.height/12));
	conditionLabel->setPosition(Point(header->getContentSize().width / 4 * 3,
									  header->getPosition().y - (header->getContentSize().height / 5)));
	conditionLabel->setColor(Color3B(60, 60, 60));
	this->addChild(conditionLabel);
	
	
	//タイマーの表示
	timerlabel = CCLabelTTF::create("0:00", "Arial", int(size.height/19));
	timerlabel->setPosition(Point(size.width/2,size.height/50*48));
	this->addChild(timerlabel);
	
	//初期タイマーのセット
	timeswitch = true;
	nowTime = 120;			//秒
	frameCount = 0;
	
	
	//イベントリスナーを作成
	auto listener = EventListenerTouchOneByOne::create();
    
	listener->onTouchBegan = CC_CALLBACK_2(PuzzleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PuzzleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PuzzleScene::onTouchEnded, this);
    
	//イベントリスナーを登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
	//atomsの初期化
	for(int i=0;i<atoms;i++){
		atom[i] = NULL;
	}
	
	///////////////////////////////////
	
	lineStartPosision = Vec2(0,0);
	lineGoalPosision = Vec2(0,0);
	
	/*
	 for(int i=0;i<atoms;i++){
     if(atom[i] == NULL){
	 atom[i] = new Atom;
	 atom[i]->init(ATOM_O);
	 atom[i]->atom->setPosition(100,100);
	 addChild(atom[i]);
	 break;
     }
	 }*/
	
	
	///////////////////////////////////
	
	this->scheduleUpdate();
	
	return true;
}

//	α版用に深く考えずに作ったカードを押した時（スキル発動（仮））の（コレは消す予定）
void PuzzleScene::Card3PushCallBack(Ref *pSender){
	log("card3Pushed");
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	auto CutIn = Sprite::create("HomunImg/O2/O2_Card_big.png");
	//CutIn->setPosition(size.width/2, size.height / 2);
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
	
}

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

void PuzzleScene::update(float delta)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//生成
	frameCount++;
	if(frameCount % 60 == 0){
		for(int i=0;i<atoms;i++){
			if(atom[i] == NULL){
				atom[i] = new Atom;
				
				if(i%2 == 0){
					atom[i]->init(ATOM_H, i);
				}
				if(i%2 == 1){
					atom[i]->init(ATOM_O, i);
				}
				
				int posRandX;
				int posRandY;
				do
				{
					posRandX = rand()%((int)size.width - (int)size.width/5);
					posRandY = rand()%((int)size.height*2/3 - (int)size.height/8);
					atom[i]->atom->setPosition(posRandX + size.width/14,
											   posRandY + size.height/6 + size.height/16);
				} while (popPosCheck(i,posRandX,posRandY));
				addChild(atom[i]);
				log("tootta");
				break;
			}
		}
	}
	
	
	//ノードを初期化して書き直す
	lineNode->clear();
	lineNode->drawSegment(lineStartPosision, lineGoalPosision, 30, Color4F(1, 1, 1, 0.5));
	for (int i= 0;i<lines; i++)
	{
		lineNode->drawSegment(keepLineStartPos[i],keepLineGoalPos[i], 30, Color4F(1,1,1,1));
	}
	
	
	
	for(int group_i=0;group_i<atoms;group_i++){
		int arra[] = {
			2,
			0,
			0,
			0,
			0,
			0,
			0,
			1,
		};
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
			atomCondition--;
			for(int i=0;i<atoms;i++){
				if(atom[i] == NULL) continue;
				if(atom[i]->getGroup() == group_i){
					atom[i]->removeFromParentAndCleanup(true);
					atom[i] = NULL;
					
				}
			}
            for(int line_i=0;line_i<lines;line_i++){
                keepLineStartPos[line_i] = Vec2(-1,-1);
                keepLineGoalPos[line_i] = Vec2(-1,-1);
            }
            groupReset();
		}
	}
	
	//条件を達成したらシーン遷移
	if(atomCondition == 0){
		//ここにシーン遷移
		log("Claer!!");
		if (flag == 0) {
			auto nextScene = ResultScene::createScene();
			auto pScene = TransitionSlideInT::create(1.5, nextScene);
			Director::getInstance()->replaceScene(pScene);
			flag++;
		}
	}
	
	String *str = String::createWithFormat("%d",atomCondition);
	conditionLabel->setString(str->getCString());
	
	//Trueならタイマーを減らす
	if(timeswitch){
		nowTime -= delta;
	}
	int timeM = int(nowTime)/60;
	int timeS = int(nowTime)%60;
	
	String *timestr = String::createWithFormat("%d:%d",timeM,timeS);
	timerlabel->setString(timestr->getCString());
	
	// タイマーの色
	if(nowTime < 60){
		colorChangeFrag = true;
		timeColorChange();
	}
}
int changecount = 0;
void PuzzleScene::timeColorChange(){
	if (colorChangeFrag == true && changecount == 0) {
		auto frame = (Sprite*)this->getChildByTag(1001);
		frame->runAction(TintTo::create(30, 204, 47, 58));
		log("colorChange");
		changecount++;
	}
}

bool PuzzleScene::onTouchBegan(Touch *touch, Event *event)
{
	
	
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->isTapped(touchPoint)){
			//タップされたら削除する
			//			atom[i]->atom->removeFromParentAndCleanup(true);
			//			atom[i] = NULL;
			
			log("%d",atom[i]->getGroup());
			drawlineFlag = true;
			keepAtomGroup = atom[i]->getGroup();
			keepAtom = atom[i];
			lineStartPosision = atom[i]->atom->getPosition();
			lineGoalPosision  = atom[i]->atom->getPosition();
			
			//log("%d",i);
		}
		//		log("atomposi:%d,%d",atom[i]->getPositionX(),atom[i]->getPositionY());
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////////
	
	log("touch:%f,%f",touchPoint.x, touchPoint.y);
	
	return true;
}

void PuzzleScene::onTouchMoved(Touch *touch, Event *event)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	if(drawlineFlag){
		lineGoalPosision = touchPoint;
	}
	//log("Touch Moved!");
	
	
}


void PuzzleScene::groupReset()
{
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		atom[i]->groupReset();
		atom[i]->bondCountReset();
	}
}


void PuzzleScene::setGroup(int set, int sett)
{
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->getGroup() == set){
			atom[i]->setGroup(sett);
		}
	}
}


void PuzzleScene::onTouchEnded(Touch *touch, Event *event)
{
	//画面のサイズを取得
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
	
	//touchPoint : タッチされた場所
	Point touchPoint = Vec2(touch->getLocationInView().x, size.height - touch->getLocationInView().y);
	
	
	
	
	
	for(int i=0;i<atoms;i++){
		if(atom[i] == NULL) continue;
		if(atom[i]->isTapped(touchPoint)){
			//	atom[i] = NULL;
			if(drawlineFlag){
				lineGoalPosision  = atom[i]->atom->getPosition();
				
				if(keepAtomGroup == atom[i]->getGroup()){
					groupReset();
					for(int line_i=0;line_i<lines;line_i++){
						keepLineStartPos[line_i] = Vec2(-1,-1);
						keepLineGoalPos[line_i] = Vec2(-1,-1);
					}
				}else{
					if(keepAtom->bondCount > 0 && atom[i]->bondCount > 0){
						setGroup(atom[i]->getGroup(),keepAtomGroup);
						keepAtom->bondCount--;
						atom[i]->bondCount--;
						//atom[i]->setGroup(keepAtomGroup);
						for(int line_i=0;line_i<lines;line_i++){
							if(keepLineStartPos[line_i] == Vec2(-1,-1)){
								keepLineStartPos[line_i] = lineStartPosision;
								keepLineGoalPos[line_i] = lineGoalPosision;
								break;
							}
						}
					}
				}
			}
			
			log("%d",i);
		}
		//		log("atomposi:%d,%d",atom[i]->getPositionX(),atom[i]->getPositionY());
	}
	//lineNodeの頂点を全削除
	lineNode->clear();
	lineStartPosision = Vec2(-1,-1);
	lineGoalPosision = Vec2(-1,-1);
	drawlineFlag = false;
	//log("Touch Ended!");
}