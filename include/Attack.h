#pragma once
#include"Features.h"
#include"AnimationObject.h"

//--------------class-------------
class Attack :public Features , public AnimationObject
{
public:
	Attack(b2World& world, spriteSetting sset, sf::Vector2u imageCount,
							 sf::Vector2u imagecountWorm, int place)
		:Features(imagecountWorm, place),
		AnimationObject(sset, imageCount, world, true) {}
	void foo();
	
private:
	//int m_count;
};