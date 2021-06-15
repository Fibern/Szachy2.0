#include "game.h"
#include "piece.h"

Game::Game()
{
	this->player = 1;
	this->initWindow();
	this->initBoard();
	this->startingPosition();
	this->checkMoves();
	for (int i = 0; i < possibleMoves.size(); i++)
		cout << possibleMoves[i] << endl;
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
					if (player)
						tmpMove = white[i].cordToString((int)dx / 100, (int)dy / 100);
					else
						tmpMove = black[i].cordToString((int)dx / 100, (int)dy / 100);

					if (isLegal(tmpMove)) {
						if (player) {
							white[i].setPos(dx, dy);
							white[i].updateCord(dx / 100, dy / 100);
						}
						else {
							black[i].setPos(dx, dy);
							black[i].updateCord(dx / 100.f, dy / 100.f);
						}

						gameMoves.push_back(tmpMove);
						player = !player;
						possibleMoves.clear();
						checkMoves();

						for (int i = 0; i < possibleMoves.size(); i++)
							cout << possibleMoves[i] << endl; 
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

//Funkcje dla ka¿dej figury
void Game::checkRook(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
	Piece p;

	for (int i = x + 1; i < 8; i++) {
		p = checkPiece(i, y);
		if (p.getSet()) {

			if ((p.getColor() && player) || (!p.getColor() && !player)) {
				break;
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else {
			possibleMoves.push_back(tmp.cordToString(i, y));
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player)) {
				break;
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else {
			possibleMoves.push_back(tmp.cordToString(i, y));
		}
	}

	for (int i = y + 1; i < 8; i++) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player)) {
				break;
			}
			else {
				possibleMoves.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else {
			possibleMoves.push_back(tmp.cordToString(x, i));
		}
	}

	for (int i = y - 1; i >= 0; i--) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player)) {
				break;
			}
			else {
				possibleMoves.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else {
			possibleMoves.push_back(tmp.cordToString(x, i));
		}
	}


}

void Game::checkPawn(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
}

void Game::checkBishop(Piece tmp) {
	int x = tmp.getX();
	int y = tmp.getY();
	Piece p;

	for (int i = x; i < 8; i++) {
		for (int j = y; j < 8; j++) {
			p = checkPiece(i, j);
			if (p.getSet()) {

				if ((p.getColor() && player) || (!p.getColor() && !player)) {
					break;
				}
				else {
					possibleMoves.push_back(tmp.cordToString(i, j));
					break;
				}
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, j));
			}
		}
	}

	for (int i = x; i < 8; i++) {
		for (int j = y; j >= 0; j--) {
			p = checkPiece(i, j);
			if (p.getSet()) {

				if ((p.getColor() && player) || (!p.getColor() && !player)) {
					break;
				}
				else {
					possibleMoves.push_back(tmp.cordToString(i, j));
					break;
				}
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, j));
			}
		}
	}

	for (int i = x; i >= 0; i--) {
		for (int j = y; j < 8; j++) {
			p = checkPiece(i, j);
			if (p.getSet()) {

				if ((p.getColor() && player) || (!p.getColor() && !player)) {
					break;
				}
				else {
					possibleMoves.push_back(tmp.cordToString(i, j));
					break;
				}
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, j));
			}
		}
	}

	for (int i = x; i >= 0; i--) {
		for (int j = y; j >= 0; j--) {
			p = checkPiece(i, j);
			if (p.getSet()) {

				if ((p.getColor() && player) || (!p.getColor() && !player)) {
					break;
				}
				else {
					possibleMoves.push_back(tmp.cordToString(i, j));
					break;
				}
			}
			else {
				possibleMoves.push_back(tmp.cordToString(i, j));
			}
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

bool Game::isLegal(string tmpMove) {
	for (int i = 0; i < possibleMoves.size(); i++) {
		if (tmpMove == possibleMoves[i])
			return 1;
	}
	return 0;
}