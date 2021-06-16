#include "game.h"

int main()
{
	Game game;

	while (game.getWindow().isOpen()) {
		game.updateWindow();
		game.renderWindow();
	}

	return 0;
}

/*
figura jest na górze

promocje 
roszady

ruchy królem
szachy, maty, paty
przypiêcia

menu zapisywanie i wczytywanie
*/