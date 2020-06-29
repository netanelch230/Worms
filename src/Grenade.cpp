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
