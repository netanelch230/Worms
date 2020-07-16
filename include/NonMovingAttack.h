#pragma once
#include "Attack.h"

//---------class----------
class NonMovingAttack : public Attack
{
public:
	NonMovingAttack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount, int distanceToObject = 1, float switchTime = 0.05f)
		:Attack(world,  sset, animationSet, imageCount, distanceToObject, switchTime) {}
	virtual ~NonMovingAttack()= default;

};