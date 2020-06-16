#include"AnimationObject.h"

AnimationObject::AnimationObject(spriteSetting sset, sf::Vector2u imageCount,b2World& world,bool whichtype) :
	m_animation(&sset.picture, imageCount, 0.03f), m_row(0),
	AbsObject(sset,world,whichtype)
{
}

void AnimationObject::update(float deltaTime)
{
	m_animation.update(m_row, deltaTime);
	m_sprite.setTextureRect(m_animation.getrect());
}