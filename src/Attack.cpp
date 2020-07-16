#include "Attack.h"


bool Attack::destroy(int time)
{
	if (m_endOfAnimation || time == timeOfRound)
	{
		m_body->GetWorld()->DestroyBody(m_body);
		return true;
	}
	return false;
}

void Attack::featureExplosion(b2World& world)
{

	m_body->SetType(b2_staticBody);
	float blastRadius = 2.f;
	float  blastPower = 4.f;
	auto center = getBody()->GetWorldCenter();
	//find all bodies with fixtures in blast radius AABB
	MyQueryCallback queryCallback; //see "World querying topic"
	b2AABB aabb;
	aabb.lowerBound = center - b2Vec2(blastRadius, blastRadius);
	aabb.upperBound = center + b2Vec2(blastRadius, blastRadius);
    world.QueryAABB(&queryCallback, aabb);

		
	
	//check which of these bodies have their center of mass within the blast radius
	for (auto i : queryCallback.getFoundBodies())
	{
		b2Body* body = i;
		b2Vec2 bodyCom = body->GetWorldCenter();	
		auto data = i->GetUserData();

		blastPoint(data);

		if ((bodyCom - center).Length() >= blastRadius)
			continue;

		applyBlastImpulse(body, center, bodyCom, blastPower);

	}
}



void Attack::update()
{
	float time = m_timeAnimation.restart().asSeconds();
	AnimationObject::update(time);
}

bool Attack::bombAnimationFeature()
{
	return isDead();
}

void Attack::blastPoint(void* data)
{
	if (auto k = static_cast<AbsObject*> (data))
		if (auto z = dynamic_cast<Worm*>(k))
		{
			attackTakeOfPoints(*z);
		}
}

void Attack::applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower)
{
	b2Vec2 blastDir = applyPoint - blastCenter;
	float distance = blastDir.Normalize();
	//ignore bodies exactly at the blast point - blast direction is undefined
	if (distance == 0)
		return;
	float invDistance = 1 / distance;
	float impulseMag = blastPower * invDistance * invDistance;
	body->ApplyLinearImpulse(impulseMag * blastDir, applyPoint, true);
}

void Attack::endBomb()
{
	m_body->GetWorld()->DestroyBody(m_body);
}