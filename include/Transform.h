#pragma once
#include "Feature.h"

//------------class-----------
class Transform :public Feature {

public:
	Transform(); 
	virtual void draw(sf::RenderWindow& window) {};
	void update() {}
	virtual void aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature);
	virtual void applyFeature(sf::Event& event, int& drawFeature);
	virtual ~Transform() = default;
};