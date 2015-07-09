#include "AtomClass.h"

USING_NS_CC;

bool Atom::init(AtomNum type, int groupnum) {
	if (!Layer::init()) {
		return false;
	}
	
	//画面のサイズを取得
	static auto view = Director::getInstance()->getOpenGLView();
	static auto size = view->getFrameSize();
	
	
	
	//原子データのインスタンスを取得
	AtomData *atomdata = AtomData::getInstance();
	
	
	//受け取った原子番号をセット
	atomnum = type;
	
	//受け取ったグループ番号をセット
	group = groupnum;
	initialGroup = groupnum;
	
	
	//結合手の数の初期化
	bondCount = atomdata->GetBondCount(type);
	initialBondCount = atomdata->GetBondCount(type);
	
	
	
	
	//原子背景スプライト
	atom = Sprite::create(atomdata->GetImageName(type));
	atom->setTag(100);
	addChild(atom);
	
	
	//原子名ラベル
	auto atomname = atomdata->GetName(type);
	auto atomLabel = Sprite::create(atomname);
	atomLabel->setPosition(atom->getContentSize().width/2,atom->getContentSize().height/2);
	atomLabel->setTag(110);
	atom->addChild(atomLabel);
	
	
	//結合手背景スプライト
	auto bond = Sprite::create(atomdata->GetSafeBondImageName());
	bond->setPosition(atom->getContentSize().width - (size.width / 100),
					  atom->getContentSize().height- (size.height/ 100));
	bond->setTag(120);
	atom->addChild(bond);
	
	
	//結合手の数ラベル
	std::string str = std::to_string(bondCount);
	bondlabel = LabelTTF::create(str, "Arial", int(size.height / 20));
	bondlabel->setPosition(bond->getContentSize().width/2,bond->getContentSize().height/2);
	bondlabel->setTag(130);
	bond->addChild(bondlabel);
	
	
	this->scheduleUpdate();
	
	return true;
}

void Atom::update(float delta)
{
	//結合手ラベルを現在のbondCountに変更する
	std::string str = std::to_string(bondCount);
	bondlabel->setString(str);
	
	
	//結合手が0なら結合手の背景画像を変更
	if(bondCount == 0){
		auto bond = (Sprite*)atom->getChildByTag(120);
		bond->setTexture(AtomData::getInstance()->GetPinchBondImageName());
	}
}


//原子のスプライトサイズをrectで返す
Rect Atom::getRect()
{
	Point point = this->getPosition();
	int w = this->getContentSize().width * this->getScaleX();
	int h = this->getContentSize().height * this->getScaleY();
	return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}

//自身(スプライト)に引数(点)が重なっているかを真偽で返す
bool Atom::isTapped(Point point)
{
	Rect rect = atom->boundingBox();
	bool tapped = rect.containsPoint(point);
	if (tapped) {
		//log("ok");
	}
	return tapped;
}

//生成時のグループ番号を返す
int Atom::getInitialGroup()
{
	return initialGroup;
}

//現在のグループ番号を返す
int Atom::getGroup()
{
	return group;
}

//現在のグループを引数に変更する
void Atom::setGroup(int setgroup)
{
	group = setgroup;
}

//現在のグループを生成時の状態に戻す
void Atom::groupReset()
{
	group = initialGroup;
}

//現在の結合手の数と背景を生成時の状態に戻す
void Atom::bondCountReset()
{
	bondCount = initialBondCount;
	auto bond = (Sprite*)atom->getChildByTag(120);
	bond->setTexture(AtomData::getInstance()->GetSafeBondImageName());
}