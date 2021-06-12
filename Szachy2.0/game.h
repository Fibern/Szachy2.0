#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>
#include "piece.h"
#include <array>
#include <vector>

using namespace sf;
using namespace std;

class Game
{
private:

	Piece white;
	RenderWindow window;
	void initWindow();

	Event e;	
	Texture boardt;
	Sprite board;
	void initBoard();
	void drawBoard();
	bool dragging = 0;

public:

	Game();
	virtual ~Game();
	void update();
	void render();
	void startingPosition();
	const RenderWindow& getWindow() const;
};