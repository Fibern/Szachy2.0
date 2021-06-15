#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<string>
#include "piece.h"

using namespace sf;
using namespace std;

class Game
{
private:

	Piece white[16];
	Piece black[16];
	Piece tmp;
	RenderWindow window;
	void initWindow();

	Event e;
	Texture boardt;
	Sprite board;
	void initBoard();
	void drawBoard();
	bool dragging[32]{};

	bool player;
	IntRect bounds;
	vector<string> possibleMoves;
	vector<string> gameMoves;
	string tmpMove;

public:

	Game();
	virtual ~Game() {}
	void update();
	void render();
	void startingPosition();
	const RenderWindow& getWindow() const;

	bool isLegal(string tmpMove);

	void checkMoves();
	void checkRook(Piece tmp);
	void checkPawn(Piece tmp);
	void checkBishop(Piece tmp);
	void checkKnight(Piece tmp);
	void checkKing(Piece tmp);
	void checkQueen(Piece tmp);
	Piece checkPiece(int x, int y);
};