#include"Attack.h"


void Attack::destroy()
{
	if (m_is_dead)
		m_body->GetWorld()->DestroyBody(m_body);
}



void Attack::update()
{
	float time = m_timeAnimation.restart().asSeconds();
	AnimationObject::update(time);
}
