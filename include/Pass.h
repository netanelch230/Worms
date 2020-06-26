
#pragma once
#include"Features.h"


class Pass :public Features {
public:
	Pass() :Features(AnimationSet{ animation_skip, skipImageCount,true,1 }) {}
		virtual void applyFeatures() {}
		virtual void draw(sf::RenderWindow& window) {}
		void update() {};
};