#pragma once 
#include"Enum.h"
//-------------class----------------
class Features
{
public:
	Features(sf::Vector2u imagecount, int place) :m_imageCount(imagecount), m_place(place) {}
	sf::Vector2u getImageCount() { return m_imageCount; }
	int getPlace() { return m_place; }
	virtual ~Features() = default;
	
private:
	sf::Vector2u m_imageCount;
	int m_place;
};
