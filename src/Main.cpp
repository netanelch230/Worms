#pragma once
#include "Controller.h"
#include <box2d/box2d.h>
#include <iostream>
int main()
{
	try
	{
		Controller r;
		r.run();
	}
	catch (...)
	{
		std::cout << "in exception in main" << std::endl;
	}
}