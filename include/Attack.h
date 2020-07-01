#pragma once
#include"Features.h"
#include"AnimationObject.h"
#include "MyQueryCallback.h"
#include "Worm.h"
//--------------class-------------
class Attack :public Features , public AnimationObject
{
public:
	Attack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount,int distanceToObject=1, float switchTime= 0.03f)
		:Features(animationSet),
		AnimationObject(sset, imageCount, world, true, distanceToObject, switchTime) {}
	void draw(sf::RenderWindow& window) { AbsObject::draw(window); }
	virtual void play() {};
	
	bool destroy(int time);
	void featureExplosion(b2World& world);
	void update();
	virtual ~Attack() = default;


private:

	void blastPoint(void* data);
	void applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower);
	sf::Clock m_timeAnimation;

};