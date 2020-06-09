#pragma once 
#include "AbsObject.h"

class Features:public AbsObject
{
public:
	Features(const sf::Texture& texture, const sf::Vector2f& pos) :
		AbsObject({ pos,{20,30},texture }) {};
	//~Features();
	

private:
};
