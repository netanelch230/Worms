#pragma once
#include"MovingAttack.h"
#include"Resource.h"

//--------------const-------------------
const auto grenadeSize = sf::Vector2f{ 20, 20 };
const auto spriteSheetGrenadeSize = sf::Vector2u{ 1, 32 };

//-------------class-------------------
class Grenade :public MovingAttack 
{
public:
	Grenade(b2World& world, sf::Vector2f position); 
	virtual void aliveFeature(sf::Event &event, sf::RenderWindow &window, Worm &worm,int& drawFeature);
	virtual void applyFeature(sf::Event &event,int& drawFeature);
	virtual void attackTakeOfPoints(Worm &worm) override;
	virtual ~Grenade() = default;

private:
	sf::Clock m_timer;
	int m_second = 3;
	sf::Sound m_painSound;
	

};