#include"OpenLayer.h"
USING_NS_CC;
bool OpenLayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	auto label_1 = Label::createWithTTF(SceneManger::WStrToUTF8(L"新的游戏"), "fj3.ttf", 50);
	label_1->enableOutline(Color4B::BLUE, 3);
	MenuItemLabel *menuItem = MenuItemLabel::create(label_1, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width / 2, winSize.height*0.65));

	auto label_2 = Label::createWithTTF(SceneManger::WStrToUTF8(L"退出"), "fj3.ttf", 50);
	label_2->enableOutline(Color4B::BLUE, 3);
	MenuItemLabel *menuItem_2 = MenuItemLabel::create(label_2, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_2->setTag(102);
	menuItem_2->setPosition(Vec2(winSize.width / 2, winSize.height*0.2));
	
	auto label_3 = Label::createWithTTF(SceneManger::WStrToUTF8(L"声音"), "fj3.ttf", 50);
	label_3->enableOutline(Color4B::BLUE, 3);
	MenuItemLabel *menuItem_3 = MenuItemLabel::create(label_3, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_3->setTag(103);
	menuItem_3->setPosition(Vec2(winSize.width / 2, winSize.height*0.5));

	auto label_4 = Label::createWithTTF(SceneManger::WStrToUTF8(L"说明"), "fj3.ttf", 50);
	label_4->enableOutline(Color4B::BLUE, 3);
	MenuItemLabel *menuItem_4 = MenuItemLabel::create(label_4, CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_4->setTag(104);
	menuItem_4->setPosition(Vec2(winSize.width / 2, winSize.height*0.35));

	menu = Menu::create(menuItem, menuItem_2, menuItem_3, menuItem_4, NULL);
	menu->setPosition(Point::ZERO);
	menu->setTag(10);
	this->addChild(menu,1);

	auto _background = Sprite::create("bg01.png");
	_background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	_background->setScale(1.1);
	this->addChild(_background);
    
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm_scene1.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm_scene2.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("bubble.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("bubble2.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("shark_eat2.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("shark_rush.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm_scene1.mp3", true);
	SimpleAudioEngine::getInstance()->preloadEffect("shoot.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_levelup.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("sfx_slot_stop.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("sound_button.mp3");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish2.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish3.plist");

	auto fishSprite = Sprite::createWithSpriteFrameName("fish011_01.png");
	this->addChild(fishSprite);
	fishSprite->setPosition(winSize.width - 10, winSize.height / 6);
	auto animation = Animation::create();
	for (int i = 1; i <= 10; i++)
	{
		if (i == 10)
		{
			animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("fish011_10.png")));
		}
		else
		{
			animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("fish011_0%d.png", i)));
		}
	}
	animation->setDelayPerUnit(3.0f / 30.0f);
	AnimationCache::getInstance()->addAnimation(animation, "move011");
	auto move = AnimationCache::getInstance()->getAnimation("move011");
	auto animate = Animate::create(move);
	auto repeatAnimate = RepeatForever::create(animate);
	auto moveBy = MoveBy::create(10, Vec2(-winSize.width - 10,0));
	auto moveByReverse = moveBy->reverse();
	ActionInstant *flipx = FlipX::create(true);
	fishSprite->runAction(repeatAnimate);
	fishSprite->runAction(RepeatForever::create(Sequence::create(moveBy,flipx,moveByReverse,flipx->reverse(),NULL)));

	auto fishSprite_2 = Sprite::createWithSpriteFrameName("fish08_01.png");
	this->addChild(fishSprite_2);
	fishSprite_2->setFlipX(true);
	fishSprite_2->setPosition( 0, 3*winSize.height / 4);
	auto animation_2 = Animation::create();
	for (int i = 1; i <= 16; i++)
	{
		if (i >= 10)
		{
			animation_2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("fish08_%d.png",i)));
		}
		else
		{
			animation_2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("fish08_0%d.png", i)));
		}
	}
	animation_2->setDelayPerUnit(3.0f / 30.0f);
	AnimationCache::getInstance()->addAnimation(animation_2, "move08");
	auto move_2 = AnimationCache::getInstance()->getAnimation("move08");
	auto animate_2 = Animate::create(move_2);
	auto repeatAnimate_2 = RepeatForever::create(animate_2);
	auto moveBy_2 = MoveBy::create(15, Vec2(winSize.width + 10, 0));
	auto moveByReverse_2 = moveBy_2->reverse();
	ActionInstant *flipx_2 = FlipX::create(false);
	fishSprite_2->runAction(repeatAnimate_2);
	fishSprite_2->runAction(RepeatForever::create(Sequence::create(moveBy_2, flipx_2, moveByReverse_2, flipx_2->reverse(), NULL)));
	
	auto fishSprite_3 = Sprite::createWithSpriteFrameName("bk_01.png");
	this->addChild(fishSprite_3);
	fishSprite_3->setPosition(Vec2(200, 50));
	fishSprite_3->setScale(2);
	auto animation_3 = Animation::create();
	for (int i = 1; i <= 24; i++)
	{
		if (i >= 10)
		{
			animation_3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("bk_%d.png", i)));
		}
		else
		{
			animation_3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("bk_0%d.png", i)));
		}
	}
	animation_3->setDelayPerUnit(3.0f / 30.0f);
	AnimationCache::getInstance()->addAnimation(animation_3, "action3");
	auto action_3 = AnimationCache::getInstance()->getAnimation("action3");
	auto animate_3 = Animate::create(action_3);
	auto repeatAnimate_3 = RepeatForever::create(animate_3);
	fishSprite_3->runAction(repeatAnimate_3);

	auto fishSprite_4 = Sprite::createWithSpriteFrameName("bk_01.png");
	fishSprite_4->setFlippedX(true);
	this->addChild(fishSprite_4);
	fishSprite_4->setPosition(Vec2(600, 50));
	fishSprite_4->setScale(2);
	auto delay = DelayTime::create(3);
	fishSprite_4->runAction(RepeatForever::create((Sequence::create(delay, animate_3, NULL))));


	schedule(CC_SCHEDULE_SELECTOR(OpenLayer::updateTimesPerSecond), 2.0f);

	auto rain = ParticleRain::create();
	rain->setPosition(Vec2(500, 800));
	this->addChild(rain);
	rain->setDuration(ParticleSystem::DURATION_INFINITY);
	rain->setEmissionRate(300);
	rain->setLife(4.0f);



	return true;

}
void OpenLayer::menuCallBack(Ref *pSender)
{	
	Size winSize = Director::getInstance()->getWinSize();
	SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3");
	switch (((MenuItem*)pSender)->getTag())
	{
	case 101:		
		tsm->goGameScene();
		break;
	case 102:
		Director::getInstance()->end();
		break;
		exit(0);
	case 103:
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() != true)
		{
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		}
		else
		{
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		}
		break;
	case 104:
		menu->setVisible(false);
		Label *label2 = Label::createWithTTF(SceneManger::WStrToUTF8(L"用摇杆来控制大鱼去吃小鱼，\n小鱼会巧妙运用鱼群的特性来躲避，\n需要在左上角规定的时间内吃满右上角要求的数目，\n满足数目后即可进入下一关，\n注意不要被落下的泡泡砸中，砸中会少血哦，\n如果去吃掉泡泡的话也可以回少量血，\n同时右下角还有技能可以使用，\n通过一关可以解锁一个技能哦！"), "fj3.ttf", 30);
		label2->setPosition(Vec2(winSize.width / 2+50, winSize.height*0.6));
		label2->setColor(Color3B(0, 0, 0));
		label2->setLineHeight(50);
		this->addChild(label2, 3);
		auto label_2 = Label::createWithTTF(SceneManger::WStrToUTF8(L"返回"), "fj3.ttf", 30);
		label_2->enableOutline(Color4B::BLUE, 3);
		Menu* menu_2 = NULL;
		MenuItemLabel* menuItem = MenuItemLabel::create(label_2,
			[=](Object *pSender){
			SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3");
			menu->setVisible(true);
			this->removeChild(label2);
			label_2->removeFromParent();
		});
		menu_2 = Menu::create(menuItem, NULL);
		menu_2->setPosition(Point::ZERO);
		this->addChild(menu_2, 2);
		menu_2->setPosition(Vec2(winSize.width - 80, 80));
	}
}
void OpenLayer::updateTimesPerSecond(float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto sprite = Sprite::create("qipao.png");
	this->addChild(sprite);
	sprite->setPosition(CCRANDOM_0_1()*visibleSize.width, 0);
	auto moveBy = MoveBy::create(5, Vec2(0, visibleSize.height));
	auto callFunc = CallFunc::create([this,sprite]{
		this->removeChild(sprite); });
	auto sequence = Sequence::create(moveBy, callFunc, NULL);
	sprite->runAction(sequence);
}
void OpenLayer::explain()
{
	/*auto label = Label::createWithTTF(SceneManger::WStrToUTF8(L"用摇杆来控制大鱼去吃小鱼，小鱼会巧妙运用鱼群的特性来躲避，需要在左上角规定的时间内吃满右上角要求的数目，同时右下角还有技能可以使用，通过一关可以解锁一个技能哦！"), "fj3.ttf", 30);
	label->setDimensions(600, 600);
	this->addChild(label, 2);
	label->setPosition(600, 600);*/
	Size winSize = Director::getInstance()->getWinSize();
	Label *label2 = Label::createWithTTF(SceneManger::WStrToUTF8(L"中国科协技术协会"), "fj3.ttf", 60);
	label2->setPosition(Vec2(winSize.width / 2, winSize.height*0.8));
	label2->setColor(Color3B(0, 0, 0));
	this->addChild(label2, 3);
}

