 #pragma once
#include "Speed.h"
#include <iostream>

Speed::Speed()
	:Feature(AnimationSet{ animation_worm, wormImageCount ,true,1,sizeOfWorm })
{
	m_sound.setBuffer(Music(run_away));
}
void Speed::aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature)
{
	worm.setVelocity(2.f);
	m_sound.play();
	m_runTimer.restart();
	drawFeature++;
}

void Speed::applyFeature(sf::Event& event, int& drawFeature)
{

	if (m_second > 0)
	{
		float time = m_runTimer.getElapsedTime().asSeconds();
		if (time >= 1)
		{
			m_second--;
			m_runTimer.restart();
		}
	}
	else
	  drawFeature++;
}
