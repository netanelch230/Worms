#pragma once
#include "Features.h"


class WhiteFlag : public Features
{
public:
	WhiteFlag() : Features(whiteFlagImageCount, animation_whiteFlag) {}
	virtual void applyFeatures(float time) {}
	virtual void draw(sf::RenderWindow& window) { };	
private:
};
