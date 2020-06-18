#include <SFML/Graphics.hpp>

class Animation 
{
public:
	Animation(sf::Texture* tex, sf::Vector2u imageCount, float switchtime);
	Animation(Animation& ani) = default;
	void update(int row, float deltaTime);
	sf::IntRect getrect() { return m_rect; };
	void setRestartAnimation(bool ani) { m_restartAnimation = ani; }

private:
	bool m_restartAnimation = true;
	sf::IntRect m_rect;
	sf::Vector2u m_imageCount;
	sf::Vector2u currentImage;
	float m_totaltime;
	float m_switchtime;
};
