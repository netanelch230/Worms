#pragma once
#include"Attack.h"

class Axe :public Attack
{
public:
	Axe(b2World& world, sf::Vector2f position) :
		Attack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(axe) },
			AnimationSet{ animation_axe,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount ) {}
	virtual void applyFeatures(float time) {};
	virtual void play() override {};
	

private:

};