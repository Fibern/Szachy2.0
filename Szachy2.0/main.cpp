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
figura jest na g�rze

promocje 
roszady

ruchy kr�lem
szachy, maty, paty
przypi�cia

menu zapisywanie i wczytywanie
*/