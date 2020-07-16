#pragma once
#include "Feature.h"
#include "Worm.h"

void Feature::runFeature(sf::Event& event, sf::RenderWindow& window, int& drawFeature, Worm& worm)
{
	switch(drawFeature)
	{
	case startAnimation:
		worm.setAnimation(m_animationSet, 0.03f);
		drawFeature++;
		break;
	case alive:
		aliveFeature(event, window,worm,drawFeature);
		break;
	case bomb:
		applyFeature(event,drawFeature);
		break;
	case bombAnimation:
		worm.setVelocity(1.f);
		if(bombAnimationFeature())
			drawFeature++;
		break;
	case endBombAnimation:
		endBomb();
		drawFeature++;
		break;
	}
}