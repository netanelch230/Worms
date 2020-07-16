#pragma once
#include"MovingAttack.h"

//------------class-----------
class Sheep :public MovingAttack 
{
public:
	Sheep(b2World& world, sf::Vector2f position);
	virtual void aliveFeature(sf::Event &event, sf::RenderWindow &window, Worm &worm,int& drawFeature);
	virtual void applyFeature(sf::Event &event,int& drawFeature);
	virtual void attackTakeOfPoints(Worm &worm) override;
	virtual ~Sheep() = default;

};