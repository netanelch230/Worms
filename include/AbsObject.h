
#pragma once
#include <SFML/Graphics.hpp>

class AbsObject
{
public:
	AbsObject() {};
	AbsObject(sf::Vector2f);
	void setLocation(sf::Vector2f location);
	void draw(sf::RenderWindow& window);
	virtual bool touch(sf::Vector2f location);

protected:
	sf::Sprite m_sprite;
};