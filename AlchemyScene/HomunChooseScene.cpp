#include "HomunChooseScene.h"
#include <iostream>
using namespace std;
using namespace ui;
USING_NS_CC;

Scene* HomunChooseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HomunChooseScene::create();
	scene->addChild(layer);
	return scene;
}

bool HomunChooseScene::init()
{
	if ( !Layer::init() ){return false;}
	
	auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();

	initGra(size.width, size.height);
    initScrollView();

    
    for(int i = 0;i<homuns;i++){
        partyHomun[i] = HOMUN_NULL;
    }
    
    
    //startButton
    auto *sprite = Sprite::create("SystemImg/title_tap.png");
    auto *sprite2 = Sprite::create("SystemImg/title_tap.png");
    sprite2->setColor(Color3B(180, 180, 180));//押されている状態の色
    auto item = MenuItemSprite::create(sprite, sprite2, [&](Ref* sender){
        for(int i=0;i<homuns;i++){
            if(partyHomun[i] != -1){
                break;
            }
            return;
        }
        auto savedata = CCUserDefault::getInstance();
        savedata->setIntegerForKey("PartyHomun_0", partyHomun[0]);
        savedata->setIntegerForKey("PartyHomun_1", partyHomun[1]);
        savedata->setIntegerForKey("PartyHomun_2", partyHomun[2]);
        savedata->flush();
        
        //SEとか入れたい
        
        auto nextScene = PuzzleScene::createScene();
        auto pScene = TransitionFade::create(0.5f, nextScene);
        Director::getInstance()->replaceScene(pScene);
    });
    auto *menu = Menu::create(item, NULL);
    menu->setPosition(size.width / 2, size.height * 5/9);
    
    this->addChild(menu);
    
    
    //
	
	return true;
}



void HomunChooseScene::initGra(int winWidth, int winHeight){
	
    //	背景
	auto backGround = Sprite::create();
	Rect backGroundRect = Rect(0, 0, winWidth, winHeight);
	backGround->setTextureRect(backGroundRect);
	backGround->setColor(Color3B(188, 226, 232));
	backGround->setPosition(Point(winWidth / 2, winHeight / 2));
	addChild(backGround, ZOrder::ZO_BACKGROUND, Tag::TAG_BACKGROUND);
}


void HomunChooseScene::initScrollView(){
    
    auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
    
    log("%f",size.height);
    
    //アイテムサイズを記録しておく
    Vec2 itemsize;
    
    
    // 通常のメニュー作成時と同様にMenuItemのVectorを作成
    Vector<MenuItem*> menuItems;
    
    //ここで要素を並べる
    for(int i = 0;i<HOMUN_LAST_NUM;i++){
        Sprite *sprite = Sprite::create(HomunData::getImageName(i));
        Sprite *sprite2 = Sprite::create(HomunData::getImageName(i));
        sprite2->setColor(Color3B(180, 180, 180));//押されている状態の色
        auto button = MenuItemSprite::create(sprite, sprite2, [&,i](Ref* sender){
            
            //ここにアイテムが押された時の処理
            for(int j=0;j<homuns;j++){
                if(partyHomun[j] == -1){
                    HomunChooseScene::addHomunButton(j,i);
                    partyHomun[j] = i;
                    break;
                }
            }
            
            //SEとか入れたい
        });
        
        button->setTag(i);
        
        //button->setScale(0.7);
        
        
        //アイテム同士の間隔の調整
        float xInterval = button->getContentSize().width;
        float yInterval = button->getContentSize().height * -1;
        button->setPosition(Vec2(xInterval * (-1 + i%3),
                                 yInterval * int(i/3)));
        
        //ボタンをvectorに追加
        menuItems.pushBack(button);
        
        //buttonのsizeを記憶
        itemsize = button->getContentSize();
    }
    
    
    // ScrollMenuを作成
    auto menu = ScrollMenu::createWithArray(menuItems);
    menu->setContentSize(Size(0, itemsize.y * ((HOMUN_LAST_NUM+2)/3)));
    log("%f",menu->getContentSize().height);
 //   menu->setAnchorPoint(Vec2(0, 0));
    menu->setPosition(Vec2(size.width/2, itemsize.y * ((HOMUN_LAST_NUM+2)/3) - itemsize.y * 2 / 5));
    
    // 作成したメニューをセットしたScrollMenuViewを作成
    auto scrollMenuView = ScrollMenuView::create(menu);
    //scrollMenuView->setBounceEnabled(true);                             //バウンドの設定
    scrollMenuView->setDirection(ui::ScrollView::Direction::VERTICAL);  //スクロールの方向の設定　※VERTICAL＝縦方向
    scrollMenuView->setContentSize(Size(size.width, size.height/2));                    //表示領域のセット
    scrollMenuView->setPosition(Vec2(0, 0));                           //左下がanchorPointになってるっぽい？
    
    this->addChild(scrollMenuView);
}


void HomunChooseScene::addHomunButton(int i , int num){
    
    auto view = Director::getInstance()->getOpenGLView();
	auto size = view->getFrameSize();
    
    int buttonTag = 1000 + i;
    
    //HomunButton
    auto sprite = Sprite::create(HomunData::getImageName(num));
    auto sprite2 = Sprite::create(HomunData::getImageName(num));
    sprite2->setColor(Color3B(180, 180, 180));//押されている状態の色
    auto button = MenuItemSprite::create(sprite, sprite2, [&,buttonTag,i](Ref* sender){
        this->removeChildByTag(buttonTag);
        partyHomun[i] = HOMUN_NULL;
        
        //SEとか入れたい
    });
    auto menu = Menu::create(button, NULL);
    menu->setPosition(size.width / 2 + button->getContentSize().width * (-1 + i%3) , size.height * 7/9);
    menu->setTag(buttonTag);
    this->addChild(menu);
}

