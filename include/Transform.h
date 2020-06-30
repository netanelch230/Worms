#pragma once
#include "Features.h"

class Transform :public Features {

public:
	Transform() :Features(AnimationSet{ animation_teleporter ,teleporterImageCount ,false,1} ) {}
	virtual void applyFeatures() {};
	virtual void draw(sf::RenderWindow& window) {};
	void update() {}
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window, bool& drawFeatur, const sf::Vector2f& wormPosition) { return false; }
};