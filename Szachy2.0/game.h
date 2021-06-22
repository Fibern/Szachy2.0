#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include "piece.h"

using namespace sf;


class Game
{
private:

	Piece white[16]; //Tablica dla bia�ych figur
	Piece black[16]; //Tablica dla czarnych figur
	Piece promotionWhite[4]; //Tablica z bia�ymi figurami do promowania (hetman, wie�a, goniec, skoczek)
	Piece promotionBlack[4]; //Tablica z czarnymi figurami do promowania (hetman, wie�a, goniec, skoczek)
	RenderWindow window; //Okno z gr�
	int windowState; //0 - gra, 1 - menu, 2 - menu gry, 3 - wygrana bialych, 4 - wygrana czarnych, 5 - remis, 6 - zapis, 7 - wczytywanie
	
	void initWindow(); //Funkcja inicjazlizuj�ca okno
	void setPromotionPieces(); //Funkcja przypisuj�ca promowane figury

	Event e; //Zmienna zdarze�
	Font font; //Zmienna do czcionki
	Text textMenu[3]; //Teksty menu
	Text textGameMenu[3]; //Teksty menu w trakcie gry
	Text textAfterGameMenu[5]; //Teksty menu po zako�czeniu gry
	Text textSL[6]; //Teksty menu zapisywania/wczytywania
	String playerInput; //Zmienna zapisuj�ca tekst wpisywany przy zapisie/wczytywaniu
	Texture boardt; //Tekstura t�a menu
	Sprite board; //Sprite z tekstur� t�a menu
	Texture logot; //Tekstura logo gry
	Sprite logo; //Sprite z logiem gry
	
	void initBoard(); //Funkcja inicjalizuj�ca plansz� gry
	void drawBoard(); //Funkcja rysuj�ca plansz� gry
	bool dragging[16]{}; //Tablica z informacjami o mo�liwo�ci przeci�gania figur

	bool player; //0 - czarny gracz, 1 - bia�y gracz
	IntRect bounds; //Przechowuje informacje o wsp�rz�dnych wierzcho�k�w sprit�w
	vector<string> possibleMovesWhite{}; //Tablica z mo�liwymi ruchami dla bia�ych
	vector<string> possibleMovesBlack{}; //Tablica z mo�liwymi ruchami dla czarnych
	vector<string> gameMoves; //Tablica z wykonanymi ruchami w trakcie gry
	string tmpMove; //Pomocnicza zmienna dla ruchu

	float dx{}, dy{}; //Zmienne pomocnicze do funkcji 
	int x{}, y{}; //Zmienne pomocnicze do funkcji 
	Vector2i pos{}; //Wektor przekazuj�cy pozycje
	char type; //Zmienna pomocnicza zawieraj�ca typ figury
	Piece tmp, tmpM, tmpP, p, pinned; //Zmienne z figurami do funkcji
	bool tmpSet{}; //Zmienna pomocnicza do funkcji checkPiece
	bool promotion = 0; //Zmienna pomocnicza do funkcji promuj�cej piony
	bool check = 0; //Zmienna przechowuj�ca informacje o szachu

	//Zmienne pomocnicze do zapisywania i wczytywania partii
	ifstream fileL;
	string tmpMoveL;
	int counterFileL = 0;
	int counterL = 0;
	ofstream fileS;

public:

	Game(); //Konstruktor
	virtual ~Game() {} //Destruktor
	void updateWindow(); //Funkcja aktualizuj�ca okno
	void renderWindow(); //Funkcja wy�wietlaj�ca okno
	void startingPosition(); //Funkcja ustawiaj�ca startow� pozycj� bierek na szachownicy

	void initBackgroundMenu(); //Funkcja inicjalizuj�ca t�o menu
	void initTextMenu(); //Funkcja inicjalizuj�ca napisy w menu
	void drawMenu(); //Funkcja rysuj�ca menu
	void updateWindowMenu(); //Funkcja wczytuj�ca menu

	void initTextGameMenu(); //Funkcja inicjalizuj�ca napisy w menu gry
	void drawGameMenu(); //Funkcja rysuj�ca menu gry
	void updateWindowGameMenu(); //Funkcja wczytuj�ca menu gry

	void initTextAfterGameMenu(); //Funkcja inicjalizuj�ca napisy w menu po zako�czeniu gry
	void drawAfterGameMenu(); //Funkcja rysuj�ca menu po zako�czeniu gry
	void updateWindowAfterGameMenu(); //Funkcja wczytuj�ca menu po zako�czeniu gry

	void initTextSL(); //Funkcja inicjalizuj�ca napisy w menu zapisywania/wczytywania
	void drawSL(); //Funkcja rysuj�ca menu zapisywania/wczytywania
	void updateWindowSL(); //Funkcja wczytuj�ca menu zapisywania/wczytywania

	bool isLegal(string tmpMove); //Funkcja sprawdzaj�ca legalno�� ruchu
	void takes(int x, int y); //Funkcja usuwaj�ca zbit� figure
	void updateMoves(int x, int y, int i); //Funkcja wpisuj�ca wykonane ruchy
	void updatePromotion(int i); //Funkcja wpisuj�ca wykonan� promocj� piona
	void clearEnPassant(); //Funkcja czyszcz�ca bicie w przelocie

	//Funkcje sprawdzaj�ce mo�liwe do wykonania ruchy oraz ich poprawno��
	void checkMoves();
	void checkRook(Piece tmp);
	void checkPawn(Piece tmp);
	void checkBishop(Piece tmp);
	void checkKnight(Piece tmp);
	void checkKing(Piece tmp);
	void checkQueen(Piece tmp);
	void checkCastle(Piece tmp);
	void checkPin(Piece tmp);
	void checkCheck(Piece tmp);
	void clearCheck(char xK, char yK, char xC, char yC);
	void checkAttacked();
	void checkPromotion(int i);
	
	void checkGameEnd(); //Funkcja sprawdzaj�ca czy gra si� zako�czy�a oraz z jakim wynikiem

	Piece checkPiece(int x, int y); //Funkcja sprawdzaj�ca czy na danej pozycji znajduje si� figura

	void saveFile(String s); //Funkcja zapisuj�ca parti� do pliku
	void loadFile(String s); //Funkcja wczytuj�ca parti� z pliku
	void loadMoves(); //Funkcja wykonuj�ca za�adowane ruchy

	const RenderWindow& getWindow() const { return this->window; } //Funkcja zwracaj�ca okno
	int getWindowState() { return windowState; } //Funkcja zwracaj�ca stan okna
};