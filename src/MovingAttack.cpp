#include "MovingAttack.h"
#include "Worm.h"

void MovingAttack::moveWeapone()
{
	if (m_timeMoving.getElapsedTime().asSeconds() >= 1)
	{
		update();
		m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
		m_timeMoving.restart();
	}
}

//get the direction to move the weapon
b2Vec2 MovingAttack::force()
{
	if (m_sprite.getScale() == featureRight)
		return m_rightForce;
	else if (m_sprite.getScale() == featureLeft)
		return m_leftForce;
	else
		return b2Vec2{ 0,0 };
	
}

//if the attack weapon get stack in some thing
void MovingAttack::changeDirection()
{
	if (m_sprite.getScale() == LEFT)
		m_sprite.setScale(RIGHT);
	else if (m_sprite.getScale() == RIGHT)
		m_sprite.setScale(LEFT);
}

