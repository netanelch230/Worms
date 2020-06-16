#pragma once
#include"AbsObject.h"

class AnimationObject:public AbsObject
{
public:
	AnimationObject(spriteSetting sset, sf::Vector2u imageCount, b2World& world,bool whichtype);
	//~AnimationObject();
	void update(float deltaTime);

protected:
	Animation m_animation;
	unsigned int m_row;

};
