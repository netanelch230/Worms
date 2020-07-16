#pragma once
#include "staticObject.h"
#include "Enum.h"
#include "Resource.h"
#include <memory>

//--------------class--------------
class Board
{
public:
	Board() = default;
	void createBord(b2World& world, int type = jeruBack);
	void draw(sf::RenderWindow& window) const;
	~Board() = default;

private:
	void loadBorders(b2World& world);
	void loadJerusalem(b2World& world);
	void loadDesert(b2World& world);
	spriteSetting getSpriteSetting(sf::Vector2f position, int pic) const;

	std::vector<std::unique_ptr<staticObject>> m_staticMapObject;
	sf::RectangleShape m_backGround;
};