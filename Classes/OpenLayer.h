#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"SceneManger.h"
USING_NS_CC;
using namespace CocosDenshion;
class OpenLayer:public Layer
{
public:
	CREATE_FUNC(OpenLayer);
	virtual bool init();
	void menuCallBack(Ref *psender);
	void updateTimesPerSecond(float);
public:
	SceneManger *tsm;
private:
	void explain();
	Menu *menu;
	
};