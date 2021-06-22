#include "game.h"

int main()
{
	Game game;	

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
