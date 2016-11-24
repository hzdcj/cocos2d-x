#include"Bubble.h"
Bubble * Bubble::create(const string &filename)
{
	Bubble *bubble = Bubble::create();
	if (bubble)
	{
		bubble->bubbleInit(filename);
		return bubble;
	}
	CC_SAFE_DELETE(bubble);
	return nullptr;
}
void Bubble::bubbleInit(const string&filename)
{
	bubbleImage = Sprite::create(filename);
	this->addChild(bubbleImage);
}
void Bubble::down()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float second = CCRANDOM_0_1() * 3 + 3;
	auto moveBy = MoveBy::create(second, Vec2(0,-visibleSize.height - 40));
	this->runAction(moveBy);
}
Vec2 Bubble::randomGenerate()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float x = CCRANDOM_0_1() * 2 * visibleSize.width;
	float y = visibleSize.height + 20;
	return Vec2(x, y);
}

