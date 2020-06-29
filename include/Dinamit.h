#pragma once
#include"NonMovingAttack.h"

class Dinamit :public NonMovingAttack
{
public:
	Dinamit(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(dinamit) },
			AnimationSet{ animation_begin_dinamit,sf::Vector2u{1,1},false,1 },
			sf::Vector2u{ 1,1 }) {}
	virtual void applyFeatures() {};
	virtual void play() override {};
	

private:

};