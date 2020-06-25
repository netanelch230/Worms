#pragma once
#include"Attack.h"

class Sheep :public Attack 
{
public:
	Sheep(b2World& world, sf::Vector2f position) :
		Attack(world, spriteSetting{ position,sf::Vector2f{1,1},Resources::instance().getTexture(sheep) },
		AnimationSet{ animaiton_sheep,sheepImageCount,false,1 },
			sf::Vector2u{ 1,32 }) {}
	virtual void applyFeatures(float time);
	virtual void play() override {};
	void changeDirection();
private:


};