#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	int temp;
	restartBackground();
	restartPlayers();
	restartFeature();
	m_menu.setFont(m_resources.getfont(0));
	m_menu.run(m_resources.getTexture(menuPic), m_window);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_background);
		drawPlayer();
		m_window.display();
		exitGame();
		for (auto& i : m_player)
			i->run(m_window,m_event);
	}

}

void Controller::restartPlayers()   
{
	int numOfPlayer = m_menu.getInput().m_numOfPlayers;
	int j = 0;
	auto name = m_menu.getInput().m_playerName;
	m_player.resize(numOfPlayer);
	for (auto& it : m_player)
	{
		float widthRatio = WIDTH / numOfPlayer;
		float heightRatio = HEIGHT / numOfPlayer;
		auto i = std::make_unique<Player>(name[j],
			sf::Vector2f{ (float)widthRatio * j,heightRatio },
			m_menu.getColor(m_menu.getInput().m_color));
		it.swap(i);
		j++;
	}
}

void Controller::restartBackground()   
{
	m_background.setTexture(&m_resources.getTexture(0));
	m_background.setSize({ WIDTH,HEIGHT });
}

void Controller::drawPlayer()
{
	for (auto& i : m_player)
		i->draw(m_window);
}

void Controller::exitGame()
{
	for (; m_window.pollEvent(m_event); )
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
			m_event.type == sf::Event::Closed)
		{
			m_window.close();
			break;
		}
}

void Controller::restartFeature()
{
	auto startHieght = 100.f;
	auto Width = 1000.f;
	for (auto& i : m_player)
	{
		i->loadFeatures(m_resources.getTexture(flik), { startHieght, Width });
		i->loadFeatures(m_resources.getTexture(grenade), { startHieght+30, Width });
		i->loadFeatures(m_resources.getTexture(pass), { startHieght+60, Width });
		i->loadFeatures(m_resources.getTexture(sheep), { startHieght+90, Width });
		i->loadFeatures(m_resources.getTexture(whiteflag), { startHieght+120, Width });
	}

}

