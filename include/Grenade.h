#pragma once
#include"Attack.h"
#include"Resources.h"

//--------------const-------------------
const auto grenadeSize = sf::Vector2f{ 20, 20 };
const auto spriteSheetGrenadeSize = sf::Vector2u{ 1, 32 };

//-------------class-------------------
class Grenade :public Attack 
{
public:
	Grenade(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(grenade) },
 spriteSheetGrenadeSize,GreenGrenadeImageCount,f_grenade) {}

private:


};