#pragma once
#include"NonMovingAttack.h"

class Dinamit :public NonMovingAttack
{
public:
	Dinamit(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(dinamit) },
			AnimationSet{ animation_begin_dinamit,wormAnimationAxe,false,1 },
			axeImageCount ) {}
	virtual void applyFeatures() {};
	virtual void play() override {};
	

private:

};