#include "pieceTex.h"

// £adowanie tekstur bierek szachowych
Texture loadTex(string s) //Funkcja pozwalaj¹ca na za³adowanie tekstur
{
	Texture t;
	if (t.loadFromFile(s))
		cout << "Couldn't load texture!" << endl;
	return t;
}

//£adowanie tekstur
Texture PieceTex::bK = PieceTex::loadTex("images/kingB");
Texture PieceTex::bQ = PieceTex::loadTex("images/queenB");
Texture PieceTex::bR = PieceTex::loadTex("images/rookB");
Texture PieceTex::bB = PieceTex::loadTex("images/bishopB");
Texture PieceTex::bN = PieceTex::loadTex("images/knightB");
Texture PieceTex::bP = PieceTex::loadTex("images/pawnB");

Texture PieceTex::wK = PieceTex::loadTex("images/kingW");
Texture PieceTex::wQ = PieceTex::loadTex("images/queenW");
Texture PieceTex::wR = PieceTex::loadTex("images/rookW");
Texture PieceTex::wB = PieceTex::loadTex("images/bishopW");
Texture PieceTex::wN = PieceTex::loadTex("images/knightW");
Texture PieceTex::wP = PieceTex::loadTex("images/pawnW");