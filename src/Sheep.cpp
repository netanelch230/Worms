#pragma once
#include "Sheep.h"


void Sheep::applyFeatures()
{
	AnimationObject::setAnimation({ exSheep,exSheepImageCount,false,1 }, 0.03);
}

bool Sheep::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, const sf::Vector2f& wormPosition)
{
	if (!drawFeatur)
	{
		if(event.type==sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				drawFeatur = true;
				setPosition(wormPosition);
			}
		}
	}
	else if (drawFeatur)
	{
		m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto world = getBody()->GetWorld();
				featureExplosion(*world);
				drawFeatur = false;
				return false;
			}
		}

	}
	return true;
}