#pragma once
#include"AnimationObject.h"
#include"Enum.h"

class Worm: public AnimationObject
{
public:
	Worm(sf::Vector2f& location, sf::Texture& tex)
		:AnimationObject(spriteSetting{ location,sizeOfWorm,tex },sf::Vector2u{ 1,36 }) {};
	void move(float time);
	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
	
	int direction();
	sf::Vector2f calculateDirection(const float& deltaTime, const int& num);
};

