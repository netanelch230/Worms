#include "Worm.h"


void Worm::move(float time)
{
	m_body->ApplyForce(forc(), m_body->GetWorldCenter(), true);
	//auto dir = calculateDirection(time, direction());
	auto dir = sf::Vector2f{ m_body->GetPosition().x,m_body->GetPosition().y };
	//m_sprite.move(dir);;
	//b2Vec2 i = { m_sprite.getPosition().x,m_sprite.getPosition().y };
	//m_body->SetTransform(i, m_body->GetAngle());
}
b2Vec2 Worm::forc()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return b2Vec2{ 5,0 };

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return b2Vec2{ -5,0 };

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return b2Vec2{ 0,-5 };

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return b2Vec2{ 0,5 };

	else
		return b2Vec2{ 0,0 };
}
int Worm::direction()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return right;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return left;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return jump;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return down;
	
	else
		return stand;
}

sf::Vector2f Worm::calculateDirection(const float& deltaTime, const int& num)
{
	float speed = 200.f;
	switch (num)
	{
	case jump:
		return sf::Vector2f(0, 0);				//need to calculate
		break;
	case down:
		return sf::Vector2f(0, speed * deltaTime);
		break;
	case left:
		return sf::Vector2f(-speed * deltaTime, 0);
		break;
	case right:
		return sf::Vector2f(speed * deltaTime, 0);
	case stand:
		return { 0,0 };
		break;
	}
}

Worm::Worm(sf::Vector2f& location, std::string name, sf::Color color,  b2World& world) :
	AnimationObject(spriteSetting{ location,sizeOfWorm,
			Resources::instance().getAnimations(worm) }, sf::Vector2u{ 1,36 },world,true)
{
	m_name.setFont(Resources::instance().getfont(name_font));
	m_name.setString(name+'\n'+"   "+std::to_string(m_life));
	m_name.setFillColor(color);
	m_name.setPosition(location + sf::Vector2f{ 30, -15 });
	m_name.setScale(0.5, 0.5);
	m_name.setStyle(sf::Text::Bold);
	m_textBox.setPosition(m_name.getPosition());
	m_textBox.setFillColor(sf::Color::Black);
	m_textBox.setOutlineColor(sf::Color::White);
	m_textBox.setOutlineThickness(2);
	m_textBox.setSize({ 40,40 });
}

void Worm::draw(sf::RenderWindow& window)
{
	AnimationObject::draw(window);
	float angle = m_body->GetAngle();
	b2Vec2 position = m_body->GetPosition();
	m_name.setPosition(position.x * PPM, position.y * PPM); //convert to world cords
	m_name.setRotation((angle * 180.f) / 3.14);
	m_textBox.setPosition(position.x * PPM, position.y * PPM);   //convert to world cords
	m_textBox.setRotation((angle * 180.f) / 3.14);
	window.draw(m_textBox);
	window.draw(m_name);
}

