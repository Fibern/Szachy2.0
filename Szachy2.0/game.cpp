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
					if (player) {
						bounds = (IntRect)white[i].getSprite().getGlobalBounds();
						tmp = white[i];
					}
					else {
						bounds = (IntRect)black[i].getSprite().getGlobalBounds();
						tmp = black[i];
					}
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

					if (isLegal(tmp)) {
						if (player) {
							white[i].setPos(dx, dy);
							cout << cordToString(white[i].cordToString(), white[i].cordToString((int)dx / 100, (int)dy / 100));
							white[i].updateCord(dx / 100, dy / 100);
						}
						else {
							black[i].setPos(dx, dy);
							cout << cordToString(black[i].cordToString(), black[i].cordToString((int)dx / 100, (int)dy / 100));
							black[i].updateCord(dx / 100.f, dy / 100.f);
						}
						checkMoves();
						player = !player;
					}
					else {
						if (player)
							white[i].setPos((float)bounds.left, (float)bounds.top);
						else
							black[i].setPos((float)bounds.left, (float)bounds.top);
					}
				}
			}
		}

		for (int i = 0; i < 32; i++) {
			if (dragging[i]) {
				if (player)
					white[i].setPos(pos.x - 50.f, pos.y - 50.f);
				else
					black[i].setPos(pos.x - 50.f, pos.y - 50.f);
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

void Game::checkMoves() {
	//funkcja zapisuje wszystkie ruchy
	char type;
	Piece tmp;

	for (int i = 0; i < 16; i++) {
		if (player) {
			type = white[i].getType();
			tmp = white[i];
		}
		else {
			type = black[i].getType();
			tmp = black[i];
		}

		switch (type)
		{
		case 'K':
			checkKing(tmp);
			break;
		case 'Q':
			checkQueen(tmp);
			break;
		case 'R':
			checkRook(tmp);
			break;
		case 'B':
			checkBishop(tmp);
			break;
		case 'N':
			checkKnight(tmp);
			break;
		case 'P':
			checkPawn(tmp);
			break;
		default:
			break;
		}

	}

}

//funkcje dla ka¿dej figury
void Game::checkRook(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
	Piece temp;

	for (int i = x; i < 8; i++) {
		temp = checkPiece(x, y);
		if (temp.getSet()) {
			if ((temp.getColor() && player) || (!temp.getColor() && !player)) {
				break;
			}
			else {
				//wpisz ruch
				break;
			}
		}
		else {
			//wpisz ruch
		}

	}
	for (int i = x; i >= 0; i--) {}
	for (int i = y; i < 8; i++) {}
	for (int i = y; i >= 0; i--) {}

}

void Game::checkPawn(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
}

void Game::checkBishop(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();

	for (int i = x; i < 8; i++) {
		for (int j = y; j < 8; j++) {

		}
	}

	for (int i = x; i < 8; i++) {
		for (int j = y; j >= 0; j--) {

		}
	}

	for (int i = x; i >= 0; i--) {
		for (int j = y; j < 8; j++) {

		}
	}

	for (int i = x; i >= 0; i--) {
		for (int j = y; j >= 0; j--) {

		}
	}
}
void Game::checkKnight(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
}
void Game::checkKing(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
}
void Game::checkQueen(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
}

Piece Game::checkPiece(int x, int y) {
	Piece tmp;
	for (int i = 0; i < 16; i++) {
		if (white[i].getX() == x && white[i].getY() == y) {
			tmp = white[i];
			break;
		}
		if (black[i].getX() == x && black[i].getY() == y) {
			tmp = black[i];
			break;
		}
	}
	return tmp;
}

bool Game::isLegal(Piece piece) {
	if (true)
		return 1;
	else
		return 0;
}

string Game::cordToString(string s1, string s2)
{
	return s1 + s2;
}