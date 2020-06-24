#include"AnimationObject.h"

AnimationObject::AnimationObject(spriteSetting sset, sf::Vector2u imageCount,
	b2World& world,bool whichtype, int distance) :
	m_animation(&sset.picture, imageCount, 0.03f,distance), m_row(0),
	AbsObject(sset,world,whichtype)
{
}

void AnimationObject::setAnimation(sf::Texture& photo, sf::Vector2u imageCount, float switchTime, int distance=1)
{
	m_sprite.setTexture(&photo);
	m_sprite.setSize({ 100,100 });
	Animation animation(&photo, imageCount, switchTime, distance);
	m_animation = animation;

}

void AnimationObject::update(float deltaTime)
{
	m_animation.update(m_row, deltaTime);
	m_sprite.setTextureRect(m_animation.getrect());
}