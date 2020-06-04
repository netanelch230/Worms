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
