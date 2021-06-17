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
	bool promotion = 0;
	string s1, s2, typeStr;

public:

	Piece() {}
	virtual ~Piece() {}

	void changeSet(bool set) { this->set = set; }
	void changeColor(bool color) { this->color = color; }
	void setPos(float x, float y) { sprite.setPosition(x, y); }
	void setPieceType(char type);
	void setPiece(char type, bool color, int x, int y);
	void setEnPassant(bool z) { this->enPassant = z; }
	void scale(float a, float b) { this->sprite.setScale(a, b); }

	Sprite getSprite() { return sprite; }
	char getType() { return type; }
	int getX() { return x; }
	int getY() { return y; }
	bool getColor() { return color; }
	bool getSet() { return set; }
	bool getEnPassant() { return enPassant; }
	bool getPromotion() { return promotion; }

	void promoted(char type);
	void updateCord(float x, float y);
	string cordToString(int x, int y);

};
