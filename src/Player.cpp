#include "Player.h"

Player::Player(std::string name, sf::Vector2f location, sf::Color color):
	m_name(name), m_location(location),m_color(color)
{
	m_worms.resize(wormsLimit);
	int j = 0;
	for (auto &it : m_worms)
	{
		auto i = std::make_unique<Worm>(sf::Vector2f{ (float)(location.x + j),(float)location.y});
		it.swap(i);
		j+=10;
	}
}

void Player::run(sf::RenderWindow& window, sf::Event& event)
{
	int place = rand() % wormsLimit;
	for (; window.pollEvent(event); )
	{
		switch (sf::Event::MouseButtonPressed)
		{
		case (sf::Mouse::Button::Left):
			chooseWorm(window, event, place);
			break;
		case (sf::Mouse::Button::Right)://weapons menu
			for (auto& i : m_weapons)
				i->draw(window);
			chooseWeapone(window, event);
			break;
		}
		wormMove(place);
	}
}

void Player::draw(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
		i->draw(window);
}

void Player::chooseWeapone(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.MouseButtonPressed)
	{
	case(sf::Mouse::Button::Left):
		auto location = locatin(window, event);
		for (auto& i : m_weapons)
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
	if (sf::Event::KeyPressed)
	{
		float time = m_wormsTime.restart().asSeconds();
		m_worms[i]->move(time);
	}
}

sf::Vector2f Player::locatin(sf::RenderWindow& window, sf::Event& event)
{
	return window.mapPixelToCoords(
		{ event.mouseButton.x, event.mouseButton.y });
}
