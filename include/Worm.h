#pragma once
#include"AbsObject.h"
#include"Enum.h"

class Worm: public AbsObject
{
public:
	Worm(sf::Vector2f location) :AbsObject(location) {};
	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
};

