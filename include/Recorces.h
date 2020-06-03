#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include<memory>

class Recorces
{
public:
	Recorces();
private:
	std::vector<sf::RectangleShape> m_rectangle;
	sf::Texture m_picture[16];
	sf::Font m_messege[5];
	sf::Music m_sound[3];
};