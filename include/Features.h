#pragma once 
#include"Enum.h"
#include "AnimationSet.h"
//-------------class----------------
class Features
{
public:
	Features(AnimationSet animationSet) :
		m_animationSet(animationSet) {}
	virtual ~Features() = default;
	virtual void applyFeatures() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	AnimationSet getAnimationSet() { return m_animationSet; }
	virtual void update() = 0;
	virtual bool destroy(int time) { return false; }
	virtual void runFeature(sf::Event& event, sf::RenderWindow& window) {}
private:
	AnimationSet m_animationSet;
};
