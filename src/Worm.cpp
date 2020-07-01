#include "Worm.h"
#include <iostream>



void Worm::move(float time)
{
	m_body->ApplyForce(forc(), m_body->GetWorldCenter(), true);
	
}

void Worm::takeOffPoints(int i)
{
	m_life -= i;
	m_is_dead = m_life <= 0 ? false : true;

}

void Worm::destroy()
{
	/*if (m_is_dead)
		this->setAnimation(AnimationSet{ animation_die,WormDieImageCount,false,1 }, 0.03f);*/
}

b2Vec2 Worm::forc()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.setScale(RIGHT);
		this->setAnimation({ animation_walk, sf::Vector2u{1,15}, false, 1,sizeOfWalkWorm }, 0.05f);
		return b2Vec2{ 0.1,0 };
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.setScale(LEFT);
		this->setAnimation({ animation_walk, sf::Vector2u{1,15}, false, 1,sizeOfWalkWorm }, 0.05f);
		return b2Vec2{ -0.1,0 };
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return b2Vec2{ 0,-0.1 };

	else
		return b2Vec2{ 0,0 };
}


Worm::Worm(sf::Vector2f& location, std::string name, sf::Color color,  b2World& world) :
	AnimationObject(spriteSetting{ location,sizeOfWorm,
			Resources::instance().getTexture(animation_worm) }, sf::Vector2u{ 1,36 },world,true,1),
	m_name_string(name)
{
	m_name.setFont(Resources::instance().getfont(name_font));
	m_name.setString(m_name_string +'\n'+"   "+std::to_string(m_life));
	m_name.setFillColor(color);
	m_name.setPosition(location + sf::Vector2f{ 10, -15 });
	m_name.setScale(0.5, 0.5);
	m_name.setStyle(sf::Text::Bold);
	
	m_textBox.setPosition(m_name.getPosition());
	m_textBox.setFillColor(sf::Color::Black);
	m_textBox.setOutlineColor(sf::Color::White);
	m_textBox.setOutlineThickness(2);
	const auto rect = m_textBox.getLocalBounds();
	m_textBox.setOrigin(rect.width / 2, rect.height / 2);
	m_textBox.setSize({ rect.width / 2, rect.height / 2 });
}

/*this function will draw each worm on the board and will set it's animatior
and in addition will display the current animation of the board'*/
void Worm::draw(sf::RenderWindow& window)
{
	AnimationObject::draw(window);
	m_name.setString(m_name_string +'\n'+"   "+std::to_string(m_life));
	m_name.setPosition(getPosition() + getCurrentMove()); //convert to world cords
	m_name.setRotation(getRotation());
	m_textBox.setPosition(getPosition() + getCurrentMove());   //convert to world cords
	m_textBox.setRotation(getRotation());
	window.draw(m_textBox);
	window.draw(m_name);
	AbsObject::m_body;
}

sf::Vector2f Worm::getCurrentMove()
{
	if (m_sprite.getScale() == LEFT)
		return wormTextBoxCorLeft;
	else if (m_sprite.getScale() == RIGHT)
		return wormTextBoxCorRight;
	return wormTextBoxCorLeft;
}

void Worm::checkHealth()
{
	if (!m_health)
		takeOffPoints(5);
}

sf::Vector2f Worm::getScale()
{
	return m_sprite.getScale();
}

bool Worm::stand()
{
	return m_body->GetLinearVelocity() == b2Vec2{ 0,0 }
	&& m_numOfPicture == animation_walk;
}
