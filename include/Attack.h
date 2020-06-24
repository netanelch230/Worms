#pragma once
#include"Features.h"
#include"AnimationObject.h"

//--------------class-------------
class Attack :public Features , public AnimationObject
{
public:
	Attack(b2World& world, spriteSetting sset, sf::Vector2u imageCount,
							 sf::Vector2u imagecountWorm, int place, 
		int distanceToWorm=1,int distanceToObject=1)
		:Features(imagecountWorm, place,distanceToWorm),
		AnimationObject(sset, imageCount, world, true, distanceToObject) {}
	void draw(sf::RenderWindow& window) { AbsObject::draw(window); }
	//virtual void applyFeatures(float time) = 0;
	
private:
	//int m_count;
};