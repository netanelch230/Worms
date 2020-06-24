#pragma once
#include"Attack.h"
#include"Enum.h"


class Flick :public Attack {
public:
	Flick(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(flick) },
 spriteSheetGrenadeSize,flickImageCount,animation_flick) {}
	virtual void applyFeatures(float time) {};

};

