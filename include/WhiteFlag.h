#pragma once
#include "Features.h"


class WhiteFlag : public Features
{
public:
	WhiteFlag() : Features(AnimationSet{ animation_whiteFlag,  whiteFlagImageCount,true,-1 }) {}
	virtual void applyFeatures() {}
	virtual void draw(sf::RenderWindow& window) { };	
	void update() {}

private:
};
