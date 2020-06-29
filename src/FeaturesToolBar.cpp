#pragma once
#include "FeaturesToolBar.h"

FeaturesToolBar::FeaturesToolBar()
{
	m_featuresButton.resize(featuresAmount);
	m_featuresSprite.resize(featuresAmount);
	setSpriteIcons();
	setButtonVector();
}

void FeaturesToolBar::drawFeaturesMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < featuresAmount; i++)
		m_featuresButton[i]->draw(window);

}


std::vector<std::unique_ptr<Button>> &FeaturesToolBar::getFeaturesVec()
{
	return m_featuresButton;
}



void FeaturesToolBar::setSpriteIcons()
{
	int k = 0;
	for (auto i = 0; i < featuresAmount / 4; i++)
	{
		for (auto j = 0; j < featuresAmount / 2; j++)
		{
			m_featuresSprite[k].setTexture(Resources::instance().getTexture(k + 49));
			m_featuresSprite[k].setPosition(feautersX + (j * feauterSize), feautersY+ (i* feauterSize));
			k++;
		}
		
	}
}

void FeaturesToolBar::setButtonVector()
{
	for (auto i = 0; i < m_featuresSprite.size(); i++)
	{
		m_featuresButton[i] = std::make_unique <Button>(m_featuresSprite[i], m_featuresSprite[i].getPosition());
	}
}
