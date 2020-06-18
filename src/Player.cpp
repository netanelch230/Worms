#include "Player.h"
#include <iostream>

Player::Player(std::string name, sf::Color color, int background, std::shared_ptr<b2World> world):
	m_name(name),m_color(color),m_world(world)
{
	creatWorms();
	loadTimer();
	restartBackground(backGround1pic);
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
			if (sf::Keyboard::isKeyPressed)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					case sf::Keyboard::Space:
						//in here netanel, karin and yair needs to handle box-2d
						break;
					break;

				}
			}
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
		drawBoardAndAnimation(window, groupPlayers, featuresMenu, m_staticObject);
		if (m_drawWeaponMenu)
				chooseWeapon(window, featuresMenu, featuresLocation, place, groupPlayers,
					m_staticObject);
	}	
	//set current worm to regular worm because turn is over!
	m_worms[place]->setAnimation(Resources::instance().getTexture(f_worm), wormImageCount, 0.03f);
	//m_timeForRound.setString("10");
	//Timer::setTime(timeOfRound);

}

void Player::drawBoardAndAnimation(sf::RenderWindow& window, std::vector<std::unique_ptr<Player>>& groupPlayers, sf::RectangleShape& featuresMenu,
	staticObjVec& m_staticObject)
{
	window.clear();
	m_world->Step(TIMESTEP, VELITER, POSITER);
	window.draw(m_background);
	if (m_drawWeaponMenu)
		window.draw(featuresMenu);
	for (auto& i : m_staticObject)
		i->draw(window);

	window.draw(m_timeForRound);

	for (auto& group : groupPlayers)
	{
		group->update();
		group->draw(window);
	}
	window.display();
}
void Player::draw(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
		i->draw(window);
}


void Player::chooseWeapon(sf::RenderWindow& window, sf::RectangleShape& featuresMenu,
	std::vector<sf::Vector2f> featuresLocation, int currWorm,
	std::vector<std::unique_ptr<Player>>& groupPlayers, staticObjVec& m_staticObject)
{
		while (m_drawWeaponMenu && !timesUp()) // while we still want to use the weapon Menu
		{
			drawBoardAndAnimation(window, groupPlayers, featuresMenu, m_staticObject);
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
						auto featureToCreate = checkClick(location, featuresLocation);
						handleFeatureChoosing(featureToCreate, currWorm, window);
						m_drawWeaponMenu = false;
						break;
					}
				}
			}
		}
}

void Player::handleFeatureChoosing(animationData featureToCreate, int currWorm, sf::RenderWindow& window)
{
	if (featureToCreate.first == -1)
		return;
	m_worms[currWorm]->setAnimation(Resources::instance().getTexture(featureToCreate.first),
		featureToCreate.second, 0.03f);
	handleCollision(featureToCreate.first, window);
}

animationData Player::checkClick(sf::Vector2f clickLocation, std::vector<sf::Vector2f> featuresLocation)
{
	int currLocationModuluRows = 0;
	for (auto i = featuresLocation.begin(); i != featuresLocation.end(); ++i)
	{
		if (abs(clickLocation.x - i->x) < squareSize && abs(clickLocation.y - i->y) < squareSize)
		{
			return getFeaturesName(std::distance(featuresLocation.begin(), i)+16);
		}
	}
	return { -1,{0,0} };
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

void Player::handleCollision(int wep,sf::RenderWindow& window)
{
	switch (wep)
	{
	case f_sheep:
		break;
	case f_grenade:
		break;
	case f_flick:
		break;
	case f_axe:
		//figure the player who werw attacked and change his life to helf
		break;
	case f_teleporter:
	{
		handleTeleporter(window);
		break;
	}
	case f_whiteFlag:
		handleWhiteFlag(window);
		//flag to all worms and dissapered
		break;
	case f_stinky:
		// all worms from other group that in area became sick and lose 5 life any turn
		break;
	case f_skip:
	{
		handleSkip(window);
		//wait for press and end the section
		break;
	}
	}
}

void Player::handleWhiteFlag(sf::RenderWindow &window)
{
	for (auto& i : m_worms)
	{
		i->setAnimation(Resources::instance().getTexture(f_whiteFlag), whiteFlagImageCount, 0.03f);
	}
}

void Player::handleSkip(sf::RenderWindow & window)
{
	while(m_roundTimer.getElapsedTime().asSeconds() > 1.f)
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
				case sf::Keyboard::Space:
					break;
					break;
				}
			}
		}
	}
}


void Player::handleTeleporter(sf::RenderWindow& window)
{
	while (true)
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto location = locatin(window, event); //will return where pressed
					//we need to use box-2d here with the location we got!
				}
				break;
			}
		}
	}
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
		{
			return true;
		}
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

animationData Player::getFeaturesName(int index)
{
	switch (index)
	{
	case f_sheep:
		return {f_sheep,sheepImageCount};
	case f_grenade:
		return { f_grenade,GreenGrenadeImageCount };
	case f_flick:
		return { f_flick,flickImageCount };
	case f_axe:
		return { f_axe,axeImageCount };
	case f_teleporter:
		return { f_teleporter,teleporterImageCount };
	case f_whiteFlag:
		return { f_whiteFlag,whiteFlagImageCount };
	case f_stinky:
		return { f_stinky,stinkyImageCount };
	case f_skip:
		return { f_skip,skipImageCount };
	}
}