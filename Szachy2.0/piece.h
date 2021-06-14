#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieceTex.h"

class Piece
{
private:

	void setTexture();
	char type{};
	bool color{};
	int x{}, y{};
	Sprite sprite;

public:

	Piece() {}
	virtual ~Piece() {}
	void set(float x, float y) { sprite.setPosition(x, y); }
	Sprite getSprite() { return sprite; }
	void setPiece(char type, bool color, int x, int y);

};
