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

