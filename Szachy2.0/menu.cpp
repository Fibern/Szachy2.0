#include "menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;
	
	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("Play!");
	text[0].setPosition(Vector2f(width / 2 - 20.f, height / 5)); 

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("Load game");
	text[1].setPosition(Vector2f(width / 2 - 20.f, height / 5 * 2));

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("Instruction");
	text[2].setPosition(Vector2f(width / 2 - 20.f, height / 5 * 3));

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("Exit");
	text[3].setPosition(Vector2f(width / 2 - 20.f, height / 5 * 4));
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(text[i]);
	}
}
