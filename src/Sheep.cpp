#pragma once
#include "Sheep.h"


Sheep::Sheep(b2World& world, sf::Vector2f position) :
		MovingAttack(world, spriteSetting{ position,sf::Vector2f{1,1},Resources::instance().getTexture(sheep) },
			AnimationSet{ animaiton_sheep,sheepImageCount,false,1 },
			sf::Vector2u{ 1,8 }, 1, { -0.1,2 }, {0.1,2 })
{
	m_sound.setBuffer(Resources::instance().getMusic(sheep_baa));
}
void Sheep::applyFeatures()
{
	AnimationObject::setAnimation({ exSheep,exSheepImageCount,false,1 }, 0.03);
}

bool Sheep::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, Worm& worm)
{
	if (!drawFeatur)
	{
		if(event.type==sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto wormScale = worm.getScale();
				drawFeatur = true;
				setPosition(worm.getPosition());
				m_body->SetTransform({ worm.getPosition().x * MPP,worm.getPosition().y * MPP }, m_body->GetAngle());
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