#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

//Ładowanie tekstur bierek szachowych
class PieceTex
{
public:

	static Texture bK, bQ, bR, bB, bN, bP;
	static Texture wK, wQ, wR, wB, wN, wP;

	static Texture loadTex(string s); //Funkcja pozwalająca na załadowanie tekstur
};

