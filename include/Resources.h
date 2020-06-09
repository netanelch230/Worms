#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"

enum e_music
{
	gamemusic,
	deathmusic,
	diamondmusic
};
class Resources
{
public:
	Resources() 
	{
		loadPicture();
		loadFont();
	};

	~Resources() = default;
	void loadPicture();
	void loadFont();
	void loadSound();
	std::vector<sf::Texture> &getPlayersTextures(){ return m_playersTextures; }
	sf::Texture& getTexture(const int i) { return m_pictures[i]; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	sf::Music& getMusic(int i);

private:
	std::vector<sf::RectangleShape> m_rectangle;
	std::vector<sf::Texture> m_pictures;
	std::vector<sf::Texture> m_playersTextures;

	std::vector<sf::Font> m_font;
	sf::Music m_sound[3];
};

