#pragma once
#include "Board.h"
#include <memory>



void Board::createBord(b2World& world, int type)
{
	m_backGround.setTexture(&Resources::instance().getTexture(type));
	m_backGround.setSize({ WIDTH, HEIGHT });

	loadBorders(world);

	switch (type)
	{
	case jeruBack:
		loadJerusalem(world);
		break;
	case desertBack:
		loadDesert(world);
		break;
	}

}

void Board::draw(sf::RenderWindow& window) const
{
	window.draw(m_backGround);
	for (auto &i : m_staticMapObject)
		i->draw(window);
}

void Board::loadBorders(b2World& world)
{

	m_staticMapObject.emplace_back(std::make_unique<staticObject>(spriteSetting{ {650,700},{1280,1},
		Resources::instance().getTexture(jeruland1) },world));
	m_staticMapObject[0]->setTranspert();
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(spriteSetting{ {650,0},{2400,1},
		Resources::instance().getTexture(jeruland1) },world));
	m_staticMapObject[1]->setTranspert();
	m_staticMapObject.push_back(std::make_unique<staticObject>(spriteSetting{ {0,350},{1,2000},
		Resources::instance().getTexture(jeruland1) },world));
	m_staticMapObject[2]->setTranspert();
	m_staticMapObject.push_back(std::make_unique<staticObject>(spriteSetting{ {1280,350},{1,2000},
		Resources::instance().getTexture(jeruland1) },world));
	m_staticMapObject[3]->setTranspert();

}

void Board::loadJerusalem(b2World& world)
{
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{1000,250},jeruland1),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{1071,250},jeruland1),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{800,500},jeruland1),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{50,300},jeruland1),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{300,400},jeruland1),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{100,600},westrenWall),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{500,600},lionGate),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{1000,600},daviaTower),world));
	
}
void Board::loadDesert(b2World& world)
{

	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 10,200 }, desertLand3),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 700,250 }, desertLand3),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 1000,300 }, desertLand7),world));
	/*m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 100,550 }, camel), *world.get()));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 750,600 }, cactus), *world.get()));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 500,450 }, tent), *world.get()));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 1000,550 }, waterWall), *world.get()));*/

}

spriteSetting Board::getSpriteSetting(sf::Vector2f position, int pic) const
{
	auto tempSize = Resources::instance().getTexture(pic).getSize();
	auto size = sf::Vector2f {(float)tempSize.x,(float) tempSize.y };
	auto s = spriteSetting {position,size, Resources::instance().getTexture(pic)};
	return s;
}

