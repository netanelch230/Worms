#pragma once
#include"AbsObject.h"

class DynamicObject:virtual public AbsObject
{
public:
	DynamicObject(spriteSetting sset, b2World& world):AbsObject(sset,world,true) {};
	//~DynamicObject();

private:

};
