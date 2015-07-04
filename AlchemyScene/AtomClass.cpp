#include "AtomClass.h"

USING_NS_CC;

bool Atom::init(AtomNum type, int groupnum) {
	if (!Layer::init()) {
		return false;
	}
	
	//画面のサイズを取得
	static auto view = Director::getInstance()->getOpenGLView();
	static auto size = view->getFrameSize();
	static auto changeScale = size.height / 1024;
		
	atomnum = type;
	
	//原子データを参照
	AtomData *atomdata = AtomData::getInstance();
	atom = Sprite::create(atomdata->GetImageName(type));
	auto atomname = atomdata->GetName(type);
	auto bond = Sprite::create(atomdata->GetSafeBondImageName());
	bondCount = atomdata->GetBondCount(type);
	initialBondCount = atomdata->GetBondCount(type);
	
	group = groupnum;
	initialGroup = groupnum;
	
	//原子背景スプライト
	//	atom->setPosition(200,200);
//	atom->setScale(1);
	atom->setTag(100);
	addChild(atom);
	
	//原子名ラベル
	auto atomLabel = Sprite::create(atomname);
	atomLabel->setPosition(atom->getContentSize().width/2,atom->getContentSize().height/2);
	atomLabel->setTag(110);
	atom->addChild(atomLabel);
	/*
	auto atomlabel = LabelTTF::create(atomname, "Arial", int(size.height/10) * changeScale);
	atomlabel->setPosition(atom->getContentSize().width/2,atom->getContentSize().height/2);
	atomlabel->setTag(110);
	atom->addChild(atomlabel);
	*/
	
	//結合手背景スプライト
	bond->setPosition(atom->getContentSize().width - (size.width / 100),
					  atom->getContentSize().height- (size.height/ 100));
//	bond->setScale(0.5f);
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
	/*
	 std::string str = std::to_string(bondCount);
	 bondlabel->setString(str);
	 
	 Sprite* sprite = Sprite::create();
	 sprite->setTextureRect(atom->getBoundingBox());
	 sprite->setColor(Color3B::WHITE);
	 
	 float x = atom->getPositionX();
	 float y = atom->getPositionY();
	 sprite->setPosition(Point(x, y));
	 this->addChild(sprite);
	 */
}


Rect Atom::getRect()
{
	Point point = this->getPosition();
	int w = this->getContentSize().width * this->getScaleX();
	int h = this->getContentSize().height * this->getScaleY();
	return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}

bool Atom::isTapped(Point point)
{
	Rect rect = atom->boundingBox();
	bool tapped = rect.containsPoint(point);
	if (tapped) {
		
		log("ok");
		//
		//	this->removeChild(atom[i]);
	} else {
		
	}
	return tapped;
}

int Atom::getGroup()
{
	return group;
}

void Atom::setGroup(int setgroup)
{
	group = setgroup;
}

void Atom::groupReset()
{
	group = initialGroup;
}

void Atom::bondCountReset()
{
	bondCount = initialBondCount;
}