#include "Player.h"

Player::Player(std::string name, sf::Color color,animArray animat):
	m_name(name),m_color(color),m_animat(animat)
{
	m_worms.resize(wormsLimit);
	for (auto &it : m_worms)
	{
		auto loc = randomLocation();
		auto i = std::make_unique<Worm>(loc,m_animat[worm]);
		it.swap(i);
	}
}



void Player::run(sf::RenderWindow& window, sf::Event& event)
{
	int place = rand() % wormsLimit;
	for (; window.pollEvent(event); )
	{
		update();
		wormMove(place);

		switch (sf::Event::MouseButtonPressed)
		{
		case (sf::Mouse::Button::Left):
			chooseWorm(window, event, place);
			break;
		case (sf::Mouse::Button::Right)://weapons menu
			for (auto& i : m_features)
				i->draw(window);
			chooseWeapone(window, event);
			break;
		}
		
		draw(window);
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

void Player::update()
{
	float time = m_wormsTime.restart().asSeconds();
	for (auto& i : m_worms)
		i->update(time);
}

sf::Vector2f Player::randomLocation()
{
	float randPlaceX = rand() % HEIGHT;
	float randPlaceY = rand() % WIDTH;
	 
	return sf::Vector2f{ randPlaceX, randPlaceY };
}

void Player::loadFeatures(const sf::Texture& tex, const sf::Vector2f& pos)
{
	//auto i = std::make_unique<Features>(tex, pos);
	//m_features.emplace_back(i);
}

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1+=v2;
}
