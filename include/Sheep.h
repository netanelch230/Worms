#pragma once
#include"Attack.h"

class Sheep :public Attack 
{
	Sheep(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(sheep) },
 spriteSheetGrenadeSize,GreenGrenadeImageCount,f_sheep) {}

};