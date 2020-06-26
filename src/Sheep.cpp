#pragma once
#include "Sheep.h"


void Sheep::applyFeatures()
{
	AnimationObject::setAnimation({ exSheep,sf::Vector2u{1,20},false,1 }, 0.03);
}

void Sheep::play()
{
	
}
