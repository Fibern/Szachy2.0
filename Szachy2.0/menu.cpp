#include "menu.h"
Menu::Menu()
{
	this->initWindow();
	this->initBackground();
	this->initText();
}

void Menu::initWindow()
{
	this->window.create(VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Menu::initBackground()
{
	if (!this->boardt.loadFromFile("images/brown.png"))
		cout << "Can't load board texture!" << endl;
	this->boardt.setRepeated(true);
	this->board.setTextureRect({ 0, 0, 800, 800 });
	this->board.setTexture(this->boardt);
}

void Menu::initText()
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("Play!");
	text[0].setPosition(Vector2f(800 / 2 - 20.f, 800 / 5));

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("Load game");
	text[1].setPosition(Vector2f(800 / 2 - 20.f, 800 / 5 * 2));

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("Instruction");
	text[2].setPosition(Vector2f(800 / 2 - 20.f, 800 / 5 * 3));

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("Exit");
	text[3].setPosition(Vector2f(800 / 2 - 20.f, 800 / 5 * 4));
}

void Menu::drawBackground()
{
	this->window.draw(board);
}

void Menu::drawText()
{
	for (int i = 0; i < 4; i++)
		window.draw(text[i]);
}

void Menu::updateWindow()
{
	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();
	}
}

void Menu::renderWindow()
{
	this->window.clear();
	drawBackground();
	drawText();
	this->window.display();
}

const RenderWindow& Menu::getWindow() const
{
	return this->window;
}