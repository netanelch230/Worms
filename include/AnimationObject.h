#pragma once
#include"AbsObject.h"

class AnimationObject:public AbsObject
{
public:
	AnimationObject(const spriteSetting& sset, sf::Vector2u imageCount);
	//~AnimationObject();
	void update(float deltaTime);

protected:
	Animation m_animation;
	unsigned int m_row;

};
