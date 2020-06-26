#pragma once
#include "Attack.h"

class MovingAttack : public Attack 
{
public:
	MovingAttack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount, int distanceToObject = 1)
		:Attack(world, sset, animationSet, imageCount, distanceToObject) {};

	void moveWeapone();
	b2Vec2 force();
	~MovingAttack() = default;
	void changeDirection();
private:
	sf::Clock m_timeMoving;
};
