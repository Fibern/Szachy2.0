#include "game.h"
#include "piece.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBoard() 
{
	if (!this->boardt.loadFromFile("images/brown.png")) {
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
	//Piece piece;
	float dx{}, dy{};
	
	Vector2i pos = Mouse::getPosition(window);
	Vector2f asd;
	float x = (float)pos.x, y = (float)pos.y;
	double xz = 0, zy = 9;

	while (this->window.pollEvent(this->e)) 
	{

		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseButtonPressed) {
			if (e.key.code == Mouse::Left) {
				for (int i = 0; i < 16; i++) {
					IntRect bounds = (IntRect)white.sprite.getGlobalBounds();
					if (bounds.contains(pos.x,pos.y))
						dragging = 1;
				}
			}
		}

		if (e.type == Event::MouseButtonReleased) {
			if (e.key.code == Mouse::Left && dragging) {
				dragging = 0;
				dx = (float)floor(pos.x / 100) * 100;
				dy = (float)floor(pos.y / 100) * 100;
				white.sprite.setPosition(dx, dy);
			}
		}

		if (dragging) 
			white.sprite.setPosition(pos.x - 50.f, pos.y - 50.f);
	

	}
}

void Game::drawBoard()
{
	this->window.draw(board);
	this->window.draw(white.sprite);
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

