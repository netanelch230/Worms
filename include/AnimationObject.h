#pragma once
#include"AbsObject.h"
#include"AnimationSet.h"

class AnimationObject:public AbsObject
{
public:
	AnimationObject(spriteSetting sset, sf::Vector2u imageCount, b2World& world,
		bool whichtype, int distance = 0);
	void setAnimation(AnimationSet animset,float switchTime);
	//~AnimationObject();
	void update(float deltaTime);

protected:
	Animation m_animation;
	unsigned int m_row;

};
