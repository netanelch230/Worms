#pragma once
#include"Attack.h"
#include"Resources.h"


class Stinky :public Attack{
public:
Stinky(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(stinky) },
 spriteSheetGrenadeSize,stinkyImageCount,f_stinky) {}

};