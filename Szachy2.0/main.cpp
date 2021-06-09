#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace sf;
using namespace std;

int main()
{
	
	RenderWindow window(VideoMode(1024, 1024), "Szachy");

	Event e;

	RectangleShape board;
	
	Texture t1, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14;

	t1.loadFromFile("images/brown.png");
	t3.loadFromFile("images/pawnw.png");
	t4.loadFromFile("images/pawnb.png");
	t5.loadFromFile("images/rookw.png");
	t6.loadFromFile("images/rookb.png");
	t7.loadFromFile("images/bishopw.png");
	t8.loadFromFile("images/bishopb.png");
	t9.loadFromFile("images/knightw.png");
	t10.loadFromFile("images/knightb.png");
	t11.loadFromFile("images/queenw.png");
	t12.loadFromFile("images/queenb.png");
	t13.loadFromFile("images/kingw.png");
	t14.loadFromFile("images/kingb.png");

	Sprite board(t1);
	Sprite pawnw(t3);
	Sprite pawnb(t4);
	Sprite rookw(t5);
	Sprite rookb(t6);
	Sprite bishopw(t7);
	Sprite bishopb(t8);
	Sprite knightw(t9);
	Sprite knightb(t10);
	Sprite queenw(t11);
	Sprite queen(t12);
	Sprite kingw(t13);
	Sprite kingb(t14);


	float dx = 0, dy = 0;
	bool isMove = 0;

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();

			Vector2i pos = Mouse::getPosition(window);

			if (e.type == Event::MouseButtonPressed) {
				if (e.key.code == Mouse::Left) {
					if (pawnw.getGlobalBounds().contains(pos.x, pos.y)) {
						isMove = 1;
						dx = pos.x - pawnw.getPosition().x;
						dy = pos.y - pawnw.getPosition().y;
					}
				}
			}

			if (e.type == Event::MouseButtonReleased) {
				if (e.key.code == Mouse::Left)
					isMove = 0;
			}

			if (isMove)
				pawnw.setPosition(pos.x - dx, pos.y - dy);
		}

		window.clear();
		window.draw(pawnw);
		window.display();
	}

	return 0;
}