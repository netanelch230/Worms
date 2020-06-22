#pragma once 
#include"Enum.h"
//-------------class----------------
class Features
{
public:
	Features(sf::Vector2u imagecount, int place,int distance=1) :
		m_imageCount(imagecount), m_place(place),m_distance(distance) {}
	sf::Vector2u getImageCount() { return m_imageCount; }
	int getPlace() { return m_place; }
	int getDistance() { return m_distance; }
	virtual ~Features() = default;
	virtual void applyFeatures(float time) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	
private:
	sf::Vector2u m_imageCount;
	int m_place;
	int m_distance;
};
