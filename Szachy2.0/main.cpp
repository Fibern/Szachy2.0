#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>
#include "game.h"

using namespace sf;
using namespace std;

int main()
{
	Game game;

	while (game.getWindow().isOpen()) {
		game.update();
		game.render();
	}

	return 0;
}