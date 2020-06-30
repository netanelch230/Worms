#pragma once
#include "Attack.h"


class MovingAttack : public Attack 
{
public:
	MovingAttack(b2World& world, spriteSetting sset, AnimationSet animationSet,
		sf::Vector2u imageCount, int distanceToObject, b2Vec2 rightForce,b2Vec2 leftForce)
		:   Attack(world, sset, animationSet, imageCount, distanceToObject) ,m_leftForce(rightForce),m_rightForce(rightForce){};

	void moveWeapone();
	b2Vec2 force();
	~MovingAttack() = default;
	void changeDirection();



private:
	b2Vec2 m_rightForce;
	b2Vec2 m_leftForce;
	sf::Clock m_timeMoving;
	
};
