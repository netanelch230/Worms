#include "Player.h"
#include <iostream>

Player::Player(std::string name, sf::Color color, int background, std::shared_ptr<b2World> world):
	m_name(name),m_color(color),m_world(world)
{
	creatWorms();
	loadTimer();
	restartBackground(0);
}

void Player::run(sf::RenderWindow& window,
	sf::Event& event,
	std::vector<std::unique_ptr<Player>> &groupPlayers,
	sf::RectangleShape& featuresMenu,
	staticObjVec& m_staticObject,
	std::vector<sf::Vector2f> featuresLocation)
{
	Timer::setTime(timeOfRound);
	int place =	rand() % wormsLimit;
	while (!timesUp())
	{
		if (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed)
			{
				if (sf::Mouse::Button::Right) //weapons menu
					chooseWeapon(window, featuresMenu,featuresLocation,place);

				if (sf::Mouse::Button::Left)
					chooseWorm(window, event, place);
			}
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}
		wormMove(place);
		window.clear();
		
		 m_world->Step(TIMESTEP, VELITER, POSITER);
		 window.draw(m_background);
		for (auto& i : m_staticObject)
			i->draw(window);

		for (auto& group : groupPlayers) {
			group->update();
			group->draw(window);
		}
		if (m_drawWeaponMenu)
			chooseWeapon(window, featuresMenu, featuresLocation, place);
		else
			window.display();
	}
	
}

void Player::draw(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
		i->draw(window);
	window.draw(m_timeForRound);
}


void Player::chooseWeapon(sf::RenderWindow& window, sf::RectangleShape& featuresMenu,
	std::vector<sf::Vector2f> featuresLocation, int currWorm)
{
	window.draw(featuresMenu);//now after choosing weapon we'll check which weapon the worm chose
	window.display();
	while (m_drawWeaponMenu) // while we still want to use the weapon Menu
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "in pressed button";
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					m_drawWeaponMenu = false;
					break;
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "in left click!!!!";
					auto location = locatin(window, event); //will return where pressed on board
					int featureToCreate = checkClick(location, featuresLocation);
					//m_worms[currWorm]->setAnimation(&Resources::instance().getAnimations(featureToCreate), );
					m_drawWeaponMenu = false;
					break;
				}
			}
		}
	}	
}
int Player::checkClick(sf::Vector2f clickLocation, std::vector<sf::Vector2f> featuresLocation)
{
	int currLocationModuluRows = 0;
	for (auto i = featuresLocation.begin(); i != featuresLocation.end(); ++i)
	{
		if (abs(clickLocation.x - i->x) < squareSize && abs(clickLocation.y - i->y) < squareSize)
		{
			return getFeatureName(std::distance(featuresLocation.begin(), i));
		}
	}

	return -1;
}

void Player::chooseWorm(sf::RenderWindow& window, sf::Event& event, int& place)
{
	auto location = locatin(window, event);
	int j = 0;
	for (auto& i : m_worms)
	{
		if (i->touch(location))
		{
			place = j;
			break;
		}
		j++;
	}
}

void Player::wormMove(int i)
{
	float time = m_wormsTime.restart().asSeconds();
	m_worms[i]->move(time);
}

sf::Vector2f Player::locatin(sf::RenderWindow& window, sf::Event& event)
{
	return window.mapPixelToCoords(
		{ event.mouseButton.x, event.mouseButton.y });
}

void Player::update()
{
	float time = m_wormsTimeAnimation.restart().asSeconds();
	for (auto& i : m_worms)
		i->update(time);
}



bool Player::timesUp()
{
	if (Timer::getTime() != -1)
	{
		if (m_roundTimer.getElapsedTime().asSeconds() >= 1.f)
		{
			Timer::decTime();
			m_roundTimer.restart();
			m_timeForRound.setString(std::to_string(Timer::getTime()));
		}
		if (Timer::getTime() == 0)
			return true;
	}
	return false;
}

void Player::loadTimer()
{
	m_timeForRound.setFont(Resources::instance().getfont(font::name_font));
	m_timeForRound.setColor(sf::Color::Yellow);
	m_timeForRound.setPosition(50, 650);
	m_timeForRound.setCharacterSize(20);
	m_roundTimer.restart();
}

void Player::creatWorms()
{
	m_worms.resize(wormsLimit);
	for (auto& it : m_worms)
	{
		auto loc = randomLocation(HEIGHT,WIDTH);
		auto i = std::make_unique<Worm>(loc, m_name, m_color,*m_world.get());
		it.swap(i);
	}
}

void Player::restartBackground(int i)
{
	m_background.setTexture(&Resources::instance().getTexture(i));
	m_background.setSize({ WIDTH,HEIGHT });

}

int Player::getFeatureName(int index)
{
	switch (index)
	{
	case f_sheep:
		return f_sheep;
	case f_grenade:
		return f_grenade;
	case f_flick:
		return f_flick;
	case f_axe:
		return f_axe;
	case f_move:
		return f_move;
	case f_whiteFlag:
		return f_whiteFlag;
	case f_stinky:
		return f_stinky;
	case f_skip:
		return f_skip;
	}
}