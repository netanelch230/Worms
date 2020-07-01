#pragma once
#include "Features.h"

class Transform :public Features {

public:
	Transform(); 
	virtual void applyFeatures() {};
	virtual void draw(sf::RenderWindow& window) {};
	void update() {}
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window,
		bool& drawFeatur, Worm& worm) { return false; }
};