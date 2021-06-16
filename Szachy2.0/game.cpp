#include "game.h"
#include "piece.h"
#include<windows.h>

Game::Game()
{
	this->player = 1;
	this->initWindow();
	this->initBoard();
	this->startingPosition();
	this->checkMoves();
	for (int i = 0; i < (int)possibleMoves.size(); i++)
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

void Game::updateWindow()
{

	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e))
	{

		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseButtonPressed) {
			bounds = {};
			if (e.key.code == Mouse::Left) {
				for (int i = 0; i < 16; i++) {
					if (player && white[i].getSet()) {
						bounds = (IntRect)white[i].getSprite().getGlobalBounds();
						tmp = white[i];
					}
					else if (!player && black[i].getSet()) {
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

						updateMoves((int)(dx / 100), int(dy / 100), i);

					}
					else {
						tmpMove = "";
						if (player)
							white[i].setPos((float)bounds.left, (float)bounds.top);
						else
							black[i].setPos((float)bounds.left, (float)bounds.top);
					}
				}
			}
		}

		for (int i = 0; i < 16; i++) {
			if (dragging[i]) {
				if (player && white[i].getSet()) {
					white[i].setPos(pos.x - 50.f, pos.y - 50.f);
					cout << white[i].getType();
				}
				else if (!player && black[i].getSet()) {
					black[i].setPos(pos.x - 50.f, pos.y - 50.f);
					cout << black[i].getType();
				}
			}
		}

	}
}

void Game::drawBoard()
{
	this->window.draw(board);
	for (int i = 0; i < 16; i++) {
		if (white[i].getSet() && !dragging[i])
			this->window.draw(white[i].getSprite());
		if (black[i].getSet() && !dragging[i])
			this->window.draw(black[i].getSprite());
		if (white[i].getPromotion() || black[i].getPromotion()) {
			if (player) {
				
			}
			else {
				
			}
		}
	}
	for (int i = 0; i < 16; i++) {
		if (dragging[i]) {
			if (player) {
				if (black[i].getSet())
					this->window.draw(black[i].getSprite());
				this->window.draw(white[i].getSprite());
			}
			else {
				if (black[i].getSet())
					this->window.draw(white[i].getSprite());
				this->window.draw(black[i].getSprite());
			}
		}
	}
}

void Game::renderWindow()
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
	//Funkcja zapisuje wszystkie ruchy
	for (int i = 0; i < 16; i++) {
		if (player) {
			type = white[i].getType();
			tmpM = white[i];
		}
		else {
			type = black[i].getType();
			tmpM = black[i];
		}
		if (tmpM.getSet()) {
			switch (type)
			{
			case 'K':
				checkKing(tmpM);
				break;
			case 'Q':
				checkQueen(tmpM);
				break;
			case 'R':
				checkRook(tmpM);
				break;
			case 'B':
				checkBishop(tmpM);
				break;
			case 'N':
				checkKnight(tmpM);
				break;
			case 'P':
				checkPawn(tmpM);
				break;
			default:
				break;
			}
		}
	}

}

//Funkcje dla każdej figury
void Game::checkRook(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	for (int i = x + 1; i < 8; i++) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				if (p.getType() == 'K') {/*tu jest szach*/ }
				possibleMoves.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(i, y));
	}

	for (int i = x - 1; i >= 0; i--) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(i, y));
	}

	for (int i = y + 1; i < 8; i++) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x, i));
	}

	for (int i = y - 1; i >= 0; i--) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x, i));
	}

}

