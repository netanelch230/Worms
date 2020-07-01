#pragma once
#include"NonMovingAttack.h"
#include"Enum.h"


class Artilary :public NonMovingAttack {
public:
	Artilary(b2World& world, sf::Vector2f position);
	bool runFeature(sf::Event& event, sf::RenderWindow& window,
	bool& drawFeatur, Worm& worm) override;
	void setExplode() { m_explode = true; }
	~Artilary() = default;
private:
	bool m_explode = false;
};


