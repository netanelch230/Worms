#pragma once
#include "Feature.h"

//--------class---------
class WhiteFlag : public Feature
{
public:
	WhiteFlag() : Feature(AnimationSet{ animation_whiteFlag,  whiteFlagImageCount,true,1 , sizeOfWhiteFlagWorm}) {}
	virtual void draw(sf::RenderWindow& window) {};
	virtual void update() override {}
	virtual void aliveFeature(sf::Event& event, sf::RenderWindow& window,
		Worm& worm, int& drawFeature) {}
	virtual void applyFeature(sf::Event& event, int& drawFeature) {}
	virtual ~WhiteFlag() = default;

};
