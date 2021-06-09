#pragma once
class Piece
{
private:
	int row, col;
	bool color;
	char id;
public:
	Piece(int row, int col);
	~Piece();
};

