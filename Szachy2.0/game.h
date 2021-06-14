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

public:

	Game();
	virtual ~Game() {}
	void update();
	void render();
	void startingPosition();
	const RenderWindow& getWindow() const;

	bool isLegal(Piece piece);
	string cordToString(string s1, string s2);
};