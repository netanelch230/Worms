#pragma once
#include "Features.h"

class Transform :public Features {

public:
	Transform() :Features(AnimationSet{ animation_teleporter ,teleporterImageCount ,false,1} ) {}
	virtual void applyFeatures(float time) {};
	virtual void draw(sf::RenderWindow& window) {};
};