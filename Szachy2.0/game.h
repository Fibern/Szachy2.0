#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "piece.h"
#include <windows.h>

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
	int windowState; //0 - gra, 1 - menu, 2 - menu gry, 3 - wygrana bialych, 4 - wygrana czarnych, 5 - remis, 6 - zapis, 7 - wczytywanie
	void initWindow();
	void setPromotionPieces();

	Event e;
	Font font;
	Text textMenu[3];
	Text textGameMenu[3];
	Text textAfterGameMenu[5];
	Text textSL[6];
	String playerInput;
	Texture boardt;
	Sprite board;
	Texture logot;
	Sprite logo;
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
	Piece tmpM, tmpP, p, pinned;
	bool tmpSet{};
	bool promotion = 0;
	bool check = 0;
	int gameEnd = 0;

	ifstream fileL;
	string tmpMoveL;
	int counterFileL = 0;
	int counterL = 0;

	ofstream fileS;

public:

	Game();
	virtual ~Game() {}
	void updateWindow();
	void renderWindow();
	void startingPosition();
	const RenderWindow& getWindow() const;

	void initBackgroundMenu();
	void initTextMenu();
	void drawMenu();
	void updateWindowMenu();

	void initTextGameMenu();
	void drawGameMenu();
	void updateWindowGameMenu();

	void initTextAfterGameMenu();
	void drawAfterGameMenu();
	void updateWindowAfterGameMenu();

	void initTextSL();
	void drawSL();
	void updateWindowSL();

	bool isLegal(string tmpMove);
	void takes(int x, int y);
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
	void checkCastle(Piece tmp);
	void checkPin(Piece tmp);
	void checkCheck(Piece tmp);
	void clearCheck(char xK, char yK, char xC, char yC);
	Piece checkPiece(int x, int y);
	void checkAttacked();
	void checkPromotion(int i);
	void checkGameEnd();

	void saveFile(String s);
	void loadFile(String s);
	void loadMoves();

	int getWindowState() { return windowState; }
};