#pragma once
#include <vector>
#include <memory>
#include "Button.h"
#include "Enum.h"
#include "Resources.h"

class FeaturesToolBar
{
public:
	FeaturesToolBar();
	void drawFeaturesMenu( sf::RenderWindow &window);
	std::vector < std::unique_ptr <Button> > &getFeaturesVec();
	~FeaturesToolBar() = default;

private:

	void setSpriteIcons();
	void setButtonVector();

	std::vector <std::unique_ptr<Button>> m_featuresButton;
	std::vector<sf::Sprite> m_featuresSprite;
	
};