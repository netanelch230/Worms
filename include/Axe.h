#pragma once
#include"Attack.h"

class Axe :public Attack
{
public:
   Axe(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(axe) },
 spriteSheetGrenadeSize,GreenGrenadeImageCount,f_axe) {};


private:

}