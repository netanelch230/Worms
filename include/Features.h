#pragma once 
#include "AnimationObject.h"

class Features:public AnimationObject
{
public:
	Features(const sf::Texture& texture, const sf::Vector2f& pos) :
		AnimationObject(spriteSetting{ pos,{20,30},texture }, { 1,36 }) {};
	//~Features();
	

private:
};
