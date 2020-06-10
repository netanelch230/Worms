#include <SFML/Graphics.hpp>

class Animation {
public:
	Animation(sf::Texture tex, sf::Vector2u imageCount, float switchtime);
	void update(int row, float deltaTime);
	sf::IntRect getrect() { return m_rect; };
private:
	sf::IntRect m_rect;
	sf::Vector2u m_imageCount;
	sf::Vector2u currentImage;
	float m_totaltime;
	float m_switchtime;

};
