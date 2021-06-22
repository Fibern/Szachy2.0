#include "piece.h"
#include "pieceTex.h"

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
		break;
	}
}

void Piece::setPieceType(char type) 
{
	this->type = type;
	this->setTexture();
}

void Piece::setPiece(char type, bool color, int x, int y)
{
	this->color = color;
	this->setPieceType(type);
	if (this->type == 'K' || this->type == 'R')
		this->castle = 1;
	this->x = x;
	this->y = y;
	this->sprite.setPosition(x * 100.f, y * 100.f);
	this->set = 1;
}

void Piece::promoted(char type)
{
	this->setPieceType(type);
	this->set = 1;
	this->promotion = 0;
}

void Piece::updateCord(float x, float y) 
{
	this->x = (int)x;
	this->y = (int)y;

	if (this->type == 'P' && ((this->color && this->y == 0) || (!this->color && this->y == 7))) {
		this->promotion = 1;
	}

	if (this->type == 'K' || this->type == 'R')
		this->castle = 0;

}

string Piece::cordToString(int x, int y) 
{
	this->typeStr = this->type;
	this->s1 = this->typeStr;
	this->s1 += static_cast<char>(this->x) + 'a';
	this->s1 += to_string(8 - this->y);
	this->s2 = static_cast<char>(x) + 'a';
	this->s2 += to_string(8 - y);
	return s1 + s2;
}

