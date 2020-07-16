#pragma once 
#include"Enum.h"
#include "AnimationSet.h"
#include "Worm.h"

//-------------class----------------
class Feature
{
public:
	Feature(AnimationSet animationSet) :
		m_animationSet(animationSet) {}
	AnimationSet getAnimationSet() { return m_animationSet; }

	virtual void draw(sf::RenderWindow& window) {}
	virtual void update() {}
	virtual bool destroy(int time) { return false; }
	void runFeature(sf::Event& event, sf::RenderWindow& window, int& drawFeature, Worm& worm);
	virtual void aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature) {}
	virtual void applyFeature(sf::Event& event, int& drawFeature) {}
	virtual bool bombAnimationFeature() { return true; }
	virtual void endBomb() {}
	virtual ~Feature() = default;

protected:
	sf::Sound m_sound;

private:
	AnimationSet m_animationSet;
};
