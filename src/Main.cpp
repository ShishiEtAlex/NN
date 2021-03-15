#include "engine/Engine.h"

#include <iostream>

int main()
{
	Engine engine;
	
	try
	{
		engine.run();
	}
	catch (std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	
	return 0;
}
