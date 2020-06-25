#pragma once
#include"Attack.h"
#include"Enum.h"


class Flick :public Attack {
public:
	Flick(b2World& world, sf::Vector2f position) :
		Attack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(animation_flick) },
			AnimationSet{ animation_flick,flickImageCount,false,1 },
			spriteSheetGrenadeSize) {}
	virtual void applyFeatures(float time) {};
	virtual void play() override {};
};


