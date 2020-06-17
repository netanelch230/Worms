#include "Worm.h"

void Worm::move(float time)
{
	m_body->ApplyForce(forc(), m_body->GetWorldCenter(), true);
	auto dir = sf::Vector2f{ m_body->GetPosition().x,m_body->GetPosition().y };
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
	auto position = getPosition();
	auto angle = getRotation();
	m_name.setPosition(position + sf::Vector2f{7, -25}); //convert to world cords
	m_name.setRotation(angle);
	m_textBox.setPosition(position + sf::Vector2f{ 7, -25 });   //convert to world cords
	m_textBox.setRotation(angle);
	window.draw(m_textBox);
	window.draw(m_name);
	AbsObject::m_body;
}