void Game::checkPawn(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	if (!player) {
		p = checkPiece(x, y + 1);
		if (!p.getSet()) {
			possibleMoves.push_back(tmp.cordToString(x, y + 1));
			if (y == 1) {
				p = checkPiece(x, y + 2);
				if (!p.getSet())
					possibleMoves.push_back(tmp.cordToString(x, y + 2));
			}
		}
		p = checkPiece(x + 1, y + 1);
		if (p.getSet() && p.getColor())
			possibleMoves.push_back(tmp.cordToString(x + 1, y + 1));
		p = checkPiece(x - 1, y + 1);
		if (p.getSet() && p.getColor())
			possibleMoves.push_back(tmp.cordToString(x - 1, y + 1));
		if (y == 4) {
			p = checkPiece(x - 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMoves.push_back(tmp.cordToString(x - 1, y + 1));
			p = checkPiece(x + 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMoves.push_back(tmp.cordToString(x + 1, y + 1));
		}

	}
	else {
		p = checkPiece(x, y - 1);
		if (!p.getSet()) {
			possibleMoves.push_back(tmp.cordToString(x, y - 1));
			if (y == 6) {
				p = checkPiece(x, y - 2);
				if (!p.getSet())
					possibleMoves.push_back(tmp.cordToString(x, y - 2));
			}
		}
		p = checkPiece(x + 1, y - 1);
		if (p.getSet() && !p.getColor())
			possibleMoves.push_back(tmp.cordToString(x + 1, y - 1));
		p = checkPiece(x - 1, y - 1);
		if (p.getSet() && !p.getColor())
			possibleMoves.push_back(tmp.cordToString(x - 1, y - 1));
		if (y == 3) {
			p = checkPiece(x - 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMoves.push_back(tmp.cordToString(x - 1, y - 1));
			p = checkPiece(x + 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMoves.push_back(tmp.cordToString(x + 1, y - 1));
		}
	}
}

void Game::checkBishop(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	for (int i = 1; i < 8 - x && i < 8 - y; i++) {
		p = checkPiece(x + i, y + i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x + i, y + i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x + i, y + i));
	}

	for (int i = 1; i < 8 - x && i <= y; i++) {
		p = checkPiece(x + i, y - i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x + i, y - i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x + i, y - i));
	}

	for (int i = 1; i <= x && i < 8 - y; i++) {
		p = checkPiece(x - i, y + i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x - i, y + i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x - i, y + i));
	}

	for (int i = 1; i <= x && i <= y; i++) {
		p = checkPiece(x - i, y - i);
		if (p.getSet()) {
			if ((p.getColor() && player) || (!p.getColor() && !player))
				break;
			else {
				possibleMoves.push_back(tmp.cordToString(x - i, y - i));
				break;
			}
		}
		else
			possibleMoves.push_back(tmp.cordToString(x - i, y - i));
	}
}

void Game::checkKnight(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	p = checkPiece(x - 2, y - 1);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x - 2 >= 0 && y - 1 >= 0)
		possibleMoves.push_back(tmp.cordToString(x - 2, y - 1));
	p = checkPiece(x - 2, y + 1);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x - 2 >= 0 && y + 1 < 8)
		possibleMoves.push_back(tmp.cordToString(x - 2, y + 1));
	p = checkPiece(x - 1, y - 2);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x - 1 >= 0 && y - 2 >= 0)
		possibleMoves.push_back(tmp.cordToString(x - 1, y - 2));
	p = checkPiece(x - 1, y + 2);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x - 1 >= 0 && y + 2 < 8)
		possibleMoves.push_back(tmp.cordToString(x - 1, y + 2));
	p = checkPiece(x + 1, y - 2);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x + 1 < 8 && y - 2 >= 0)
		possibleMoves.push_back(tmp.cordToString(x + 1, y - 2));
	p = checkPiece(x + 1, y + 2);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x + 1 < 8 && y + 2 < 8)
		possibleMoves.push_back(tmp.cordToString(x + 1, y + 2));
	p = checkPiece(x + 2, y - 1);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x + 2 < 8 && y - 1 >= 0)
		possibleMoves.push_back(tmp.cordToString(x + 2, y - 1));
	p = checkPiece(x + 2, y + 1);
	if (((p.getSet() && (p.getColor() && !player) || (!p.getColor() && player)) || !p.getSet()) && x + 2 < 8 && y + 1 < 8)
		possibleMoves.push_back(tmp.cordToString(x + 2, y + 1));
}

