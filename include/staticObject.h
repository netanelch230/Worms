# pragma once
#include "AbsObject.h"

class staticObject:public AbsObject 
{
public:
	staticObject(spriteSetting sset, b2World& world) :AbsObject(sset, world, false) {};
	//~staticObject();

private:

};
