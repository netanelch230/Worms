
#pragma once
#include"Features.h"


class Pass :public Features {
public:
	Pass() :Features(AnimationSet{ animation_skip, skipImageCount,false,1 }) {}
		virtual void applyFeatures(float time) {};
		virtual void draw(sf::RenderWindow& window) {}
};