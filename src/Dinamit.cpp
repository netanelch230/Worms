#pragma once
#include"Dinamit.h"
#include <iostream>

Dinamit::Dinamit(b2World& world, sf::Vector2f position) :
	NonMovingAttack(world,
		spriteSetting{ position,{20,20},image(dinamit) },
		AnimationSet{ animation_begin_dinamit,sf::Vector2u{1,10},false,0 },
		sf::Vector2u{ 1,20 }, 1, 0.15f)
{
	m_sound.setBuffer(Resource::instance().getMusic(timer));
}

void Dinamit::aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature)
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				b2Vec2 force = { 5,0 };
				setPosition(worm.getPosition());
				auto wormScale = worm.getScale();
				if (wormScale.x == 1)
					force.x *= -1;
				m_body->ApplyForce(force, m_body->GetWorldCenter(), true);
				m_body->SetTransform({ worm.getPosition().x * MPP,worm.getPosition().y * MPP },
				m_body->GetAngle());
				m_timer.restart();
				drawFeature++;
				worm.setRegularAnimation();
			}
		}
	}
}
//======================================================
void Dinamit::applyFeature(sf::Event& event, int& drawFeature)
{
	if (m_second != -1)
	{
		float time = m_timer.getElapsedTime().asSeconds();
		if (time >= 1.f)
		{
			m_second--;
			m_timer.restart();
			m_sound.play();
		}
	}
	else
	{
		auto world = getBody()->GetWorld();
		featureExplosion(*world);
		m_sound.setBuffer(Music(explosion2));
		m_sound.play();
		setAnimation(AnimationSet{ exDynamite,dinamitExImageCount , false }, 0.07f);
		drawFeature++;
	}

	//m_body->GetWorld()->DestroyBody(m_body);
}

void Dinamit::attackTakeOfPoints(Worm& worm)
{
	worm.takeOffPoints(30);
}