#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	int numOfPlayer;
	std::string name;
	std::cin >> numOfPlayer;
	m_player.resize(numOfPlayer);
	int j = 0;
	for (auto& it : m_player)
	{
		std::cin >> name;
		float widthRatio = 1200 / numOfPlayer;
		float heightRatio = 700 / numOfPlayer;
		j++;
		auto i = std::make_unique<Player>(name, sf::Vector2f{(float) widthRatio*j,heightRatio},sf::Color::Blue);
		it.swap(i);
	}



}

void Controller::run()
{
	m_menu.setFont(m_resources.getfont(0));
	m_menu.run(m_resources.getTexture(menuPic), m_window);
}

void Controller::menu()
{
	
}
