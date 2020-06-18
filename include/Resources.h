#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using animArray = std::array<sf::Texture, amuntOfPicture>;

class Resources
{
public:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	static Resources& instance();
	~Resources() = default;

	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	//sf::Music& getMusic(int i);

private:
	Resources() {
		loadPicture();
		loadFont();
	};
	animArray m_picture;
	sf::Texture m_featuresMenu;
	std::array<sf::Font, countOfFont> m_font;
	//std::array<sf::Music,countOfMusic> m_sound;
	void loadPicture();
	void loadFont();

};

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f randomLocation(int height, int width);

