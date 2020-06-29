#include"Attack.h"


bool Attack::destroy(int time)
{
	if (m_is_dead || time == timeOfRound)
	{
		m_body->GetWorld()->DestroyBody(m_body);
		return true;
	}
	return false;
}



void Attack::update()
{
	float time = m_timeAnimation.restart().asSeconds();
	AnimationObject::update(time);
}
