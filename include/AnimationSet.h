#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

struct AnimationSet 
{
	int photo;
	sf::Vector2u imageCount; 
	bool restart; //האם לרוץ על האנמציה מספר פעמים
	int distance;//מרחק בין האנימציות של התולעים
	sf::Vector2f sizeOfAni;
};