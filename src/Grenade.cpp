#include "Grenade.h"
#include <iostream>


Grenade::Grenade(b2World& world, sf::Vector2f position):
		MovingAttack(world, 
			spriteSetting{ position,grenadeSize,image(grenade) },
			AnimationSet{ animation_grenade,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount,1, { -250.f, 250.f }, { 250.f, 250.f })
{
    m_body->SetFixedRotation(false);
	m_sound.setBuffer(Music(timer));

}

void Grenade::aliveFeature(sf::Event &event, sf::RenderWindow &window, Worm &worm, int& drawFeature) 
{
	if (window.pollEvent(event))
	{
		if(event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				setPosition(worm.getPosition());
				m_body->SetTransform({ worm.getPosition().x * MPP,worm.getPosition().y * MPP }, m_body->GetAngle());
				auto wormScale = worm.getScale();
				m_sprite.setScale({ wormScale.x * -1,wormScale.y });
				m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
				m_timer.restart();
				drawFeature++;
				worm.setRegularAnimation();
			}
		}
	}
}

void Grenade::applyFeature(sf::Event &event,int& drawFeature)
{
	if (m_second > 0)
	{
		float time = m_timer.getElapsedTime().asSeconds();
		if (time >= 1)
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
		m_sound.setBuffer(Music(explosion1));
		m_sound.play();
		m_painSound.setBuffer(Music(pain));
		m_painSound.play();
		setAnimation(AnimationSet{ exGrenade,exGrenadeImageCount,false }, 0.07f);
		drawFeature++;
	}
}
void Grenade::attackTakeOfPoints(Worm& worm)
{
	worm.takeOffPoints(25);
}