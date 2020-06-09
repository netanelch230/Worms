#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	restartBackground();
	restartPlayers();
	m_menu.setResources(m_resources.getfont(menu_font), m_resources.getTexture(menuPic),
		m_resources.getTexture(menuHeadline), m_resources.getPlayersTextures());
	m_menu.run(m_window);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_background);
		m_window.display();
		for (; m_window.pollEvent(m_event); )
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
				m_event.type == sf::Event::Closed)
			{
				m_window.close();
				break;
			}
		}
		for (auto& i : m_player)
			i->run(m_window, m_event);
	}
}

void Controller::restartPlayers()
{
	/*
	int numOfPlayer = m_menu.getInput().m_numOfPlayers;
	int j = 0;
	//auto name = m_menu.getInput().m_playerName;
	m_player.resize(numOfPlayer);
	for (auto& it : m_player)
	{
		//float widthRatio = 1200 / numOfPlayer;
		//float heightRatio = 700 / numOfPlayer;
		//auto i = std::make_unique<Player>("noa",sf::Vector2f{ (float)widthRatio * j,heightRatio },
			//m_menu.getColor(m_menu.getInput().m_color));
		//it.swap(i);
		//j++;
	}
	*/
}

void Controller::restartBackground()
{
	m_background.setTexture(&(m_resources.getTexture(m_menu.getInput().m_background)));
	m_background.setSize({ 1200,700 });
}
