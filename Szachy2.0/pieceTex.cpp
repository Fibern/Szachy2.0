#include "pieceTex.h"

// £adowanie tekstur bierek szachowych
Texture PieceTex::loadTex(string s) //Funkcja pozwalaj¹ca na za³adowanie tekstur
{
	Texture t;
	if (!t.loadFromFile(s))
		cout << "Couldn't load texture!" << endl;
	return t;
}

//£adowanie tekstur
Texture PieceTex::bK = PieceTex::loadTex("images/kingb.png");
Texture PieceTex::bQ = PieceTex::loadTex("images/queenb.png");
Texture PieceTex::bR = PieceTex::loadTex("images/rookb.png");
Texture PieceTex::bB = PieceTex::loadTex("images/bishopb.png");
Texture PieceTex::bN = PieceTex::loadTex("images/knightb.png");
Texture PieceTex::bP = PieceTex::loadTex("images/pawnb.png");

Texture PieceTex::wK = PieceTex::loadTex("images/kingw.png");
Texture PieceTex::wQ = PieceTex::loadTex("images/queenw.png");
Texture PieceTex::wR = PieceTex::loadTex("images/rookw.png");
Texture PieceTex::wB = PieceTex::loadTex("images/bishopw.png");
Texture PieceTex::wN = PieceTex::loadTex("images/knightw.png");
Texture PieceTex::wP = PieceTex::loadTex("images/pawnw.png");