#include "game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBoard() {
	

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

void Game::update() {
	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();
	}
}

void Game::drawBoard()
{
	//Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;

	//t1.loadFromFile("images/brown.png");
	//t2.loadFromFile("images/pawnw.png");
	//t3.loadFromFile("images/pawnb.png");
	//t4.loadFromFile("images/rookw.png");
	//t5.loadFromFile("images/rookb.png");
	//t6.loadFromFile("images/bishopw.png");
	//t7.loadFromFile("images/bishopb.png");
	//t8.loadFromFile("images/knightw.png");
	//t9.loadFromFile("images/knightb.png");
	//t10.loadFromFile("images/queenw.png");
	//t11.loadFromFile("images/queenb.png");
	//t12.loadFromFile("images/kingw.png");
	//t13.loadFromFile("images/kingb.png");

	//Sprite board(t1);
	//Sprite pawnw(t2);
	//Sprite pawnb(t3);
	//Sprite rookw(t4);
	//Sprite rookb(t5);
	//Sprite bishopw(t6);
	//Sprite bishopb(t7);
	//Sprite knightw(t8);
	//Sprite knightb(t9);
	//Sprite queenw(t10);
	//Sprite queen(t11);
	//Sprite kingw(t12);
	//Sprite kingb(t13);

	this->window.draw(board);

}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::render()
{
	this->window.clear();
	drawBoard();
	this->window.display();
}