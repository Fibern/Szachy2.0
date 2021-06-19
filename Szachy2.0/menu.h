#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;
class Menu
{
private:
	int selectIndex;
	Font font;
	Text text[4];

public:
	Menu(float width, float height);
	~Menu() {}

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

};

