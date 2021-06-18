#include "game.h"
//#include<SFML/Graphics.hpp>

using namespace sf;

int main()
{
	Game game;
	//RenderWindow window;
	//window.create(VideoMode(800, 800), "Chess");
	//Texture xd;
	//xd.loadFromFile("images/queenw.png"); 
	//Sprite dx;
	//dx.setTexture(xd);
	//dx.scale(Vector2f(0.5f, 0.5f));
	//Event e;
	//while (window.isOpen())
	//{
	//	while (window.pollEvent(e))
	//	{
	//		if (e.type == Event::Closed)
	//			window.close();
	//	}
	//	window.clear();
	//
	//window.draw(dx);
	//	window.display();
	//}
	//

	while (game.getWindow().isOpen()) {
		game.updateWindow();
		game.renderWindow();
	}

	return 0;
}

/*
roszady

ruchy królem
szachy, maty, paty
przypiêcia

menu zapisywanie i wczytywanie
*/