#pragma once
#include"AbsObject.h"
#include"Enum.h"

class Worm: public AbsObject
{
public:
	Worm(sf::Vector2f location) :AbsObject(location) {};
	void move(float time);
	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
	
	int direction();
	sf::Vector2f calculateDirection(const float& deltaTime, const int& num);
};

