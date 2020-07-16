#include"AnimationObject.h"
//--------------------------------------------------------------

AnimationObject::AnimationObject(spriteSetting sset, sf::Vector2u imageCount,
	b2World& world,bool whichtype, int distance, float switchTime) :
	m_animation(&sset.picture, imageCount, switchTime, distance), m_row(0),
	AbsObject(sset,world,whichtype){}

//--------------------------------------------------------------
//set the animation pic of the object
void AnimationObject::setAnimation(AnimationSet animset, float switchTime)
{
	m_sprite.setTexture(image(animset.photo));
	Animation animation(&image(animset.photo),
		animset.imageCount, switchTime, animset.distance, animset.restart);
	m_animation = animation;

	m_numOfPicture = animset.photo;
}

void AnimationObject::update(float deltaTime)
{
	m_animation.update(m_row, deltaTime);
	m_sprite.setTextureRect(m_animation.getrect());
	m_endOfAnimation = m_animation.isDead();
}

void AnimationObject::setPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void AnimationObject::destroy()
{
	
}
