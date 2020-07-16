#include "Worm.h"
#include <iostream>

Worm::Worm(sf::Vector2f& location, std::string name, sf::Color color, b2World& world) :
	AnimationObject(spriteSetting{ location,sizeOfWorm,
			image(animation_worm) }, wormImageCount, world, true, 1),
	m_name_string(name)
{
	m_numOfPicture = animation_worm;
	m_name.setFont(font(name_font));
	m_name.setString(m_name_string + '\n' + "   " + std::to_string(m_life));
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

	m_wormUp.setBuffer(Music(wormjump));
	m_wormWalk.setBuffer(Music(worm_walk1));
	m_wormCoughe.setBuffer(Music(Coughe));
}



//---------------------------
int Worm::getLife()
{
	return m_life;
}

//---------------------------
void Worm::update(float time)
{
	AnimationObject::update(time);
	if (m_life <= 0 && m_endOfAnimation && m_numOfPicture != animation_grave3)
	{
		m_wormCoughe.setBuffer(Music(wormByeBye));
		m_wormCoughe.play();
		setAnimation({ animation_grave3,graveImageCount,true,0 }, 0.03f);
		m_numOfPicture = animation_grave3;
	}
}

//---------------------------

int Worm::getNumOfPicture()
{
	return m_numOfPicture;
}

void Worm::setStandOrigin()
{
	m_sprite.setOrigin(10,10);
}


///------------------------ before
void Worm::move()
{
	m_body->ApplyForce(forc() * velocity, m_body->GetWorldCenter(), true);
}

//---------------------------

void Worm::setSprite(float x, float y)
{
	this->m_sprite.setOrigin(x, y);
}

//---------------------------

void Worm::takeOffPoints(int i)
{
	m_life -= i;
	m_endOfAnimation = m_life < 0 ? true : false;

}

//---------------------------

bool Worm::stand()
{
	return m_body->GetLinearVelocity() == b2Vec2{ 0,0 }
	&& m_numOfPicture == animation_walk && m_life > 0;
}
//---------------------------

b2Vec2 Worm::forc()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_wormWalk.play();
		m_sprite.setScale(RIGHT);
		this->setAnimation({ animation_walk, sf::Vector2u{1,15}, false, 0,sizeOfWalkWorm }, 0.05f);////
		spriteSetting sset{ this->getPosition(), sf::Vector2f{ 20,20 }, image(animation_walk) };
		m_sprite.setOrigin(sset.size.x, sset.size.y + 8);
		m_numOfPicture = animation_walk;
		return b2Vec2{ 0.1,0 };
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_wormWalk.play();
		m_sprite.setScale(LEFT);
		this->setAnimation({ animation_walk, sf::Vector2u{1,15}, false, 0,sizeOfWalkWorm }, 0.05f);////
		spriteSetting sset{ this->getPosition(), sf::Vector2f{ 20,20 }, image(animation_walk) };
		m_sprite.setOrigin(sset.size.x, sset.size.y+8);
		m_numOfPicture = animation_walk;
		return b2Vec2{ -0.1,0 };
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		m_wormUp.play();
		this->setAnimation({ animation_walk, sf::Vector2u{1,15}, false, 0,sizeOfWalkWorm }, 0.05f);////
		spriteSetting sset{ this->getPosition(), sf::Vector2f{ 20,20 }, image(animation_walk) };
		m_sprite.setOrigin(sset.size.x, sset.size.y + 8);
		m_numOfPicture = animation_walk;
		return b2Vec2{ 0.f,-0.2f };
	}

	else
		return b2Vec2{ 0,0 };
}

void Worm::initializeWormSpriteSetting(sf::Vector2f size, sf::Texture& pic)
{
	spriteSetting sset{ this->getPosition(), size, pic };
}

void Worm::setRegularAnimation()
{
	setAnimation({ animation_worm, wormImageCount ,true,1,sizeOfWorm }, 0.05f);
	m_numOfPicture = animation_worm;
}


/*this function will draw each worm on the board and will set it's animatior
and in addition will display the current animation of the board'*/
void Worm::draw(sf::RenderWindow& window)
{
	AnimationObject::draw(window);
	if (m_life > 0)
	{
		m_name.setString(m_name_string + '\n' + "   " + std::to_string(m_life));
		m_name.setPosition(getPosition() + getCurrentMove()); //convert to world cords
		m_name.setRotation(getRotation());
		m_textBox.setPosition(getPosition() + getCurrentMove());   //convert to world cords
		m_textBox.setRotation(getRotation());
		window.draw(m_textBox);
		window.draw(m_name);
	}
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
	if (!m_health && m_life > 0)
	{
		takeOffPoints(5);
		m_wormCoughe.play();
	}
}

sf::Vector2f Worm::getScale()
{
	return m_sprite.getScale();
}

b2Vec2 operator*(b2Vec2 v1, float i)
{
	return b2Vec2{ v1.x * i,v1.y * i };
}
