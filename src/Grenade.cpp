#include "Grenade.h"


Grenade::Grenade(b2World& world, sf::Vector2f position):
		Attack(world, 
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(grenade) },
			AnimationSet{ animation_grenade,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount)
{
    m_body->SetFixedRotation(false);
}


void Grenade::applyFeatures(float time)
{
	auto pos = m_body->GetWorldCenter();
		if (m_sprite.getScale() == LEFT)
			m_body->ApplyForce({ 250.f, 250.f }, pos, true);
		else if(m_sprite.getScale() == RIGHT)
			m_body->ApplyForce({ -250.f, 250.f }, pos, true);
}

void Grenade::play()
{
	m_bomb.restart();
	int second=3;
	while (second > 0)
	{
		float time = m_bomb.getElapsedTime().asSeconds();
		if (time >= 1)
		{
			second--;
			m_bomb.restart();
		}
	}
	setAnimation(AnimationSet{ exGrenade,exGrenadeImageCount,false,1 }, 0.03f);
}
