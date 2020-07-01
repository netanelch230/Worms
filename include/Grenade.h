#pragma once
#include"MovingAttack.h"
#include"Resources.h"

//--------------const-------------------
const auto grenadeSize = sf::Vector2f{ 20, 20 };
const auto spriteSheetGrenadeSize = sf::Vector2u{ 1, 32 };

//-------------class-------------------
class Grenade :public MovingAttack 
{
public:
	Grenade(b2World& world, sf::Vector2f position); 
	bool runFeature(sf::Event& event, sf::RenderWindow& window,
		bool& drawFeatur, Worm& worm);
private:
	sf::Clock m_timer;
	int m_second = 3;
	

};