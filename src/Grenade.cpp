#include "Grenade.h"
#include <iostream>


Grenade::Grenade(b2World& world, sf::Vector2f position):
		MovingAttack(world, 
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(grenade) },
			AnimationSet{ animation_grenade,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount,1, { 250.f, 250.f }, { -250.f, 250.f })
{
    m_body->SetFixedRotation(false);
	m_sound.setBuffer(Resources::instance().getMusic(timer));

}
//54*36

bool Grenade::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, Worm& worm)
{
	if (!drawFeatur)
	{
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "hey" << std::endl;
					drawFeatur = true;
					setPosition(worm.getPosition());
					m_body->SetTransform({ worm.getPosition().x * MPP,worm.getPosition().y * MPP }, m_body->GetAngle());
					m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
					m_timer.restart();
				}
				break;
			}
		}
	}
	else
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
		else {
			auto world = getBody()->GetWorld();
			featureExplosion(*world);
			m_sound.setBuffer(Resources::instance().getMusic(explosion1));
			m_sound.play();
			drawFeatur = false;
			return false;
		}
	}
	return true;
}