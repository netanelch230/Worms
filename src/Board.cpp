#pragma once
#include "Board.h"
#include <memory>

Board::Board(int type, std::shared_ptr<b2World> world) :m_world(world)
{
	m_backGround.setTexture(&Resources::instance().getTexture(type));
	m_backGround.setSize({WIDTH, HEIGHT});
	
	loadBorders();

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

void Board::draw(sf::RenderWindow& window) const
{
	window.draw(m_backGround);
	for (auto i : m_staticMapObject)
		i.draw(window);
}

void Board::loadBorders()
{

	m_staticMapObject.push_back(staticObject(spriteSetting{ {0,650},{3000,1},
		Resources::instance().getTexture(jeruland1) }, *m_world.get()));
	m_staticMapObject[0].setTranspert();
	m_staticMapObject.push_back(staticObject(spriteSetting{ {0,0},{2400,1},
		Resources::instance().getTexture(jeruland1) }, *m_world.get()));
	m_staticMapObject[1].setTranspert();
	m_staticMapObject.push_back(staticObject(spriteSetting{ {10,0},{1,2000},
		Resources::instance().getTexture(jeruland1) }, *m_world.get()));
	m_staticMapObject[2].setTranspert();
	m_staticMapObject.push_back(staticObject(spriteSetting{ {1270,0},{1,2000},
		Resources::instance().getTexture(jeruland1) }, *m_world.get()));
	m_staticMapObject[3].setTranspert();

}

void Board::loadJerusalem()
{
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{1000,250},jeruland1),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{1071,250},jeruland1),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{800,500},jeruland1),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{50,300},jeruland1),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{300,400},jeruland1),*m_world.get()));
	/*m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{100,550},westrenWall),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{500,450},lionGate),*m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{1000,350},daviaTower),*m_world.get()));*/
	
}
void Board::loadDesert()
{

	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 10,200 }, desertLand3), *m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 700,250 }, desertLand3), *m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 1000,300 }, desertLand7), *m_world.get()));
	/*m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 100,550 }, camel), *m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 750,600 }, cactus), *m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 500,450 }, tent), *m_world.get()));
	m_staticMapObject.push_back(staticObject(getSpriteSetting(sf::Vector2f{ 1000,550 }, waterWall), *m_world.get()));*/

}

spriteSetting Board::getSpriteSetting(sf::Vector2f position, int pic) const
{
	auto tempSize = Resources::instance().getTexture(pic).getSize();
	auto size = sf::Vector2f {(float)tempSize.x,(float) tempSize.y };
	auto s = spriteSetting {position,size, Resources::instance().getTexture(pic)};
	return s;
}

