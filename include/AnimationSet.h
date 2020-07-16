#pragma once
#include <SFML/Graphics.hpp>
#include "Resource.h"

struct AnimationSet 
{
	int photo;
	sf::Vector2u imageCount; 
	bool restart; //means if we need to run again on the animation
	int distance;//distance of animations 
	sf::Vector2f sizeOfAni;
};