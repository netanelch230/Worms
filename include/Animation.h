#include <SFML/Graphics.hpp>
#include "AnimationSet.h"

class Animation 
{
public:
	Animation() {}
	Animation(sf::Texture* tex, sf::Vector2u imageCount, float switchtime, int distance, bool restart = true);
	Animation(Animation& ani) = default;
	void update(int row, float deltaTime);
	sf::IntRect getrect() { return m_rect; };
	bool isDead();
	void setSwitchTime(float switchTime) { m_switchtime = switchTime; }
private:
	bool m_restartAnimation = true;
	sf::IntRect m_rect;
	sf::Vector2u m_imageCount;
	sf::Vector2u currentImage;
	float m_totaltime;
	float m_switchtime;
	int m_distance;
};
