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
roszady

szachy, maty, paty
przypiÍcia

menu zapisywanie i wczytywanie
*/