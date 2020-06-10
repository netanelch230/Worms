#include "Animation.h"

Animation::Animation(sf::Texture tex, sf::Vector2u imageCount, float switchtime):
m_imageCount(imageCount), m_switchtime(switchtime), m_totaltime(0.f)
{
	currentImage.x = 0;
	m_rect.width = tex.getSize().x / float(m_imageCount.x);
	m_rect.height = tex.getSize().y / float(m_imageCount.y);
}

void Animation::update(int row, float deltaTime)
{
	currentImage.x = row;
	m_totaltime += deltaTime;
	if (m_totaltime >= m_switchtime)
	{
		m_totaltime -= m_switchtime;
		currentImage.y++;
		if (currentImage.y >= m_imageCount.y)
			currentImage.y = 0;
	}
	m_rect.left = currentImage.x * m_rect.width;
	m_rect.top = currentImage.y * m_rect.height;

}