#pragma once
#include "staticObject.h"

class Grounde : public staticObject
{
public:
	Grounde(spriteSetting sset, b2World& world):staticObject(sset,world) {};

};