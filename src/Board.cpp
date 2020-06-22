#pragma once
#include "Board.h"
#include <memory>
Board::Board(int type, std::shared_ptr<b2World> world):m_world(world)
{
	m_backGround.setTexture(&Resources::instance().getTexture(type));
	switch (type)
	{
	case jeruBack:
		loadJerusalem();
		break;
	case desertBack:
		loadDesert();
		break;
	}		
}

void Board::loadJerusalem()
{
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{100,200},jeruland1)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{200,450},jeruland2)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{50,550},jeruland3)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{80,200},jeruland4)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{0,650},westrenWall)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{0,100},lionGate)),*m_world.get());
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{0,450},daviaTower)),*m_world.get());
}
void Board::loadDesert()
{

}

spriteSetting Board::getSpriteSetting(sf::Vector2f position, int pic)
{
	auto size = sf::Vector2f {(float) Resources::instance().getTexture(jeruland1).getSize().x,
	(float) Resources::instance().getTexture(jeruland1).getSize().y };
	auto s = spriteSetting {position,size, Resources::instance().getTexture(jeruland1)};
	return s;
}

