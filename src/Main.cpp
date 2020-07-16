#pragma once
#include "Controller.h"
#include <box2d/box2d.h>
#include <iostream>
int main()
{
	try
	{
		Controller game;
		game.run();
	}
	catch (...)
	{
		std::cout << "in exception in main" << std::endl;
	}
}