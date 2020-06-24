#pragma once
#include "staticObject.h"
#include "Enum.h"
#include "Resources.h"
#include <memory>

class Board
{
public:
	Board(int type, std::shared_ptr <b2World> world);
	Board() = default;
	void draw(sf::RenderWindow& window) const;
private:
	void loadBorders();
	void loadJerusalem();
	void loadDesert();
	spriteSetting getSpriteSetting(sf::Vector2f position, int pic) const;

	std::vector<staticObject> m_staticMapObject;
	sf::RectangleShape m_backGround;
	std::shared_ptr <b2World> m_world;
};