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
	this->startingPosition();
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
	IntRect bounds;

	while (this->window.pollEvent(this->e)) 
	{

		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseButtonPressed) {
			if (e.key.code == Mouse::Left) {
				for (int i = 0; i < 32; i++) {
					if (i < 16)
						bounds = (IntRect)white[i].sprite.getGlobalBounds();
					else
						bounds = (IntRect)black[i - 16].sprite.getGlobalBounds();
					if (bounds.contains(pos.x,pos.y)) {
						dragging[i] = 1;
						break;
					}
				}
			}
		}

		if (e.type == Event::MouseButtonReleased) {
			for (int i = 0; i < 32; i++) {
				if (e.key.code == Mouse::Left && dragging[i]) {
					dragging[i] = 0;
					dx = (float)floor(pos.x / 100) * 100;
					dy = (float)floor(pos.y / 100) * 100;
					if (i < 16)
						white[i].sprite.setPosition(dx, dy);
					else
						black[i - 16].sprite.setPosition(dx, dy);
				}
			}
		}

		for (int i = 0; i < 32; i++) {
			if (dragging[i]) {
				if (i < 16)
					white[i].sprite.setPosition(pos.x - 50.f, pos.y - 50.f);
				else
					black[i - 16].sprite.setPosition(pos.x - 50.f, pos.y - 50.f);
			}
		}

	}
}

void Game::drawBoard()
{
	this->window.draw(board);
	for (int i = 0; i < 16; i++) {
		this->window.draw(white[i].sprite);
		this->window.draw(black[i].sprite);
	}
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
	white[0].setPiece('R', 1, 0, 7);
	white[1].setPiece('N', 1, 1, 7);
	white[2].setPiece('B', 1, 2, 7);
	white[3].setPiece('Q', 1, 3, 7);
	white[4].setPiece('K', 1, 4, 7);
	white[5].setPiece('B', 1, 5, 7);
	white[6].setPiece('N', 1, 6, 7);
	white[7].setPiece('R', 1, 7, 7);

	black[0].setPiece('R', 0, 0, 0);
	black[1].setPiece('N', 0, 1, 0);
	black[2].setPiece('B', 0, 2, 0);
	black[3].setPiece('Q', 0, 3, 0);
	black[4].setPiece('K', 0, 4, 0);
	black[5].setPiece('B', 0, 5, 0);
	black[6].setPiece('N', 0, 6, 0);
	black[7].setPiece('R', 0, 7, 0);

	for (int i = 8; i < 16; i++)
	{
		white[i].setPiece('P', 1, i - 8, 6);
		black[i].setPiece('P', 0, i - 8, 1);
	}

}

