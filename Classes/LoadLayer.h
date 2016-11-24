#include"cocos2d.h"
#include"SceneManger.h"
#include"SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
class LoadLayer:public Layer
{
public:
	CREATE_FUNC(LoadLayer);
	virtual bool init();
	void onScheduleOnce(float);
	virtual void onEnterTransitionDidFinish();
	void loadMusic(ValueVector musicFiles);
	void loadEffect(ValueVector effectFiles);
	void loadSpriteSheets(ValueVector spriteSheets);
	void progressUpdate();

	
public:
	SceneManger *tsm;
	int _sourceCount;
	float _progressInterval;
	ProgressTimer *progTime;
	
};