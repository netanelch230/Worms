#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"

struct spriteSetting
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture& picture;
	
};
class AbsObject
{
public:
	//AbsObject() {};
	AbsObject(spriteSetting);
	void draw(sf::RenderWindow& window);
	virtual bool touch(sf::Vector2f location);
	//void update(float deltaTime);

protected:
	sf::RectangleShape m_sprite;

};