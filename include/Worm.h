#pragma once
#include"AbsObject.h"
#include"Enum.h"

class Worm: public AbsObject
{
public:
	Worm(const sf::Vector2f& location, const sf::Texture& tex)
		:AbsObject({ location,sizeOfWorm,tex }) {};
	void move(float time);
	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
	
	int direction();
	sf::Vector2f calculateDirection(const float& deltaTime, const int& num);
};

