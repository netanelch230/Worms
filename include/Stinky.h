#pragma once
#include"MovingAttack.h"
#include"Resources.h"


class Stinky :public MovingAttack
{
	public:
		Stinky(b2World& world, sf::Vector2f position);
		
		virtual void applyFeatures() {
			AnimationObject::setAnimation({ exSheep,exSheepImageCount,false,1 }, 0.03);
		};
			virtual void play() override {};
			bool runFeature(sf::Event& event, sf::RenderWindow& window,
				bool& drawFeatur, Worm& worm) override;

	private:
};