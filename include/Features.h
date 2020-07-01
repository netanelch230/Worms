#pragma once 
#include"Enum.h"
#include "AnimationSet.h"
#include "Worm.h"
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
	virtual bool runFeature(sf::Event& event, sf::RenderWindow& window, bool& drawFeatur, Worm& worm) = 0;
	virtual ~Features() = default;

protected:
	sf::Sound m_sound;

private:
	AnimationSet m_animationSet;
};
