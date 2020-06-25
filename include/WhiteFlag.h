#pragma once
#include "Features.h"


class WhiteFlag : public Features
{
public:
	WhiteFlag() : Features(AnimationSet{ animation_whiteFlag,  whiteFlagImageCount,true,-1 }) {}
	virtual void applyFeatures(float time) {}
	virtual void draw(sf::RenderWindow& window) { };	
private:
};
