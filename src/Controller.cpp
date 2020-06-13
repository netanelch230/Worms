#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	if (m_menu.run(m_window))
	{
		restartBackground();
		restartPlayers();
	}
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
		float widthRatio = 300;
		float heightRatio = 400;
		auto i = std::make_unique<Player>(name[j], m_menu.getInput().m_playersColor[j],m_menu.getInput().m_background);
		it.swap(i);
		j++;
	}
}

void Controller::restartBackground()   
{
	m_background.setTexture(&Resources::instance().getMenuTexture(m_menu.getInput().m_background));
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



