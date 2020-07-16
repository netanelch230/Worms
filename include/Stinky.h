#pragma once
#include"MovingAttack.h"
#include"Resource.h"

//------------class-----------	
class Stinky :public MovingAttack
{
public:
	Stinky(b2World& world, sf::Vector2f position);
	virtual void aliveFeature(sf::Event &event, sf::RenderWindow &window, Worm &worm,int& drawFeature);
	virtual void applyFeature(sf::Event &event,int& drawFeature);
	virtual void attackTakeOfPoints(Worm &worm) override;
	virtual ~Stinky() = default;

private:
	sf::Sound m_soundGass;
};