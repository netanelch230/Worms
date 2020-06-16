#pragma once
#include"AbsObject.h"

class AnimationObject:public AbsObject
{
public:
	AnimationObject(spriteSetting sset, sf::Vector2u imageCount, b2World& world,bool whichtype);
	void setAnimation(sf::Texture &photo, sf::Vector2u imageCount, float switchTime);
	//~AnimationObject();
	void update(float deltaTime);

protected:
	Animation m_animation;
	unsigned int m_row;

};
