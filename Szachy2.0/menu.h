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
	Texture boardt;
	Sprite board;
	RenderWindow window;
	Event e;
	Vector2i pos{};

public:
	Menu();
	virtual ~Menu() {}

	void moveUp();
	void moveDown();
	void initWindow();
	void initBackground();
	void initText();
	void drawBackground();
	void drawText();
	void updateWindow();
	void renderWindow();
	const RenderWindow& getWindow() const;
};

