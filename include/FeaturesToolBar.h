#pragma once
#include <vector>
#include <memory>
#include "Button.h"
#include "Enum.h"
#include "Resource.h"

//--------------class--------------
class FeatureToolBar
{
public:
	FeatureToolBar();
	void drawFeatureMenu( sf::RenderWindow &window);
	std::vector < std::unique_ptr <Button> > &getFeatureVec();
	~FeatureToolBar() = default;

private:

	void setSpriteIcons();
	void setButtonVector();

	std::vector <std::unique_ptr<Button>> m_FeatureButton;
	std::vector<sf::Sprite> m_FeatureSprite;
	
};