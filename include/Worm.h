#pragma once
#include"AbsObject.h"
#include"Enum.h"

class Worm: public AbsObject
{
public:
	Worm(sf::Vector2f location) :AbsObject(location) {};
	bool touch(sf::Vector2f location);

	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
};

