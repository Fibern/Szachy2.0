#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieceTex.h"
//#include <time.h>
//#include <math.h>
//
//using namespace sf;
//using namespace std;
//
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

//	Piece(int row, int col, bool color, char id, Sprite s);
//	void Update();
	Piece() {}
	void setPiece(char type, bool color, int x, int y);
	~Piece();
};
//
