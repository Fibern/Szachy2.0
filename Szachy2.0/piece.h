#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "pieceTex.h"

class Piece
{
private:

	void setTexture();
	char type{}; //K - Król, Q - Hetman, R - Wie¿a, B - Goniec, N - Skoczek, P - Pion
	bool color{}; //0 - czarny, 1 - bia³y
	int x{}, y{};
	Sprite sprite;
	bool set = 0; //Zapisuje, czy figura jest wyœwietlana
	bool enPassant = 0; //Zapisuje, czy jest mo¿liwe bicie w przelocie
	bool promotion = 0; //Zapisuje, czy jest mo¿liwa promocja piona
	bool castle = 0; //Zapisuje, czy jest mo¿liwa roszada
	string s1, s2, typeStr; //Stringi do zapisu ruchu

public:

	Piece() {} //Konstruktor
	virtual ~Piece() {} //Destruktor

	void changeSet(bool set) { this->set = set; } //Funkcja do zmiany wyœwietlenia figury
	void changeColor(bool color) { this->color = color; } //Funkcja ustawiaj¹ca kolor figury
	void setPos(float x, float y) { sprite.setPosition(x, y); } //Funkcja ustawiaj¹ca pozycjê figury
	void setPieceType(char type); //Funkcja ustawiaj¹ca typ figury
	void setPiece(char type, bool color, int x, int y); //Funkcja ustawiaj¹ca figurê
	void setEnPassant(bool z) { this->enPassant = z; } //Funkcja ustawiaj¹ca bicie w przelocie
	void scale(float a, float b) { this->sprite.setScale(a, b); } //Funkcja skaluj¹ca rozmiar figury

	//Funkcje zwracaj¹ce
	Sprite getSprite() { return sprite; }
	char getType() { return type; }
	int getX() { return x; }
	int getY() { return y; }
	bool getColor() { return color; }
	bool getSet() { return set; }
	bool getEnPassant() { return enPassant; }
	bool getPromotion() { return promotion; }
	bool getCastle() { return castle; }

	void promoted(char type); //Funkcja do promowania piona
	void updateCord(float x, float y); //Funkcja aktualizuj¹ca pozycje figury
	string cordToString(int x, int y); //Funkcja tworz¹ca ruch do zapisu
};
