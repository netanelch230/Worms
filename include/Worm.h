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
	void takeOffPoints(int i);
	virtual void destroy() override;
	void setHelth() { m_health = false; }
	void checkHealth();
	sf::Vector2f getScale();
	~Worm()= default;

private:
	bool m_health = true;
	int m_life= NumOfLife;
	sf::Text m_name;
	sf::RectangleShape m_textBox;
	sf::Vector2f getCurrentMove();
	b2Vec2 forc();
	std::string m_name_string;
	sf::Sound m_wormUp;
	sf::Sound m_wormWalk;
};

