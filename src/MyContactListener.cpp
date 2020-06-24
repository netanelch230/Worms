#include "MyContactListener.h"
#include "AbsObject.h"
#include"CollisionHandling.h"

MyContactListener::MyContactListener()
{
}


MyContactListener::~MyContactListener()
{
}

void MyContactListener::BeginContact(b2Contact* contact)
{
	// Starts listening for body collisions
	AbsObject* objectA = static_cast<AbsObject*> (contact->GetFixtureA()->GetBody()->GetUserData());
	AbsObject* objectB = static_cast<AbsObject*> (contact->GetFixtureB()->GetBody()->GetUserData());
	
	if (objectA != nullptr && objectB != nullptr)
	{
		processCollision(objectA, objectB);
	}
}
