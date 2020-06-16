#include "Player.h"
#include <iostream>

Player::Player(std::string name, sf::Color color, int background):
	m_name(name),m_color(color)
{
	creatWorms();
	loadTimer();
	restartBackground(background);
}

void Player::run(sf::RenderWindow& window, sf::Event& event)
{
	Timer::setTime(timeOfRound);
	int place =	rand() % wormsLimit;
	while (!timesUp())
	{
		for (; window.pollEvent(event); )
		{
			switch (sf::Event::MouseButtonReleased)
			{
			case (sf::Mouse::Button::Left):
				chooseWorm(window, event, place);
				break;
			case (sf::Mouse::Button::Right)://weapons menu
				chooseWeapone(window, event);
				break;
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}
		update();
		wormMove(place);
		window.clear();
		window.draw(m_background);
		draw(window);
		window.display();
	}
	
}

void Player::draw(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
		i->draw(window);
	window.draw(m_timeForRound);
}

void Player::chooseWeapone(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.MouseButtonPressed)
	{
	case(sf::Mouse::Button::Left):
		auto location = locatin(window, event);
		for (auto& i : m_features)
			if(i->touch(location))
				//the player choose this weapon, do someting.				
		break;
	}
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
	std::cout << i;
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

sf::Vector2f Player::randomLocation()
{
	float randPlaceX = rand() % HEIGHT;
	float randPlaceY = rand() % WIDTH;
	 
	return sf::Vector2f{ randPlaceX, randPlaceY };
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
		auto loc = randomLocation();
		auto i = std::make_unique<Worm>(loc, m_name, m_color);
		it.swap(i);
	}
}

void Player::restartBackground(int i)
{
	m_background.setTexture(&Resources::instance().getMenuTexture(i));
	m_background.setSize({ WIDTH,HEIGHT });

}

