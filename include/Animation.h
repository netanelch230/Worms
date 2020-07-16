#include <SFML/Graphics.hpp>
#include "AnimationSet.h"

//--------------class--------------
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
	~Animation() = default;

private:
	bool m_restartAnimation = true;
	sf::IntRect m_rect;
	sf::Vector2u m_imageCount;
	sf::Vector2u currentImage;
	float m_totaltime=0.f;
	float m_switchtime = 0.03f;
	int m_distance=1;
};
