#pragma once
#include"Feature.h"

//------------class-----------
class Speed :public Feature {
public:
	Speed();
	virtual void applyFeature() {};
	virtual void draw(sf::RenderWindow& window) {};
	void update() {}
	virtual void aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature);
	virtual void applyFeature(sf::Event& event, int& drawFeature);
	virtual ~Speed() = default;

private:
	sf::Clock m_runTimer;
	int m_second = speedRunTimer;
};

 
