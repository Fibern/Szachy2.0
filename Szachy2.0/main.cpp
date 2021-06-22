#include "game.h"
#include <Windows.h>

int main()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE); //Ukrywanie konsoli
	Game game;	

	//Pêtla g³ówna gry
	while (game.getWindow().isOpen()) {
		if (game.getWindowState() == 1)
			game.updateWindowMenu();
		else if (game.getWindowState() == 2)
			game.updateWindowGameMenu();
		else if (game.getWindowState() == 3 || game.getWindowState() == 4 || game.getWindowState() == 5)
			game.updateWindowAfterGameMenu();
		else if (game.getWindowState() == 6 || game.getWindowState() == 7)
			game.updateWindowSL();
		else
			game.updateWindow();
		game.renderWindow();
	}

	return 0;
}
