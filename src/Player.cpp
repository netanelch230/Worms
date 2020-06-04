#include "Player.h"

Player::Player(std::string name, sf::Vector2f location, sf::Color color):
	m_name(name), m_location(location),m_color(color)
{
	m_worms.resize(wormsLimit);
	int j = 0;
	for (auto &it : m_worms)
	{
		auto i = std::make_unique<Worm>(sf::Vector2f{ (float)(location.x + j),location.y});
		it.swap(i);
		j+=10;
	}
}

void Player::run(sf::RenderWindow& window, sf::Event& event)
{
	
	int place = rand() % wormsLimit;
	for (; window.pollEvent(event); )
	{
		if (sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::Button::Left)
			{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				int j = 0;
				for (auto& i : m_worms)
				{
					if (i->touch(location))
						place = j;
					j++;
				}
			}
			if (sf::Mouse::Button::Left);//weapons menu

		}
		if (sf::Event::KeyPressed)
		{
			float time = m_wormsTime.restart().asSeconds();
			m_worms[place]->move(time);

		}

			

	}
}
