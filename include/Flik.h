#pragma once
#include"NonMovingAttack.h"
#include"Enum.h"


class Flick :public NonMovingAttack {
public:
	Flick(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(animation_flick) },
			AnimationSet{ animation_flick,flickImageCount,false,1 },
			spriteSheetGrenadeSize) {}
	virtual void applyFeatures() {};
	virtual void play() override {};
};


