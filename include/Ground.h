#pragma once
#include"AbsObject.h"
#include"Resources.h"

class Ground :public AbsObject
{
public:
	Ground() {};
	Ground(b2World& world) :
		AbsObject(spriteSetting{ sf::Vector2f(0,600),sf::Vector2f(3000,20),Resources::instance().getMenuTexture(0)}, world, false) {
		m_sprite.setFillColor(sf::Color::Transparent);
	}
};