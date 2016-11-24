#include"cocos2d.h"
USING_NS_CC;
using namespace std;
class Bubble :public Node
{
public:
	static Bubble* create( const string&);
	void down();
	Vec2 randomGenerate();
	CREATE_FUNC(Bubble);
	void bubbleInit(const string&);
	Sprite* bubbleImage;
};