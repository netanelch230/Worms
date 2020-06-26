#pragma once
#include"Features.h"
#include"AnimationObject.h"

//--------------class-------------
class Attack :public Features , public AnimationObject
{
public:
	Attack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount,int distanceToObject=1)
		:Features(animationSet),
		AnimationObject(sset, imageCount, world, true, distanceToObject) {}
	void draw(sf::RenderWindow& window) { AbsObject::draw(window); }
	virtual void play() = 0;
	void destroy();
	void update();
private:
	sf::Clock m_timeAnimation;
};