#include"cocos2d.h"
#include"SceneManger.h"
#include"GameLayer.h"
#include"Fish.h"
#include"HRocker.h"
#include"Bubble.h"
#include"ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#pragma once
using namespace CocosDenshion;
USING_NS_CC;
using namespace ui;
class Skill;
class FishLayer :public GameLayer
{
  public:
	CREATE_FUNC(FishLayer);
	virtual bool init();
	void update(float delata);
    HRocker *rocker;
	Shark *shark;
	Label *label1;
	Label *label2;
	Label *label3;
	Label *label4;
	Map<string,Fish*>fish;
	void setViewPointCenter(float, Vec2,Vec2);
	Sprite *_background1;
	Sprite *_background2;
	void sharkMove();
	Sprite *sharkHead;
	Sprite* sharkBody;
    Rect getBoundingBox(Sprite *sprite)const;
	Sprite *cutShark1(Sprite*);
	Sprite* cutShark2(Sprite*);
	vector<int>lock;
	void updateTimesPerSecond(float delta);
	Menu *menu;
	Vector<Bubble*>bubble;
	ProgressTimer* progTime;
	int _timeLost;
	static int level;
	void timeLost(float);
	LoadingBar *blood;
	Size visibleSize;
	int testDirection(Fish*);
	void win();
	void lose();
	void restart(Ref*);
	void nextLevel(Ref*);
	void moveNode(float);
	Sprite *qipao;
	Skill *skill;
	ClippingNode *clipNode;
	void updateTimesFiveSecond(float);
	void drawCircle(Vec2);
	LightFish *lightFish;
	static int T;
	void waterWeedsInit();
	static float speed;
	static float rotationSpeed;
};


