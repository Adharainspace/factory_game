#include <iostream>

#include "Macros.h"
#include "Game.h"

int main()
{
	try
	{
		Game game(WINDOW_WIDTH, WINDOW_HEIGHT);
		game.main_loop();
	}
	catch (Exception exception)
	{
		std::cout << "exception: " << exception.what() << " halting program." << std::endl;
	}
}
