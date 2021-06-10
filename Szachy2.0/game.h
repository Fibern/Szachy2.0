#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

class Game
{
private:
	RenderWindow window;
	Event e;
	void initWindow();
	Texture boardt;
	Sprite board;
	void initBoard();


public:

	Game();
	void update();
	virtual ~Game();
	void drawBoard();
	const RenderWindow& getWindow() const;
	void render();
};

