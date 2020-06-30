#pragma once
#include"MovingAttack.h"
#include"Resources.h"


class Stinky :public MovingAttack
{
	public:
		Stinky(b2World& world, sf::Vector2f position) :
			MovingAttack(world, spriteSetting{ position,{10,10},Resources::instance().getTexture(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1, sizeOfStinky },
				stinkyAnimationImageCaount,28, { -0.1,0 }, {0.1,0}) {}
		virtual void applyFeatures() {
			AnimationObject::setAnimation({ exSheep,exSheepImageCount,false,1 }, 0.03);
		};
			virtual void play() override {};
			bool runFeature(sf::Event& event, sf::RenderWindow& window,
				bool& drawFeatur, const sf::Vector2f& wormPosition) override;

	private:
};