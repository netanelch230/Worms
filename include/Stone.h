#pragma once
#include"staticObject.h"
class Stone:public staticObject
{
public:
	Stone(b2World& world, sf::Vector2f position) :
		staticObject(spriteSetting{ position,sizeOfStone, Resources::instance().getTexture(stone) }, world){}

private:

};
