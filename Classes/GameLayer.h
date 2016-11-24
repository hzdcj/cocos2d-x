#include"cocos2d.h"
#include"SceneManger.h"
USING_NS_CC;
#pragma once
class GameLayer :public Layer
{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void menuCallBack_Start(Ref *pSender);
	void startGame();
	Sprite *setBackground1(const string&,int);
	Sprite *setBackground2(const string&, int);

public:
	SceneManger *tsm;
	Menu *menu;

};