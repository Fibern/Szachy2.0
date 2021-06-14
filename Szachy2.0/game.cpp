#include "game.h"
#include "piece.h"

Game::Game()
{
	this->player = 1;
	this->initWindow();
	this->initBoard();
	this->startingPosition();
}

void Game::initWindow()
{
	this->window.create(VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBoard()
{
	if (!this->boardt.loadFromFile("images/brown.png"))
		cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << endl;
	this->boardt.setRepeated(true);
	this->board.setTextureRect({ 0, 0, 800, 800 });
	this->board.setTexture(this->boardt);
}

void Game::update()
{
	float dx{}, dy{};

	Vector2i pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e))
	{

		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseButtonPressed) {
			if (e.key.code == Mouse::Left) {
				for (int i = 0; i < 16; i++) {
					if (player)
						bounds = (IntRect)white[i].getSprite().getGlobalBounds();
					else
						bounds = (IntRect)black[i].getSprite().getGlobalBounds();
					if (bounds.contains(pos.x, pos.y)) {
						dragging[i] = 1;
						break;
					}
				}
			}
		}

		if (e.type == Event::MouseButtonReleased) {
			for (int i = 0; i < 16; i++) {
				if (e.key.code == Mouse::Left && dragging[i]) {
					dragging[i] = 0;
					dx = (float)floor(pos.x / 100) * 100;
					dy = (float)floor(pos.y / 100) * 100;

					if (isLegal()) {
						if (player)
							white[i].set(dx, dy);
						else
							black[i].set(dx, dy);
						player = !player;
					}
					else {
						if (player)
							white[i].set((float)bounds.left, (float)bounds.top);
						else
							black[i].set((float)bounds.left, (float)bounds.top);
					}
				}
			}
		}

		for (int i = 0; i < 32; i++) {
			if (dragging[i]) {
				if (player)
					white[i].set(pos.x - 50.f, pos.y - 50.f);
				else
					black[i].set(pos.x - 50.f, pos.y - 50.f);
			}
		}

	}
}

void Game::drawBoard()
{
	this->window.draw(board);
	for (int i = 0; i < 16; i++) {
		this->window.draw(white[i].getSprite());
		this->window.draw(black[i].getSprite());
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

void Game::startingPosition()
{
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

bool Game::isLegal() {
	if (true)
		return 1;
	else
		return 0;
}