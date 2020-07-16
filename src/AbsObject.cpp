#include "AbsObject.h"
#include <iostream>


AbsObject::AbsObject(spriteSetting sset,b2World& world,bool whichtype)
{    
    // Create body static box2D
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef; 
    b2BodyDef bodyDef;
    if(whichtype)
        bodyDef.type = b2_dynamicBody;
    else
       bodyDef.type = b2_staticBody;
       
    bodyDef.position.Set(sset.position.x * MPP, sset.position.y * MPP);
    m_body = world.CreateBody(&bodyDef);
    m_body->SetFixedRotation(true);
    polygonShape.SetAsBox( sset.size.x/2 * MPP, sset.size.y/2 * MPP); 

    fixtureDef.shape = &polygonShape;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution	= 0.4f; 
    fixtureDef.density	= 1.f;

    m_body->CreateFixture(&fixtureDef);
	m_body->SetUserData(this);
	m_sprite.setTexture(sset.picture);
    m_sprite.setOrigin(sset.size.x/2, sset.size.y / 2);
}

void AbsObject::draw(sf::RenderWindow& window)
{
    m_sprite.setPosition(getPosition());
    m_sprite.setRotation(getRotation());
    window.draw(m_sprite);
}

sf::Vector2f AbsObject::getPosition() const
{
    b2Vec2 position = m_body->GetPosition();
    return sf::Vector2f(position.x * PPM, position.y * PPM);
}

float AbsObject::getRotation() const
{
    float angle = m_body->GetAngle();
    return float ((angle * 180.f) / 3.14f);
}