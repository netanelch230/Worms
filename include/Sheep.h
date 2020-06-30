#pragma once
#include"MovingAttack.h"

class Sheep :public MovingAttack 
{
public:
	Sheep(b2World& world, sf::Vector2f position) :
		MovingAttack(world, spriteSetting{ position,sf::Vector2f{1,1},Resources::instance().getTexture(sheep) },
		AnimationSet{ animaiton_sheep,sheepImageCount,false,1 },
			sf::Vector2u{ 1,8 }, 1, { -0.1,0 }, { 0.1,0 }) {}
	virtual void applyFeatures() override;
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window,
		bool& drawFeatur, const sf::Vector2f& wormPosition) override;
	
private:


};