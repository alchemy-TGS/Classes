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
	//場に出す上限
	static const int atoms = 10;
	Atom *atom[atoms];
	
    
	//ゲーム中にしようするホムン　最大３
    HomunNum partyHomun[3];
    int nowSkillTrun[3];
	
	
	//条件表示関連
	LabelTTF* conditionLabel;
	int condition;
    HomunNum conditionType;
	
	//タイマー関連
	CCLabelTTF* timerlabel;
	bool timeswitch;
	float nowTime;
	
	int frameCount;
	
	
	//drawNode  線
	DrawNode *lineNode;
	bool drawlineFlag;
	Vec2 lineStartPosision;
	Vec2 lineGoalPosision;
	
	static const int lines = 20;
	DrawNode *saveLineNode[lines];
	Vec2 keepLineStartPos[lines];
	Vec2 keepLineGoalPos[lines];
	
	
	
	//atomgroup
	int keepAtomGroup;
	Atom *keepAtom;
	
    
    //重なりチェック関数
	bool popPosCheck(int num, int x, int y);
    //生成する原子選択
    AtomNum popAtomSelect();
    
    //グループ解除関数
    bool groupResetFlag;
	void groupReset();
    
    //グループ化関数
	void setGroup(int set,int sett);
	
	
	
	//タッチ
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	
public:
	static Scene *createScene();
	bool init();
	void update(float delta);
	
	//	Cardが押された時
    void CardEffect(int cardnum);
	void Card1PushCallBack(Ref *pSender);
    void Card2PushCallBack(Ref* pSender);
    void Card3PushCallBack(Ref *pSender);
	//	制限時間に合わせてヘッダーの色を変える
	void timeColorChange();
	bool colorChangeFrag;
	int flag;
		
	CREATE_FUNC(PuzzleScene);
	
};

#endif /* defined(__Alchemy_TGS__PuzzleScene__) */
