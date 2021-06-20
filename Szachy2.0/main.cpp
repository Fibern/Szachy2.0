#include "game.h"
#include "menu.h"
//#include<SFML/Graphics.hpp>

using namespace sf;

int main()
{
	//Menu menu;
	Game game;

	//while (menu.getWindow().isOpen()) {
	//	//menu.updateWindow();
	//	menu.renderWindow();
	//}

	
	
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
		if (game.getWindowState() == 1)
			game.updateWindowMenu();
		else if (game.getWindowState() == 2)
			game.updateWindowGameMenu();
		else
			game.updateWindow();
		game.renderWindow();
	}

	return 0;
}

/*
przypiêcia

szachy, maty, paty

menu zapisywanie i wczytywanie
*/