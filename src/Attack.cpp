#include"Attack.h"

void Attack::explode()
{
	m_body->GetWorld()->DestroyBody(m_body);
}
