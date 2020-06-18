#include "Player.h"
#include <iostream>

const int distanceSize = 16;
Player::Player(std::string name, sf::Color color, int background, std::shared_ptr<b2World> world) :
	m_name(name), m_color(color), m_world(world)
{
	creatWorms();
	loadTimer();
	restartBackground(backGround1pic);
}

void Player::run(sf::RenderWindow& window,
	sf::Event& event,
	std::vector<std::unique_ptr<Player>>& groupPlayers,
	sf::RectangleShape& featuresMenu,
	staticObjVec& m_staticObject,
	std::vector<sf::Vector2f> featuresLocation)
{
	Timer::setTime(timeOfRound);
	int place = rand() % wormsLimit;
	while (!timesUp())
	{
		if (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed)
			{
				switch (event.type)
				{
				case sf::Event::MouseButtonPressed:
				case sf::Mouse::Button::Right:
					m_drawWeaponMenu = true;
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
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
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					m_drawWeaponMenu = false;
					break;
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto location = locatin(window, event); //will return where pressed on board
					auto featureToCreate = checkClick(location, featuresLocation, currWorm);
					auto place = featureToCreate->getPlace();
					auto imageCount = featureToCreate->getImageCount();
					m_worms[currWorm]->setAnimation(Resources::instance().getTexture(place),
						imageCount, 0.03f);
					if (auto i = std::dynamic_pointer_cast<Attack>(featureToCreate))
					{
						i->foo();
					}

					m_drawWeaponMenu = false;
					break;
				}
			}
		}
	}
}

std::shared_ptr<Features> Player::checkClick(sf::Vector2f clickLocation,
	std::vector<sf::Vector2f> featuresLocation, int currWorm)
{
	int currLocationModuluRows = 0;
	for (auto i = featuresLocation.begin(); i != featuresLocation.end(); ++i)
	{
		if (abs(clickLocation.x - i->x) < squareSize && abs(clickLocation.y - i->y) < squareSize)
		{
			return getFeaturesName(std::distance(featuresLocation.begin(), i) + distanceSize, currWorm);
		}
	}
	return NULL;
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
		auto loc = randomLocation(HEIGHT, WIDTH);
		auto i = std::make_unique<Worm>(loc, m_name, m_color, *m_world.get());
		it.swap(i);
	}
}

void Player::restartBackground(int i)
{
	m_background.setTexture(&Resources::instance().getTexture(i));
	m_background.setSize({ WIDTH,HEIGHT });

}

std::shared_ptr<Features> Player::getFeaturesName(int index, int current)
{
	auto wormPosition = m_worms[current]->getBody()->GetPosition();

	switch (index)
	{
	case f_sheep:
	{
		std::shared_ptr<Features> p = std::make_shared<Sheep>(m_world, wormPosition);
		return p;
	}
	//case f_grenade:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Grenade>(m_world, wormPosition);
	//	return p;
	//}

	//case f_flick:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Flick>(m_world, wormPosition);
	//	return p;
	//}

	//case f_axe:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Axe>(m_world, wormPosition);
	//	return p;
	//}

	//case f_teleporter:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Transform>();
	//	return p;
	//}

	///*case f_whiteFlag:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<WhiteFlag>();
	//	return p;
	//}*/

	//case f_stinky:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Stinky>(m_world, wormPosition);
	//	return p;
	//}

	//case f_skip:
	//{
	//	std::shared_ptr<Features> p = std::make_shared<Pass>();
	//	return p;
	//}

	
}