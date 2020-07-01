#pragma once
#include"MovingAttack.h"

class Sheep :public MovingAttack 
{
public:
	Sheep(b2World& world, sf::Vector2f position);
	
	virtual void applyFeatures() override;
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window,
		bool& drawFeatur, Worm& worm) override;
	
private:


};