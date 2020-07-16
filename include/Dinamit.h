#pragma once
#include"NonMovingAttack.h"

//--------------class--------------
class Dinamit :public NonMovingAttack
{
public:
	Dinamit(b2World& world, sf::Vector2f position);
	virtual void aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm,int& drawFeature)override;
	virtual void applyFeature(sf::Event& event, int& drawFeature) override;
	virtual void attackTakeOfPoints(Worm &worm) override;
	virtual ~Dinamit() = default;
private:
	sf::Clock m_timer;
	int m_second = 3;
	
};