#pragma once
#include "Features.h"


class WhiteFlag : public Features
{
public:
	WhiteFlag() : Features(AnimationSet{ animation_whiteFlag,  whiteFlagImageCount,true,1 , sizeOfWhiteFlagWorm}) {}
	virtual void applyFeatures() {}
	virtual void draw(sf::RenderWindow& window) { };
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window,
		bool& drawFeatur, const sf::Vector2f& wormPosition) override {return false;}
	virtual void update() override {}
	

private:
};