void Game::checkKing(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();
	p = {};
	cout << x << " " << y << " ";
	for (int i = -1; i < 2 && x + i < 8; i++) {
		if (i + x < 0)
			continue;
		for (int j = -1; j < 2 && y + j < 8; j++) {
			if ((i == 0 && j == 0) || j + y < 0)
				continue;
			p = checkPiece(x + i, y + j);
			if(!p.getSet() || (p.getSet() && ((!player && p.getColor()) || (player && !p.getColor()))))
				possibleMoves.push_back(tmp.cordToString(x + i, y + j));
		}
	}
}

void Game::checkQueen(Piece tmp) {
	checkRook(tmp);
	checkBishop(tmp);
}

Piece Game::checkPiece(int x, int y) {
	tmpSet = 0;
	for (int i = 0; i < 16; i++) {
		if (white[i].getX() == x && white[i].getY() == y) {
			tmpM = white[i];
			if (tmpM.getSet()) {
				tmpSet = 1;
				break;
			}
		}
		if (black[i].getX() == x && black[i].getY() == y) {
			tmpM = black[i];
			if (tmpM.getSet()) {
				tmpSet = 1;
				break;
			}
		}
	}
	if (!tmpSet)
		tmpM = {};
	return tmpM;
}

bool Game::isLegal(string tmpMove) {
	for (int i = 0; i < (int)possibleMoves.size(); i++) {
		if (tmpMove == possibleMoves[i])
			return 1;
	}
	return 0;
}

void Game::takes(int x, int y) {
	for (int i = 0; i < 16; i++) {
		if (white[i].getX() == x && white[i].getY() == y && white[i].getSet() && player) {
			white[i].changeSet(0);
			break;
		}
		if (black[i].getX() == x && black[i].getY() == y && black[i].getSet() && !player) {
			black[i].changeSet(0);
			break;
		}
	}
}

void Game::updateMoves(int x, int y, int i) {

	gameMoves.push_back(tmpMove);
	
	player = !player;
	takes(x, y);
	possibleMoves.clear();
	clearEnPassant();

	if (white[i].getPromotion())
		white[i].changeSet(0);

	if (black[i].getPromotion())
		black[i].changeSet(0);

	if (player) {
		if (black[i].getType() == 'P' && tmpMove[2] == '7' && tmpMove[4] == '5')
			black[i].setEnPassant(1);
		if (black[i].getType() == 'P' && tmpMove[1] != tmpMove[3] && tmpMove[2] == '4')
			takes(x, y - 1);
	}
	else {
		if (white[i].getType() == 'P' && tmpMove[2] == '2' && tmpMove[4] == '4')
			white[i].setEnPassant(1);
		if (white[i].getType() == 'P' && tmpMove[1] != tmpMove[3] && tmpMove[2] == '5')
			takes(x, y + 1);

	}

	system("cls");
	checkMoves();
	for (int j = 0; j < (int)possibleMoves.size(); j++) {
		if (possibleMoves[j][0] == 'K')
			cout << possibleMoves[j] << endl;
	}


}

void Game::clearEnPassant() {
	for (int i = 8; i < 16; i++) {
		if (player)
			black[i].setEnPassant(0);
		else
			white[i].setEnPassant(0);
	}
}

void Game::checkPromotion(int i) {
	if (player) {
		if (white[i].getType() == 'P' && ((white[i].getColor() && white[i].getY() == 0) || (!white[i].getColor() && white[i].getY() == 7))) {
			this->promotion = 1;
		}
	}
	else{
		if (black[i].getType() == 'P' && ((black[i].getColor() && black[i].getY() == 0) || (!black[i].getColor() && black[i].getY() == 7))) {
			this->promotion = 1;
		}
	}
}