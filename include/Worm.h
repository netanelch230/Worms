#pragma once
#include"AnimationObject.h"
#include"Enum.h"
#include"Resources.h"


class Worm: public AnimationObject
{
public:
	Worm(sf::Vector2f& location, std::string name, sf::Color color, b2World& world);
	virtual void draw(sf::RenderWindow& window);
	void move(float time);
	void takeOffPoints();
	//~Worm();

private:
	bool health = true;
	int m_life= NumOfLife;
	sf::Text m_name;
	sf::RectangleShape m_textBox;

	b2Vec2 forc();
	
};

