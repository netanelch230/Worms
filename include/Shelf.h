#pragma once
#include"AbsObject.h"
#include"Resources.h"
#include"staticObject.h"

class Shelf :public staticObject
{
public:
	//Shelf() {};
	Shelf(b2World& world,sf::Vector2f size,sf::Vector2f position) :
		staticObject(spriteSetting{position,size, Resources::instance().getTexture(shelf)}, world) {
		//m_sprite.setFillColor(sf::Color::Transparent);
	}
};