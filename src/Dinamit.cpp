#pragma once
#include"Dinamit.h"
#include <iostream>

Dinamit::Dinamit(b2World& world, sf::Vector2f position):
NonMovingAttack(world,
	spriteSetting{ position,{20,20},Resources::instance().getTexture(dinamit) },
	AnimationSet{ animation_begin_dinamit,sf::Vector2u{1,10},false,0 },
	sf::Vector2u{ 1,14 },0)
{
	m_soundTimer.setBuffer(Resources::instance().getMusic(timer));
}

bool Dinamit::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur,const sf::Vector2f& wormPosition)
{
	if (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				std::cout << "in";
				drawFeatur = true;
				setPosition(wormPosition);
				m_timer.restart();
			}
			break;
		}
	}
	if (drawFeatur)
	{
		if (m_second !=-1)
		{
			float time = m_timer.getElapsedTime().asSeconds();
			std::cout<< time << std::endl;
			
			if (time >= 1.f)
			{
				m_second--;
				m_timer.restart();
				m_soundTimer.play();
			}
		}
		else {
			auto world = getBody()->GetWorld();
			featureExplosion(*world);
			return false;
		}
	}
	return true;
}