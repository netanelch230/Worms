#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
#include <box2d/box2d.h>
#include "Enum.h"
//class Sheep;
//class Stinky;
//class Axe;
//class Flik;


struct spriteSetting
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture& picture;
};
    static float PPM = 64.f;                     /////convert to world cords
	static  float MPP = 0.015625f;                //////convert to world cords
class AbsObject
{
public:
	
	AbsObject() {};
	AbsObject(spriteSetting,b2World& world,bool whichtype);
	b2Body* getBody() { return m_body; };
	virtual void draw(sf::RenderWindow& window);
	virtual bool touch(sf::Vector2f location) const;
	//void update(float deltaTime);
	 sf::Vector2f getPosition() const;


protected:
	sf::RectangleShape m_sprite;
	b2Body* m_body;
	float  m_radius;
	 sf::Vector2f m_size;

	 float getRotation() const;

};
