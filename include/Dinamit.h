#pragma once
#include"NonMovingAttack.h"

class Dinamit :public NonMovingAttack
{
public:
	Dinamit(b2World& world, sf::Vector2f position);
	virtual void applyFeatures() override {};
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window, bool& drawFeatur, Worm& worm) override;
	virtual void play() override {};
	

private:
	sf::Clock m_timer;
	int m_second = 5;
	
};