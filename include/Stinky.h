#pragma once
#include"Attack.h"
#include"Resources.h"


class Stinky :public Attack
{
	public:
		Stinky(b2World& world, sf::Vector2f position) :
			Attack(world, spriteSetting{ position,grenadeSize,Resources::instance().getTexture(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1 },
			spriteSheetGrenadeSize) {}
			virtual void applyFeatures(float time) {};
	private:
};