#pragma once
#include "AbsObject.h"

class staticObject: public AbsObject 
{
public:
	staticObject() = default;
	staticObject(spriteSetting sset, b2World& world) :AbsObject(sset, world, false) {}
	~staticObject() = default;
	void setTranspert() { m_sprite.setColor(sf::Color::Transparent); }
private:
};
