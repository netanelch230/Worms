#pragma once
#include "Board.h"
#include <memory>


void Board::createBord(b2World& world, int type)
{
	m_backGround.setTexture(&image(type));
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

	m_staticMapObject.emplace_back(std::make_unique<staticObject>(spriteSetting{ {650,700},{1280,70},
		image(jeruLand) },world));
	m_staticMapObject[0]->setTranspert();
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(spriteSetting{ {650,0},{3000,70},
		image(jeruLand) },world));
	m_staticMapObject[1]->setTranspert();
	m_staticMapObject.push_back(std::make_unique<staticObject>(spriteSetting{ {7,350},{70,2000},
		image(jeruLand) },world));
	m_staticMapObject[2]->setTranspert();
	m_staticMapObject.push_back(std::make_unique<staticObject>(spriteSetting{ {1280,350},{70,2000},
		image(jeruLand) },world));
	m_staticMapObject[3]->setTranspert();

}

void Board::loadJerusalem(b2World& world)
{
	
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{1130,250},jeruLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{750,320},jeruLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{130,300},jeruLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{400,400},jeruLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{500,620},kneset),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{1000,590},jaffaGate),world));
	
	
}
void Board::loadDesert(b2World& world)
{

	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 100,400 }, desertLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 350,350 }, desertLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 1150,480 }, desertLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 600,280 }, desertLand),world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 600,600 }, camel), world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 900,500 }, desertHome), world));
	m_staticMapObject.emplace_back(std::make_unique<staticObject>(getSpriteSetting(sf::Vector2f{ 350,600 }, waterWall), world));

}

spriteSetting Board::getSpriteSetting(sf::Vector2f position, int pic) const
{
	auto tempSize = image(pic).getSize();
	auto size = sf::Vector2f {(float)tempSize.x,(float) tempSize.y };
	auto s = spriteSetting {position,size, image(pic)};
	return s;
}

