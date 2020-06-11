#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"
#include <array>

using animArray = std::array<sf::Texture, countOfPicture>;

class Resources
{
public:
	Resources() {
		loadPicture();
		loadFont();
	};
	~Resources() = default;
	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Texture& getMenuTexture(const int& i) { return m_Menupictures[i]; };
	animArray& getAnimations() { return m_animations; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	sf::Music& getMusic(int i);
	std::vector<sf::Texture>& getPlayersTextures() { return m_playersBottonsTextures; }

private:
	std::array<sf::Texture,10> m_Menupictures;
	std::vector<sf::Texture> m_playersBottonsTextures;
	std::array<sf::Texture, countOfPicture> m_picture;
	animArray m_animations;
	std::array<sf::Font, countOfFont> m_font;
	//std::array<sf::Music,countOfMusic> m_sound;
	void loadPicture();
	void loadFont();
	//void loadSound();
};

