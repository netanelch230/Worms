#pragma once
#include <vector>
#include <memory>
#include <string>
#include"Worms.h"

class Player
{
public:
	player(std::string name) :m_name(name) {};
	//~Player();

private:
	int m_numOfWorms;
	std::vector<std::unique_ptr<Worms>> m_worms;
	std::vector < std::unique_ptr<Attack> m_weapons;
	std::string m_name;
};
