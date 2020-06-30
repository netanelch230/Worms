#pragma once
#include"NonMovingAttack.h"
#include"Enum.h"


class Artilary :public NonMovingAttack {
public:
	Artilary(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,sf::Vector2f{20,20},Resources::instance().getTexture(artileri) },
			AnimationSet{ animation_artilary,artilaryimagecount,false,1, {100, 100}, 0.07f },
			callartilary) {}
	virtual void applyFeatures();
	virtual void play() override {};
	bool runFeature(sf::Event& event, sf::RenderWindow& window, bool& drawFeatur, const sf::Vector2f& wormPosition) override;
};


