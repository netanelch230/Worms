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
	virtual void applyFeatures(float time) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	AnimationSet getAnimationSet() { return m_animationSet; }
private:
	AnimationSet m_animationSet;
};
