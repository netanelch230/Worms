#pragma once
#include "Attack.h"

class NonMovingAttack : public Attack
{
public:
	NonMovingAttack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount, int distanceToObject = 1)
		:Attack(world,  sset, animationSet, imageCount, distanceToObject) {}
	virtual ~NonMovingAttack()= default;
private:

};