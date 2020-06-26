#pragma once
#include"MovingAttack.h"
#include"Resources.h"


class Stinky :public MovingAttack
{
	public:
		Stinky(b2World& world, sf::Vector2f position) :
			MovingAttack(world, spriteSetting{ position,grenadeSize,Resources::instance().getTexture(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1 },
			spriteSheetGrenadeSize) {}
			virtual void applyFeatures() {};
			virtual void play() override {};
	private:
};