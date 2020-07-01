#pragma once
#include"Dinamit.h"
#include <iostream>

Dinamit::Dinamit(b2World& world, sf::Vector2f position):
NonMovingAttack(world,
	spriteSetting{ position,{20,20},Resources::instance().getTexture(dinamit) },
	AnimationSet{ animation_begin_dinamit,sf::Vector2u{1,10},false,0 },
	sf::Vector2u{ 1,17 }, 0)
{
	m_sound.setBuffer(Resources::instance().getMusic(timer));
}

bool Dinamit::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur,Worm& worm)
{
	if (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				drawFeatur = true;
				setPosition(worm.getPosition());
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
				m_sound.play();
			}
		}
		else {
			auto world = getBody()->GetWorld();
			featureExplosion(*world);
			m_sound.setBuffer(Resources::instance().getMusic(explosion2));	
			m_sound.play();
			drawFeatur = false; //ask nati- why???
			return false;
		}
	}
	return true;
}