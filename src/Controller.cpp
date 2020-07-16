#include "Controller.h"
#include <iostream>
#include <iterator>


Controller::Controller()
{
	m_startRound.setBuffer(Music(start_round));
	if (m_menu.run(m_window) && m_window.isOpen())
	{
		m_startRound.play();
		defineBoard();
		restartPlayers();
	}
}


void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_board.draw(m_window);
		drawPlayer();
		m_window.display();
		exitGame();
		m_world->SetContactListener(&m_contactListener);
		
		//this will handle the case we'll get white flag- we'll delete the current group.
		for (auto j =0;j<m_players.size();j++)
		{
			m_players[j]->run(m_players);

				if (m_players[j]->getwhiteflag())
				{
					m_players.erase(m_players.begin() + j);
					m_numOfPlayers--;
				}
			for (auto& iter : m_players)
			{
				iter->handleDie();
				if (iter->getDie())
					m_numOfPlayers--;//delete current group.
			}

		
			if (m_numOfPlayers == lastGroup) // this is the last group - winners!! :)
			{
				handleWin();
				return;
			}
		}
	}
}

void Controller::handleWin()
{
	for (auto& player : m_players)
	{
		player->setWinGroup();
		player->setWin();
		player->run(m_players);
	}
	displayWinningGroup();


}
void Controller::displayWinningGroup()
{
	m_window.clear();
	m_endGame.setTexture(image(endGame));
	m_window.draw(m_endGame);
	sf::Text winningPlayer;
	winningPlayer.setFont(font(menu_font));
	winningPlayer.setCharacterSize(50);
	winningPlayer.setFillColor(sf::Color::Black);
	winningPlayer.setStyle(sf::Text::Bold);
	winningPlayer.setOrigin(0, 10);
	winningPlayer.setPosition(500, 260);
	winningPlayer.setString("Winning group is:");
	m_window.draw(winningPlayer);
	winningPlayer.setPosition(570, 360);
	winningPlayer.setString(m_players[startIndex]->getWinningGroupName());
	m_window.draw(winningPlayer);
	m_window.display();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	m_window.close();
}


void Controller::restartPlayers()
{
	m_numOfPlayers= m_menu.getInput().m_numOfPlayers;
	int numOfPlayer = m_menu.getInput().m_numOfPlayers;
	int j = 0;
	auto name = m_menu.getInput().m_playerName;
	m_players.resize(numOfPlayer);
	for (auto& it : m_players)
	{
		auto i = std::make_unique<Player>(name[j], m_menu.getInput().m_playersColor[j],
			*m_world, m_board, m_FeatureToolBar, m_window);
		it.swap(i);
		j++;
	}
}


void Controller::defineBoard()
{
	b2Vec2 m_gravity(0.0f, 1.2f);
	m_world = std::make_unique <b2World>(m_gravity);
	m_board.createBord(*m_world, m_menu.getInput().m_background);
}


void Controller::drawPlayer()
{
	for (auto& i : m_players)
		i->draw();
}

void Controller::exitGame()
{
	for (auto event = sf::Event{};m_window.pollEvent(event); )
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
			event.type == sf::Event::Closed)
		{
			m_window.close();
			break;
		}
}

