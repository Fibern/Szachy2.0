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

promocje 
//funkcja na releasie kt�ra ustawia promocje
funkcja na kliku kt�ra pozwala na wybranie
funkcja rysuj�ca


roszady

ruchy kr�lem
szachy, maty, paty
przypi�cia

menu zapisywanie i wczytywanie
*/