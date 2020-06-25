#include"Attack.h"


void Attack::destroy()
{
	if (m_is_dead)
		m_body->GetWorld()->DestroyBody(m_body);
}

b2Vec2 Attack::force(int i)
{
	switch (i)
	{
	case right:
		return b2Vec2{ 0.5,0 };
	case left:
		return b2Vec2{ -0.5,0 };
	}
	return b2Vec2{ 0,0 };
}
