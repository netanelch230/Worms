#include"AnimationObject.h"

AnimationObject::AnimationObject(spriteSetting sset, sf::Vector2u imageCount) :
	m_animation(&sset.picture, imageCount, 0.03f), m_row(0),
	AbsObject(sset)
{
}

void AnimationObject::update(float deltaTime)
{
	m_animation.update(m_row, deltaTime);
	m_sprite.setTextureRect(m_animation.getrect());
}