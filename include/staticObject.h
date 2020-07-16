#pragma once
#include "AbsObject.h"

//------------class-----------
class staticObject: public AbsObject 
{
public:
	staticObject() = default;
	staticObject(spriteSetting sset, b2World& world) :AbsObject(sset, world, false) {}
	void setTranspert() { m_sprite.setColor(sf::Color::Transparent); }
	virtual ~staticObject() = default;

};
