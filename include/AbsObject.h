#pragma once
#include <SFML/Graphics.hpp>
struct spriteSetting
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture picture;

};
class AbsObject
{
public:
	AbsObject() {};
	AbsObject(const spriteSetting&);
	void draw(sf::RenderWindow& window);
	virtual bool touch(sf::Vector2f location);

protected:
	sf::RectangleShape m_sprite;
};