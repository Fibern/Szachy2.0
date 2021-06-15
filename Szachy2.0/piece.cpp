#include "piece.h"
#include "pieceTex.h"

void Piece::setPiece(char type, bool color, int x, int y)
{
	this->type = type;
	this->color = color;
	this->x = x;
	this->y = y;
	this->setTexture();
	this->sprite.setPosition(x * 100.f, y * 100.f);
	this->set = 1;
}

void Piece::setTexture()
{

	switch (type) {
	case 'K':
		sprite.setTexture(color ? PieceTex::wK : PieceTex::bK);
		break;
	case 'Q':
		sprite.setTexture(color ? PieceTex::wQ : PieceTex::bQ);
		break;
	case 'R':
		sprite.setTexture(color ? PieceTex::wR : PieceTex::bR);
		break;
	case 'B':
		sprite.setTexture(color ? PieceTex::wB : PieceTex::bB);
		break;
	case 'N':
		sprite.setTexture(color ? PieceTex::wN : PieceTex::bN);
		break;
	case 'P':
		sprite.setTexture(color ? PieceTex::wP : PieceTex::bP);
		break;
	default:
		cerr << "ERROR: Piece type does not exist." << endl;
		break;
	}

}

void Piece::updateCord(float x, float y) {
	this->x = (int)x;
	this->y = (int)y;
}

string Piece::cordToString(int x, int y) {
	string s1, s2, type;
	type = this->type;
	s1 = type;
	s1 += static_cast<char>(this->x) + 'a';
	s1 += to_string(8 - this->y);
	s2 = static_cast<char>(x) + 'a';
	s2 += to_string(8 - y);
	return s1 + s2;
}

