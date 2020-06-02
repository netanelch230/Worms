#pragma once
#include"AbsObject.h"
const auto NumOfLife = 150;

class Worms:public AbsObject
{
public:
	Worms();
	~Worms();

private:
	bool health = true;
	int m_life= NumOfLife;
};

Worms::Worms()
{
}

Worms::~Worms()
{
}