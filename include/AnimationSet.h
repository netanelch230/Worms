#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

struct AnimationSet 
{
	int photo;
	sf::Vector2u imageCount; 
	bool restart; //means if we need to run again on the animation
	float distance;//distance of animations 
	sf::Vector2f sizeOfAni;
};