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
//	int row, col;
//	bool color;
//  Sprite s
//	char id;
public:

	Sprite sprite;

//	Piece(int row, int col, bool color, char id, Sprite s);
//	void Update();
	Piece() 
	{
		type = 'K';
		this->setTexture();
	}
	~Piece();
};
//
