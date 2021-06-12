#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>
#include "piece.h"

using namespace sf;
using namespace std;

class Game
{
private:

	Piece white[16];

	RenderWindow window;
	void initWindow();

	Event e;	
	Texture boardt;
	Sprite board;
	void initBoard();
	void drawBoard();

public:

	Game();
	virtual ~Game();
	void update();
	void render();
	void startingPosition();
	const RenderWindow& getWindow() const;
};