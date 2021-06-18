#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "piece.h"

using namespace sf;
using namespace std;

class Game
{
private:
	
	Piece white[16];
	Piece black[16];
	Piece tmp;
	Piece promotionWhite[4];
	Piece promotionBlack[4];
	RenderWindow window;
	void initWindow();
	void setPromotionPieces();

	Event e;
	Texture boardt;
	Sprite board;
	void initBoard();
	void drawBoard();
	bool dragging[16]{};

	bool player;
	IntRect bounds;
	vector<string> possibleMovesWhite{};
	vector<string> possibleMovesBlack{};
	vector<string> gameMoves;
	string tmpMove;

	float dx{}, dy{};
	int x{}, y{};
	Vector2i pos{};
	char type;
	Piece tmpM, tmpP, p;
	bool tmpSet{};
	bool promotion = 0;

	
public:

	Game();
	virtual ~Game() {}
	void updateWindow();
	void renderWindow();
	void startingPosition();
	const RenderWindow& getWindow() const;

	bool isLegal(string tmpMove);
	void takes(int x ,int y);
	void updateMoves(int x, int y, int i);
	void updatePromotion(int i);
	void clearEnPassant();

	void checkMoves();
	void checkRook(Piece tmp);
	void checkPawn(Piece tmp);
	void checkBishop(Piece tmp);
	void checkKnight(Piece tmp);
	void checkKing(Piece tmp);
	void checkQueen(Piece tmp);
	Piece checkPiece(int x, int y);
	void checkAttacked();
	void checkPromotion(int i);
};