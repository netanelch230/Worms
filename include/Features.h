#pragma once 
#include "AnimationObject.h"

class Features:public AnimationObject
{
public:
	Features(sf::Texture& texture, sf::Vector2f& pos) :
		AnimationObject(spriteSetting{ pos,{20,30},texture }, { 1,36 }) {};
	//~Features();
	

private:
	sf::Vector2f m_featureLocation;
};
