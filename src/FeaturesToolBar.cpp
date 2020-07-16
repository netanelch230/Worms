#pragma once
#include "FeaturesToolBar.h"

FeatureToolBar::FeatureToolBar()
{
	m_FeatureButton.resize(FeatureAmount);
	m_FeatureSprite.resize(FeatureAmount);
	setSpriteIcons();
	setButtonVector();
}

void FeatureToolBar::drawFeatureMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < FeatureAmount; i++)
		m_FeatureButton[i]->draw(window);

}


std::vector<std::unique_ptr<Button>> &FeatureToolBar::getFeatureVec()
{
	return m_FeatureButton;
}



void FeatureToolBar::setSpriteIcons()
{
	int k = 0;
	for (auto i = 0; i < FeatureAmount / 4; i++)
	{
		for (auto j = 0; j < FeatureAmount / 2; j++)
		{
			m_FeatureSprite[k].setTexture(image(k + speedButtonIcon));
			m_FeatureSprite[k].setPosition(feautersX + (j * feauterSize), feautersY+ (i* feauterSize));
			k++;
		}
		
	}
}

void FeatureToolBar::setButtonVector()
{
	for (auto i = 0; i < m_FeatureSprite.size(); i++)
	{
		m_FeatureButton[i] = std::make_unique <Button>(m_FeatureSprite[i], m_FeatureSprite[i].getPosition());
	}
}
