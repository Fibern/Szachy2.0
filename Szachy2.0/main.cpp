#include "game.h"
#include "menu.h"
//#include<SFML/Graphics.hpp>

using namespace sf;

int main()
{
	//Menu menu;

	//while (menu.getWindow().isOpen()) {
	//	menu.updateWindow();
	//	menu.renderWindow();
	//}

	Game game;
	
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
		else if (game.getWindowState() == 3 || game.getWindowState() == 4 || game.getWindowState() == 5)
			game.updateWindowAfterGameMenu();
		else
			game.updateWindow();
		game.renderWindow();
	}

	return 0;
}

/*
menu zapisywanie i wczytywanie
*/