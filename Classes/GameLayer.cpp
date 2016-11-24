#include"GameLayer.h"
#include"FishLayer.h"
#include"SceneManger.h"
bool GameLayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	
	auto _background=setBackground1("bj1.png",1);
	auto label_1 = Label::createWithTTF(SceneManger::WStrToUTF8(L"返回"), "fj3.ttf", 40);
	label_1->enableOutline(Color4B::BLUE, 3);
	MenuItemLabel *menuItem_2 = MenuItemLabel::create(label_1, CC_CALLBACK_1(GameLayer::menuCallBack_Start, this));
	menuItem_2->setTag(105);
	menuItem_2->setPosition(Vec2(winSize.width*0.9, winSize.height*0.1));

	auto menu_1 = MenuItemImage::create("button_selectscene2_001-hd.png", "button_selectscene2_001-hd.png");
	menu_1->setPosition(Vec2(winSize.width / 2-300, winSize.height / 2));
	menu_1->setScale(0.5);
    
	auto menu_2 = MenuItemImage::create("button_selectscene3_001-hd.png", "button_selectscene3_001-hd.png");
	menu_2->setPosition(Vec2(winSize.width / 2 , winSize.height / 2));
	menu_2->setScale(0.5);

	auto menu_3 = MenuItemImage::create("button_selectscene5_002-hd.png", "button_selectscene5_002-hd.png");
	menu_3->setPosition(Vec2(winSize.width / 2+300, winSize.height / 2));
	menu_3->setScale(0.5);

	MenuItemImage *menu_4 = NULL;
	MenuItemImage *menu_5 = NULL;
	MenuItemImage *menu_6 = NULL;
	if (FishLayer::level >= 0)
	{	
		menu_4 = MenuItemImage::create("button_selectscene2_002-hd.png", "button_selectscene2_002-hd.png", [this](Ref *pSender){SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3");
			                                                                                                                    FishLayer::level = 0;
		                                                                                                                        this->startGame(); });
		menu_4->setPosition(menu_1->getPosition());
		menu_4->setTag(106);
		menu_4->setScale(0.5);
	}

	if (FishLayer::level >= 1)
	{
		menu_5 = MenuItemImage::create("button_selectscene3_002-hd.png", "button_selectscene3_002-hd.png", [this](Ref *pSender){SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3"); 
		                                                                                                                        FishLayer::level = 1;
		                                                                                                                         this->startGame(); });
		menu_5->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
		menu_5->setTag(107);
		menu_5->setScale(0.5);
	}

	if (FishLayer::level >= 2)
	{
		menu_6 = MenuItemImage::create("button_selectscene5_001-hd.png", "button_selectscene5_001-hd.png", [this](Ref *pSender){SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3"); 
		                                                                                                                        FishLayer::level = 2;
		                                                                                                                        this->startGame(); });
		menu_6->setPosition(menu_3->getPosition());
		menu_6->setTag(108);
		menu_6->setScale(0.5);
	}
	menu = Menu::create(menuItem_2, menu_1,menu_2, menu_3, menu_4, menu_5, menu_6, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 2);

	auto rain = ParticleRain::create();
	rain->setPosition(Vec2(500, 800));
	this->addChild(rain,2);
	rain->setDuration(ParticleSystem::DURATION_INFINITY);
	rain->setEmissionRate(300);
	rain->setLife(4.0f);

	return true;

}
void GameLayer::menuCallBack_Start(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound_button.mp3");
	Size winSize = Director::getInstance()->getWinSize();

	switch (((MenuItem*)pSender)->getTag())
	{
	case 104:		
		this->startGame();
		break;
	case 105:
		tsm->goOpenScene();
		break;
	}
}
Sprite *GameLayer::setBackground1(const string& fileNamle,int n)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto _background = Sprite::create(fileNamle);
	_background->setAnchorPoint(Vec2(0, 0));
	_background->setPosition(Vec2(0,0));
	_background->setScale(1.1);
	this->addChild(_background, n);
	return _background;
}
Sprite *GameLayer::setBackground2(const string& fileNamle, int n)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto _background = Sprite::create(fileNamle);
	_background->setPosition(Vec2(3 * winSize.width / 2, winSize.height / 2));
	_background->setScale(1.1);
	this->addChild(_background, n);
	return _background;
}


void GameLayer::startGame()
{
	FishLayer *layer=FishLayer::create();
	(tsm->gameScene)->addChild(layer);
	layer->setTag(5);
	this->removeFromParent();
}