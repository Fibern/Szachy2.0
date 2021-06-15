#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "pieceTex.h"

class Piece
{
private:

	void setTexture();
	char type{};
	bool color{};
	int x{}, y{};
	Sprite sprite;
	bool set = 0;
	bool enPassant = 0;

public:

	Piece() {}
	virtual ~Piece() {}

	void taken() { set = 0; }
	void setPos(float x, float y) { sprite.setPosition(x, y); }
	void setPiece(char type, bool color, int x, int y);
	void setEnPassant(bool z) { this->enPassant = z; }

	Sprite getSprite() { return sprite; }
	char getType() { return type; }
	int getX() { return x; }
	int getY() { return y; }
	bool getColor() { return color; }
	bool getSet() { return set; }
	bool getEnPassant() { return enPassant; }

	void updateCord(float x, float y);
	string cordToString(int x, int y);

};
