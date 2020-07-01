 #pragma once
#include "Artilary.h"
#include <iostream>

Artilary::Artilary(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,sf::Vector2f{20,20},Resources::instance().getTexture(artileri) },
			AnimationSet{ animation_artilary,artilaryimagecount,false,1, {100, 100}, 0.07f },
			callartilary) 
{
	m_sound.setBuffer(Resources::instance().getMusic(artilary));
}
bool Artilary::runFeature(sf::Event& event, sf::RenderWindow& window, 
	bool& drawFeatur, Worm& worm)
{
	if (!drawFeatur)
	{
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Button::Left)
				{
					float MouseX = sf::Mouse::getPosition(window).x;
					auto pos = sf::Vector2f{ MouseX,0 };
					setPosition(pos);
					m_body->SetTransform({ MouseX * MPP,20 * MPP }, m_body->GetAngle());
					drawFeatur = true;
				}	
				break;
			}
		}
	}
	/*else if (m_explode)
	{
		featureExplosion(*m_body->GetWorld());
		drawFeatur = false;
		m_sound.play();
		return false;
	}*/
	return true;
}