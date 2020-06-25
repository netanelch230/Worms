#include "Controller.h"
#include <iostream>


Controller::Controller()
{
	//m_window.create(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	if (m_menu.run(m_window) && m_window.isOpen())
	{
		defineBoard();
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
		m_board.draw(m_window);
		drawPlayer();
		m_window.display();
		exitGame();
		m_world->SetContactListener(&m_contactListener);
		for (auto& i : m_player)
			i->run(m_window, m_event, m_player, m_featuresMenu,m_featuresLocation);
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
			*m_world,m_board);
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
		if (i % colsInTable == 0 && i > 0)
			j++;
		m_featuresLocation[i].x = toolBarXCoordinate + (i % colsInTable) * squareSize;
		m_featuresLocation[i].y = j * squareSize;
	}

	for (auto i = 0; i < m_featuresLocation.size(); i++)
		std::cout << m_featuresLocation[i].x << " " << m_featuresLocation[i].y << std::endl;
}

void Controller::defineBoard()   
{
	b2Vec2 m_gravity(0.0f, 1.2f);
	m_world = std::make_unique <b2World> (m_gravity);

	////// Create borders for the screen so dragon cannot escape
	//float widthInMeters = m_window.getSize().x / 30;
	//float heightInMeters = m_window.getSize().y / 30;
	//b2Vec2 lowerLeftCorner = b2Vec2(0, 0);
	//b2Vec2 lowerRightCorner = b2Vec2(widthInMeters, 0);
	//b2Vec2 upperLeftCorner = b2Vec2(0, heightInMeters);
	//b2Vec2 upperRightCorner = b2Vec2(widthInMeters, heightInMeters);

	//b2BodyDef screenBorderDef;
	//screenBorderDef.position.Set(0, 0);
	//b2Body* screenBorderBody = m_world->CreateBody(&screenBorderDef);
	//b2EdgeShape screenBorderShape;

	//screenBorderShape.Set(lowerLeftCorner, lowerRightCorner);
	//screenBorderBody->CreateFixture(&screenBorderShape, 0);
	//screenBorderShape.Set(lowerRightCorner, upperRightCorner);
	//screenBorderBody->CreateFixture(&screenBorderShape, 0);
	//screenBorderShape.Set(upperRightCorner, upperLeftCorner);
	//screenBorderBody->CreateFixture(&screenBorderShape, 0);
	//screenBorderShape.Set(upperLeftCorner, lowerLeftCorner);
	//screenBorderBody->CreateFixture(&screenBorderShape, 0);

	m_board.createBord(*m_world, m_menu.getInput().m_background);
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
