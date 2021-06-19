#include "game.h"
#include "menu.h"
//#include<SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window;
	Menu menu(800.f, 800.f);
	menu.draw(window);
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