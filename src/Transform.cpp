#include "Transform.h"

Transform::Transform()
: Feature(AnimationSet{ animation_teleporter ,teleporterImageCount ,false,1 })
{
	m_sound.setBuffer(Music(transform));
}

void Transform::aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature)
{
	m_sound.play();
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				b2Vec2 loc{ location.x * MPP, location.y * MPP };
				worm.getBody()->SetTransform(loc,
					worm.getBody()->GetAngle());
				drawFeature = endBombAnimation;
				worm.setRegularAnimation();
			}
		}
	}
}

void Transform::applyFeature(sf::Event& event, int& drawFeature)
{

}

