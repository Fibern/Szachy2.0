#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace sf;
using namespace std;

int main()
{
	
	RenderWindow window(sf::VideoMode(600, 600), "Szachy");

	Event e;
	
	Texture board;

	if (!board.loadFromFile("images/bishopw.png"))
	{
		
	}

	Sprite background(board);

	float dx = 0, dy = 0;
	bool isMove = 0;

	while (window.isOpen()) {

		while (window.pollEvent(e)) {


			if (e.type == Event::Closed) {

				window.close();
			}

			Vector2i pos = Mouse::getPosition(window);

			if (e.type == Event::MouseButtonPressed)
			{


				if (e.key.code == Mouse::Left) {

					if (background.getGlobalBounds().contains(pos.x, pos.y)) {
						isMove = 1;
						dx = pos.x - background.getPosition().x;
						dy = pos.y - background.getPosition().y;
					}

				}

			}

			if (e.type == Event::MouseButtonReleased) {
				if (e.key.code == Mouse::Left) {
					isMove = 0;
				}
			}


			if (isMove) {
				background.setPosition(pos.x - dx, pos.y - dy);
			}

		}



		window.clear();
		window.draw(background);
		window.display();

	}

	return 0;
}