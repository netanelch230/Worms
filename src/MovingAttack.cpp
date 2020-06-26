#include "MovingAttack.h"

void MovingAttack::moveWeapone()
{
	auto i = m_body->GetPosition();
	if (m_timeMoving.getElapsedTime().asSeconds() >= 1)
	{
		update();
		m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
		m_timeMoving.restart();
	}
	i = m_body->GetPosition();
}

//get the direction to move the weapon
b2Vec2 MovingAttack::force()
{
	if(m_sprite.getScale() ==RIGHT )
		return b2Vec2{ -0.1,0 };
	else if (m_sprite.getScale() == LEFT)
		return b2Vec2{ 0.1,0 };
	else
	 b2Vec2{ 0,0 };
}

//if the attack weapon get stack in some thing
void MovingAttack::changeDirection()
{
	if (m_sprite.getScale() == LEFT)
		m_sprite.setScale(RIGHT);
	else if (m_sprite.getScale() == RIGHT)
		m_sprite.setScale(LEFT);
}
