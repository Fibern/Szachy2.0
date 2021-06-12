#include "game.h"
#include "piece.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBoard() 
{
	if (!this->boardt.loadFromFile("images/brown.png"))
	{
		cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << endl;
	}
	this->boardt.setRepeated(true);
	this->board.setTextureRect({ 0, 0, 800, 800 });
	this->board.setTexture(this->boardt);
}

Game::Game()
{
	this->initWindow();
	this->initBoard();
}

Game::~Game()
{

}

void Game::update() 
{
	bool dragging = 0;
	Piece piece;
	float dx{}, dy{};

	while (this->window.pollEvent(this->e)) 
	{
		Vector2i pos = Mouse::getPosition(window);

		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseButtonPressed) {
			if (e.key.code == Mouse::Left) {
				for (int i = 0; i < 16; i++) {
					if (board.getGlobalBounds().contains(pos.x, pos.y)) {
						dragging = 1;
						piece = white[i];
					}
				}
			}
		}

		if (e.type == Event::MouseButtonReleased) {
			if (e.key.code == Mouse::Left && dragging) {
				dragging = 0;
				dx = (float)floor(pos.x / 100) * 100;
				dy = (float)floor(pos.y / 100) * 100;
				board.setPosition(dx, dy);
			}
		}

		if (dragging) 
			board.setPosition(pos.x - (float)50, pos.y - (float)50);
	

	}
}

void Game::drawBoard()
{
	this->window.draw(board);
}

void Game::render()
{
	this->window.clear();
	drawBoard();
	this->window.display();
}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::startingPosition() {

}

