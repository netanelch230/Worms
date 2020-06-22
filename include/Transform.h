#pragma once
#include "Features.h"

class Transform :public Features {

public:
	Transform() :Features(teleporterImageCount, f_teleporter) {}
	virtual void applyFeatures(float time) {};
	virtual void draw(sf::RenderWindow& window) {};
};