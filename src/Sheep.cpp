#pragma once
#include "Sheep.h"


Sheep::Sheep(b2World& world, sf::Vector2f position) :
		MovingAttack(world, spriteSetting{ position,sf::Vector2f{1,1},image(sheep) },
			AnimationSet{ animaiton_sheep,sheepImageCount,false,1 },
			sf::Vector2u{ 1,8 },0, { -0.1f ,2.f }, {0.1f,2.f })
{
	m_sound.setBuffer(Music(sheep_baa));
}
void Sheep::aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			auto wormScale = worm.getScale();
			setPosition(worm.getPosition());
			m_body->SetTransform({ worm.getPosition().x * MPP,worm.getPosition().y * MPP }, m_body->GetAngle());
			m_sprite.setScale({ wormScale.x * -1,wormScale.y });
			drawFeature++;
			worm.setRegularAnimation();
		}
	}
}

void Sheep::applyFeature(sf::Event &event,int& drawFeature)
{
	if(m_sound.getStatus()!=m_sound.Playing)
		m_sound.play();
	m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto world = getBody()->GetWorld();
				featureExplosion(*world);
				m_sound.setBuffer(Music(explosion1));
				m_sound.play();
				setAnimation(AnimationSet{ exSheep,exSheepImageCount, false }, 0.07f);
				drawFeature++;
			}
		}
}

void Sheep::attackTakeOfPoints(Worm& worm)
{
	worm.takeOffPoints(10);
}