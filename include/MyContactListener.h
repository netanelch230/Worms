#pragma once
#include <Box2D/Box2D.h>

//----------class------------
class MyContactListener:public b2ContactListener
{
public:
	
	MyContactListener();
	void BeginContact(b2Contact* contact);
	virtual ~MyContactListener() = default;


};
