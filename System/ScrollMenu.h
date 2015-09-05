#ifndef __Alchemy_TGS__ScrollMenu__
#define __Alchemy_TGS__ScrollMenu__
/**
 * cocos2d::Menuクラスを継承したスクロール用Menuクラス
 * 完コピなので理解してない部分あり
 */
#include <cocos2d.h>

USING_NS_CC;

class ScrollMenu : public Menu {
public:
    
    // スクロールビューの位置を保持する
    CC_SYNTHESIZE_PASS_BY_REF(Vec2, _scrollViewPosition, ScrollViewPosition);
    // スクロールビューのサイズを保持する
    CC_SYNTHESIZE_PASS_BY_REF(Vec2, _scrollViewContentSize, ScrollViewContentSize);
    
    // オブジェクト作成用function
    static ScrollMenu* createWithArray(const Vector<MenuItem*>& arrayOfItems);
    // オブジェクト作成時実行処理
    bool initWithArray(const Vector<MenuItem*>& arrayOfItems);
    
    // タッチイベントがスクロール中であるフラグをたてる
    void setMenuInMoving();
    
    // オーバーライドするタッチ開始イベント
    bool onTouchBegan(Touch* touch, Event* event) override;
    // オーバーライドするタッチ終了イベント
    void onTouchEnded(Touch* touch, Event* event) override;
    
protected:
    // コンストラクタ
    ScrollMenu();
    
private:
    // 現在スクロール中かを判断するフラグ
    bool _inMoving;
};
#endif /* defined(__Alchemy_TGS__ScrollMenu__) */