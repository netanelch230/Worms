
#include "AbsObject.h"

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
    
    polygonShape.SetAsBox( sset.size.x/2 * MPP, sset.size.y/2 * MPP);
        
    fixtureDef.shape = &polygonShape;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution	= 0.3f;
    fixtureDef.density	= 0.7f;

    m_body->CreateFixture(&fixtureDef);

	m_sprite.setTexture(&sset.picture);
	m_sprite.setSize(sset.size);


}

void AbsObject::draw(sf::RenderWindow& window)
{

    float angle = m_body->GetAngle();
    b2Vec2 position = m_body->GetPosition();
   m_sprite.setPosition(position.x * PPM, position.y * PPM);
   m_sprite.setRotation((angle * 180.f) / 3.14);

    window.draw(m_sprite);
}

bool AbsObject::touch(sf::Vector2f location)
{
	return m_sprite.getGlobalBounds().contains(location);
}

