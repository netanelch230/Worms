#include"AnimationObject.h"
//--------------------------------------------------------------

AnimationObject::AnimationObject(spriteSetting sset, sf::Vector2u imageCount,
	b2World& world,bool whichtype, int distance) :
	m_animation(&sset.picture, imageCount, 0.03f,distance), m_row(0),
	AbsObject(sset,world,whichtype)
{
}

void AnimationObject::setAnimation(AnimationSet animset, float switchTime)
{
	m_sprite.setTexture(Resources::instance().getTexture(animset.photo));
	Animation animation(&Resources::instance().getTexture(animset.photo),
		animset.imageCount, switchTime, animset.distance, animset.restart);
	m_animation = animation;
}

void AnimationObject::update(float deltaTime)
{
	m_animation.update(m_row, deltaTime);
	m_sprite.setTextureRect(m_animation.getrect());
	m_is_dead = m_animation.isDead();
}

void AnimationObject::setPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void AnimationObject::destroy()
{
	/*if (!m_is_dead)
		m_body->GetWorld()->DestroyBody(m_body);
	*/
	//m_body->SetGravityScale(10000);
}
