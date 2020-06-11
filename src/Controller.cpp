#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	m_menu.setResources(m_resources.getfont(menu_font), m_resources.getMenuTexture(menuPic),
		m_resources.getMenuTexture(menuHeadline), m_resources.getPlayersTextures(), m_resources.getMenuTexture(playWithFriendsPic),
		m_resources.getMenuTexture(playWithComputerPic), m_resources.getMenuTexture(backGround1pic),
		m_resources.getMenuTexture(backGround2pic),m_resources.getMenuTexture(statPlay));

	if (m_menu.run(m_window))
	{
		restartBackground();
		restartPlayers();
		restartFeature();
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
		auto i = std::make_unique<Player>(name[j], m_menu.getInput().m_playersColor[j],m_resources.getAnimations());
		it.swap(i);
		j++;
	}
}

void Controller::restartBackground()   
{
	m_background.setTexture(&m_resources.getMenuTexture(m_menu.getInput().m_background));
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

