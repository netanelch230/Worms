#pragma once
#include"NonMovingAttack.h"
#include"Resources.h"

//--------------const-------------------
const auto grenadeSize = sf::Vector2f{ 20, 20 };
const auto spriteSheetGrenadeSize = sf::Vector2u{ 1, 32 };

//-------------class-------------------
class Grenade :public NonMovingAttack 
{
public:
	Grenade(b2World& world, sf::Vector2f position); 
	virtual void applyFeatures();
	virtual void play() override;

private:
	sf::Clock m_bomb;

};