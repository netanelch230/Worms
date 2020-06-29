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
private:
	AnimationSet m_animationSet;
};
