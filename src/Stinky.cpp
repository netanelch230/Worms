#pragma once
#include "Stinky.h"

Stinky:: Stinky(b2World& world, sf::Vector2f position) :
			MovingAttack(world, spriteSetting{ position,{1,1},Resources::instance().getTexture(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1, sizeOfStinky },
				stinkyAnimationImageCaount,0, {-0.1,0 }, {0.1,0}) 
{
	m_sound.setBuffer(Resources::instance().getMusic(skunk_walk));
}
bool Stinky::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, Worm& worm)
{
	if (!drawFeatur)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto wormScale = worm.getScale();
				drawFeatur = true;
				setPosition(worm.getPosition());
				m_body->SetTransform({ (worm.getPosition().x+21) * MPP,worm.getPosition().y * MPP },
					m_body->GetAngle());
				m_sprite.setScale({ wormScale.x * -1,wormScale.y });

			}
		}
	}
	else
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



