//#include "piece.h"
//
//Piece::Piece(int row, int col, bool color, char id, Sprite s)
//{
//	this->row = row;
//	this->col = col;
//	this->color = color;
//	this->id = id;
//	this->s = s;
//}
//
//void Update()
//{
//	Vector2i pos = Mouse::getPosition(window);
//
//	if (e.type == Event::MouseButtonPressed) {
//		if (e.key.code == Mouse::Left) {
//			if (pawnw.getGlobalBounds().contains(pos.x, pos.y))
//				isMove = 1;
//		}
//	}
//
//	if (e.type == Event::MouseButtonReleased) {
//		if (e.key.code == Mouse::Left && isMove) {
//			isMove = 0;
//			dx = (float)floor(pos.x / 100) * 100;
//			dy = (float)floor(pos.y / 100) * 100;
//			pawnw.setPosition(dx, dy);
//		}
//	}
//
//	if (isMove)
//		pawnw.setPosition(pos.x - (float)50, pos.y - (float)50);
//}
//
//Piece::~Piece()
//{
//
//}