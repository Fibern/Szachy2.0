#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieceTex.h"

class Piece 
{
private:

	void setTexture();
	char type;
	bool color;
	int x, y;
//	int row, col;
//	bool color;
//  Sprite s
//	char id;
public:

	Sprite sprite;

	Piece() {}
	void setPiece(char type, bool color, int x, int y);
	~Piece();
};

