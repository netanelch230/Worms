#pragma once
#include"AbsObject.h"
#include"AnimationSet.h"

//--------------class--------------
class AnimationObject:public AbsObject
{
public:
	AnimationObject(spriteSetting sset, sf::Vector2u imageCount, b2World& world,
		bool whichtype, int distance = 0, float switchTime = 0.03f);
	AnimationObject()= default;
	 virtual void destroy();
	void setAnimation(AnimationSet animset,float switchTime);
	bool isDead() { return m_endOfAnimation; };
	void update(float deltaTime);
	void setPosition(sf::Vector2f position);
	virtual ~AnimationObject()= default;

protected:
	Animation m_animation;
	unsigned int m_row;
	bool m_endOfAnimation = false;//default value 
	int m_numOfPicture = -1;
};
