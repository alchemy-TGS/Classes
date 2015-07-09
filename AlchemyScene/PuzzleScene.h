#ifndef __Alchemy_TGS__PuzzleScene__
#define __Alchemy_TGS__PuzzleScene__

#include <stdio.h>
#include "cocos2d.h"
#include "AtomClass.h"
#include "HomunData.h"
#include "ResultScene.h"

USING_NS_CC;

class PuzzleScene :public Layer {
private:
	//------------------変数------------------
	
	//各種定数の設定
	//パーティホムン
	static const int homuns = 3;
	//画面に出す原子
	static const int atoms = 10;
	//画面に書く線
	static const int lines = 20;
	//原子が生成される時間間隔
	static constexpr float atomPopInterval = 1;        //単位秒
	
	//フラグ
	int flag;
	bool colorChangeFrag;
	
	//原子
	Atom *atom[atoms];
	
	//ゲーム中に使用するホムン
	HomunNum partyHomun[homuns];
	int nowSkillTrun[homuns];
	
	//条件表示
	LabelTTF* conditionLabel;
	int condition;
	HomunNum conditionType;
	
	//タイマー
	CCLabelTTF* timerlabel;
	bool timeswitch;
	float nowTime;
	
	//インーバルの経過時間
	float nowPopInterval;
	
	//drawNode、線
	DrawNode *lineNode;
	bool drawlineFlag;
	Vec2 lineStartPosision;
	Vec2 lineGoalPosision;
	
	//線の保持
	DrawNode *saveLineNode[lines];
	Vec2 keepLineStartPos[lines];
	Vec2 keepLineGoalPos[lines];
	
	//タップした原子の保持
	int keepAtomGroup;
	Atom *keepAtom;
	
	
	
	//------------------関数------------------
	
	//重なりチェック関数
	bool popPosCheck(int num, int x, int y);
	//生成する原子選択
	AtomNum popAtomSelect();
	bool bondCountCheck(int group);
	
	//グループ解除関数
	bool groupResetFlag;
	void groupReset();
	
	//グループ化関数
	void setGroup(int set,int sett);
	
	
	//グループ削除処理
	void groupDelete();
	
	//タイマーの背景の色変更処理
	void timeColorChange();
	
	//Cardが押された時の処理
	void CardEffect(int cardnum);
	void Card1PushCallBack(Ref* pSender);
	void Card2PushCallBack(Ref* pSender);
	void Card3PushCallBack(Ref* pSender);
	
	//タッチ処理
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	
	
	
	//ノードの書き直し処理
	void nodeReWrite();
	//原子生成処理
	void atomGenerate(float delta);
	
	//クリア判定
	void clearCheck();
	
	//タイマー処理
	void timerUpdate(float delta);
	
	//カードのスキルが溜まってるかの表示
	void cardChangeColor();
	
public:
	static Scene *createScene();
	bool init();
	void update(float delta);
	
	
	
	CREATE_FUNC(PuzzleScene);
	
};

#endif /* defined(__Alchemy_TGS__PuzzleScene__) */