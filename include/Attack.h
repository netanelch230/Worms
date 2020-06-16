#pragma once
#include"Features.h"

class Attack :public Features 
{
public:
	virtual bool touch(sf::Vector2f location);
private:
	int m_count;
};