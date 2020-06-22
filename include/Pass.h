
#pragma once
#include"Features.h"


class Pass :public Features {
public:
	Pass() :Features(skipImageCount, f_skip) {}
		virtual void applyFeatures(float time) {};
		virtual void draw(sf::RenderWindow& window) {}
};