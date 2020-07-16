#pragma once
#include"AnimationObject.h"
#include"Enum.h"
#include"Resource.h"

//--------class---------
class Worm: public AnimationObject
{
public:
	Worm(sf::Vector2f& location, std::string name, sf::Color color, b2World& world);
	virtual void draw(sf::RenderWindow& window);
	void move();
	void setSprite(float x, float y);
	void takeOffPoints(int i);
	bool stand();
	virtual void destroy() override {};
	void setHelth() { m_health = false; }
	void checkHealth();
	void setVelocity(float mul) { velocity = mul; };
	sf::Vector2f getScale();
	void initializeWormSpriteSetting(sf::Vector2f size, sf::Texture& pic);
	void setRegularAnimation();
	std::string getGroupName() { return m_name_string; }
	int getLife();
	void update(float time);
	int getNumOfPicture();
	void setStandOrigin();
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
	sf::Sound m_wormCoughe;
	float velocity = 1;
	
};

b2Vec2 operator*(b2Vec2 v1, float i);
