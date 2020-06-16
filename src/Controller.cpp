#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	if (m_menu.run(m_window))
	{
		restartBackground();
		restartPlayers();
		restartFeaturesMenu();
		restartFeaturesLocation();
	}
}

void Controller::restartFeaturesMenu()
{
	m_featuresMenu.setTexture(&Resources::instance().getTexture(featuresMenu));
	m_featuresMenu.setSize(featuresCoordinates);
	m_featuresMenu.setPosition({ 984, 0 });
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
			i->run(m_window,m_event,m_player, m_featuresMenu);
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
		auto i = std::make_unique<Player>(name[j], m_menu.getInput().m_playersColor[j],
			m_menu.getInput().m_background);
		it.swap(i);
		j++;
	}
}

void Controller::restartFeaturesLocation()
{
	m_featuresLocation.resize(rowsInTable * colsInTable);
	int j = 0;// the rows of the table
	for (auto i = 0; i < rowsInTable * colsInTable; i++)
	{
		std::cout <<"j:" << j << std::endl;
		std::cout <<"i:" << i << std::endl;
		m_featuresLocation[i].x = 984 + (i % colsInTable) * squareSize;
		m_featuresLocation[i].y = j * squareSize;
		if (i % colsInTable == 0)
		{
			j++;
			std::cout << j << std::endl;
		}
	}

	for (auto i = 0; i < m_featuresLocation.size(); i++)
	{
		std::cout << m_featuresLocation[i].x << " " << m_featuresLocation[i].y << std::endl;
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



void Controller::noaTheQueen()
{
	
}
