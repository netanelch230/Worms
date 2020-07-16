#include "Pass.h"

void Pass::aliveFeature(sf::Event& event, sf::RenderWindow& window, Worm& worm, int& drawFeature)
{
	worm.initializeWormSpriteSetting(sf::Vector2f{ 20,20 },
		image(animation_skip));
	worm.setSprite(20, 40);
	drawFeature++;
}

void Pass::applyFeature(sf::Event& event, int& drawFeature)
{
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Space)
			drawFeature = endBombAnimation;

}
