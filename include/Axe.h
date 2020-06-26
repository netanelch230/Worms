#pragma once
#include"NonMovingAttack.h"

class Axe :public NonMovingAttack
{
public:
	Axe(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(axe) },
			AnimationSet{ animation_axe,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount ) {}
	virtual void applyFeatures() {};
	virtual void play() override {};
	

private:

};