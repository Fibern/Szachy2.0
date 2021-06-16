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
//funkcja na releasie która ustawia promocje
funkcja na kliku która pozwala na wybranie
funkcja rysuj¹ca


roszady

ruchy królem
szachy, maty, paty
przypiêcia

menu zapisywanie i wczytywanie
*/