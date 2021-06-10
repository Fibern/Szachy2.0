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

	void initWindow();
public:
	Game();
	virtual ~Game();
};

