#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
#include <box2d/box2d.h>
#include "Enum.h"


struct spriteSetting
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& picture;
};

//--------------class--------------
class AbsObject
{
public:
    AbsObject() = default;
    AbsObject(spriteSetting, b2World& world, bool whichtype);
    virtual void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    b2Body* getBody() { return m_body; }
    virtual ~AbsObject() = default;

protected:
    sf::Sprite m_sprite;
    b2Body* m_body;
    float getRotation() const;

private:
    float  m_radius;
    sf::Vector2f m_size;

};
