#pragma once
#include"Attack.h"

class Sheep :public Attack 
{
public:
	Sheep(b2World& world, sf::Vector2f position) :
		Attack(world, spriteSetting{ position,grenadeSize,Resources::instance().getTexture(sheep) },
		AnimationSet{ animaiton_sheep,sheepImageCount,false,1 },
		GreenGrenadeImageCount) {}
	virtual void applyFeatures(float time) {};
private:

};