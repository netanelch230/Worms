#pragma once
#include"MovingAttack.h"
#include"Resources.h"


class Stinky :public MovingAttack
{
	public:
		Stinky(b2World& world, sf::Vector2f position) :
			MovingAttack(world, spriteSetting{ position,grenadeSize,Resources::instance().getTexture(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1, sizeOfStinky },
				stinkyAnimationImageCaount,28, { -0.1,2 }, {0.1,2}) {}
		virtual void applyFeatures() {
			AnimationObject::setAnimation({ exSheep,exSheepImageCount,false,1 }, 0.03);
		};
			virtual void play() override {};
	private:
};