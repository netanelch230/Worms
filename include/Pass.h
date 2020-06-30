
#pragma once
#include"Features.h"


class Pass :public Features {
public:
	Pass() :Features(AnimationSet{ animation_skip, skipImageCount,true,1, sizeOfPassWorm }) {}
		virtual void applyFeatures() {}
		virtual void draw(sf::RenderWindow& window) {}
		void update() {};
		virtual bool runFeature(sf::Event& event, sf::RenderWindow& window, 
			bool& drawFeatur, const sf::Vector2f& wormPosition) { return false; }
};