#pragma once
#include <Box2D/Box2D.h>
class MyContactListener:public b2ContactListener
{
public:
	
	MyContactListener();
	~MyContactListener();
	void BeginContact(b2Contact* contact);



};
