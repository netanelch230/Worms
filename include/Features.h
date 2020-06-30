#pragma once 
#include"Enum.h"
#include "AnimationSet.h"
//-------------class----------------
class Features
{
public:
	Features(AnimationSet animationSet) :
		m_animationSet(animationSet) {}
	AnimationSet getAnimationSet() { return m_animationSet; }

	virtual void applyFeatures() {}
	virtual void draw(sf::RenderWindow& window) {}
	virtual void update() {}
	virtual bool destroy(int time) { return false; }
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window, bool& drawFeatur, const sf::Vector2f& wormPosition) = 0;
	virtual ~Features() = default;
private:
	AnimationSet m_animationSet;
};
