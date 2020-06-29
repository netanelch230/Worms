#include "MovingAttack.h"

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
	if (m_sprite.getScale() == RIGHT)
		return m_rightForce;
	else if (m_sprite.getScale() == LEFT)
		return m_leftForce;
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

void MovingAttack::featureExplosion(b2World& world)
{
	m_body->SetType(b2_staticBody);
	float blastRadius = 10.f;
	float  blastPower = 10.f;
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

		if ((bodyCom - center).Length() >= blastRadius)
			continue;

		applyBlastImpulse(body, center, bodyCom, blastPower);
	}

}

void MovingAttack::applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower)
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
