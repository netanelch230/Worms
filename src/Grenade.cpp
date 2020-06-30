#include "Grenade.h"


Grenade::Grenade(b2World& world, sf::Vector2f position):
		MovingAttack(world, 
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(grenade) },
			AnimationSet{ animation_grenade,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount,1, { 250.f, 250.f }, { -250.f, 250.f })
{
    m_body->SetFixedRotation(false);
}
//54*36
void Grenade::play()
{
	
}

bool Grenade::runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, const sf::Vector2f& wormPosition)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Space)
		{
			drawFeatur = true;
			setPosition(wormPosition);
			m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
			m_timer.restart();
		}
		break;
	}
	if (drawFeatur)
	{
		if (m_second > 0)
		{
			float time = m_timer.getElapsedTime().asSeconds();
			if (time >= 1)
			{
				m_second--;
				m_timer.restart();
			}
		}
		else {
			auto world = getBody()->GetWorld();
			featureExplosion(*world);
			drawFeatur = false;
			return false;
		}
	}
	return true;
}