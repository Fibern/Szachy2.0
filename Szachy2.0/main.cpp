#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

int main()
{
	
	RenderWindow window(VideoMode(800, 800), "Chess", Style::Titlebar | Style::Close);

	Event e;
	
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;

	t1.loadFromFile("images/brown.png");
	t2.loadFromFile("images/pawnw.png");
	t3.loadFromFile("images/pawnb.png");
	t4.loadFromFile("images/rookw.png");
	t5.loadFromFile("images/rookb.png");
	t6.loadFromFile("images/bishopw.png");
	t7.loadFromFile("images/bishopb.png");
	t8.loadFromFile("images/knightw.png");
	t9.loadFromFile("images/knightb.png");
	t10.loadFromFile("images/queenw.png");
	t11.loadFromFile("images/queenb.png");
	t12.loadFromFile("images/kingw.png");
	t13.loadFromFile("images/kingb.png");
	t1.setRepeated(true);
	
	Sprite board(t1);
	Sprite pawnw(t2);
	Sprite pawnb(t3);
	Sprite rookw(t4);
	Sprite rookb(t5);
	Sprite bishopw(t6);
	Sprite bishopb(t7);
	Sprite knightw(t8);
	Sprite knightb(t9);
	Sprite queenw(t10);
	Sprite queen(t11);
	Sprite kingw(t12);
	Sprite kingb(t13);
	board.setTextureRect({ 0, 0, 800, 800});
	pawnw.setPosition(0, 100);
	float dx = 0, dy = 0;
	bool isMove = 0;

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			
			Vector2i pos = Mouse::getPosition(window);

			if (e.type == Event::MouseButtonPressed) {
				if (e.key.code == Mouse::Left) {
					if (pawnw.getGlobalBounds().contains(pos.x, pos.y))
						isMove = 1;
				}
			}

			if (e.type == Event::MouseButtonReleased) {
				if (e.key.code == Mouse::Left && isMove) {
					isMove = 0;
					dx = (float)floor(pos.x / 100) * 100;
					dy = (float)floor(pos.y / 100) * 100;
					pawnw.setPosition(dx, dy);
				}
			}

			if (isMove)
				pawnw.setPosition(pos.x - (float)50, pos.y - (float)50);
		}

		window.clear();
		window.draw(board);
		window.draw(pawnw);
		window.draw(pawnw);
		window.display();
	}

	return 0;
}