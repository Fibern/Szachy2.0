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

	Piece white[16]; //Tablica dla bia³ych figur
	Piece black[16]; //Tablica dla czarnych figur
	Piece promotionWhite[4]; //Tablica z bia³ymi figurami do promowania (hetman, wie¿a, goniec, skoczek)
	Piece promotionBlack[4]; //Tablica z czarnymi figurami do promowania (hetman, wie¿a, goniec, skoczek)
	RenderWindow window; //Okno z gr¹
	int windowState; //0 - gra, 1 - menu, 2 - menu gry, 3 - wygrana bialych, 4 - wygrana czarnych, 5 - remis, 6 - zapis, 7 - wczytywanie
	
	void initWindow(); //Funkcja inicjazlizuj¹ca okno
	void setPromotionPieces(); //Funkcja przypisuj¹ca promowane figury

	Event e; //Zmienna zdarzeñ
	Font font; //Zmienna do czcionki
	Text textMenu[3]; //Teksty menu
	Text textGameMenu[3]; //Teksty menu w trakcie gry
	Text textAfterGameMenu[5]; //Teksty menu po zakoñczeniu gry
	Text textSL[6]; //Teksty menu zapisywania/wczytywania
	String playerInput; //Zmienna zapisuj¹ca tekst wpisywany przy zapisie/wczytywaniu
	Texture boardt; //Tekstura t³a menu
	Sprite board; //Sprite z tekstur¹ t³a menu
	Texture logot; //Tekstura logo gry
	Sprite logo; //Sprite z logiem gry
	
	void initBoard(); //Funkcja inicjalizuj¹ca planszê gry
	void drawBoard(); //Funkcja rysuj¹ca planszê gry
	bool dragging[16]{}; //Tablica z informacjami o mo¿liwoœci przeci¹gania figur

	bool player; //0 - czarny gracz, 1 - bia³y gracz
	IntRect bounds; //Przechowuje informacje o wspó³rzêdnych wierzcho³ków spritów
	vector<string> possibleMovesWhite{}; //Tablica z mo¿liwymi ruchami dla bia³ych
	vector<string> possibleMovesBlack{}; //Tablica z mo¿liwymi ruchami dla czarnych
	vector<string> gameMoves; //Tablica z wykonanymi ruchami w trakcie gry
	string tmpMove; //Pomocnicza zmienna dla ruchu

	float dx{}, dy{}; //Zmienne pomocnicze do funkcji 
	int x{}, y{}; //Zmienne pomocnicze do funkcji 
	Vector2i pos{}; //Wektor przekazuj¹cy pozycje
	char type; //Zmienna pomocnicza zawieraj¹ca typ figury
	Piece tmp, tmpM, tmpP, p, pinned; //Zmienne z figurami do funkcji
	bool tmpSet{}; //Zmienna pomocnicza do funkcji checkPiece
	bool promotion = 0; //Zmienna pomocnicza do funkcji promuj¹cej piony
	bool check = 0; //Zmienna przechowuj¹ca informacje o szachu

	//Zmienne pomocnicze do zapisywania i wczytywania partii
	ifstream fileL;
	string tmpMoveL;
	int counterFileL = 0;
	int counterL = 0;
	ofstream fileS;

public:

	Game(); //Konstruktor
	virtual ~Game() {} //Destruktor
	void updateWindow(); //Funkcja aktualizuj¹ca okno
	void renderWindow(); //Funkcja wyœwietlaj¹ca okno
	void startingPosition(); //Funkcja ustawiaj¹ca startow¹ pozycjê bierek na szachownicy

	void initBackgroundMenu(); //Funkcja inicjalizuj¹ca t³o menu
	void initTextMenu(); //Funkcja inicjalizuj¹ca napisy w menu
	void drawMenu(); //Funkcja rysuj¹ca menu
	void updateWindowMenu(); //Funkcja wczytuj¹ca menu

	void initTextGameMenu(); //Funkcja inicjalizuj¹ca napisy w menu gry
	void drawGameMenu(); //Funkcja rysuj¹ca menu gry
	void updateWindowGameMenu(); //Funkcja wczytuj¹ca menu gry

	void initTextAfterGameMenu(); //Funkcja inicjalizuj¹ca napisy w menu po zakoñczeniu gry
	void drawAfterGameMenu(); //Funkcja rysuj¹ca menu po zakoñczeniu gry
	void updateWindowAfterGameMenu(); //Funkcja wczytuj¹ca menu po zakoñczeniu gry

	void initTextSL(); //Funkcja inicjalizuj¹ca napisy w menu zapisywania/wczytywania
	void drawSL(); //Funkcja rysuj¹ca menu zapisywania/wczytywania
	void updateWindowSL(); //Funkcja wczytuj¹ca menu zapisywania/wczytywania

	bool isLegal(string tmpMove); //Funkcja sprawdzaj¹ca legalnoœæ ruchu
	void takes(int x, int y); //Funkcja usuwaj¹ca zbit¹ figure
	void updateMoves(int x, int y, int i); //Funkcja wpisuj¹ca wykonane ruchy
	void updatePromotion(int i); //Funkcja wpisuj¹ca wykonan¹ promocjê piona
	void clearEnPassant(); //Funkcja czyszcz¹ca bicie w przelocie

	//Funkcje sprawdzaj¹ce mo¿liwe do wykonania ruchy oraz ich poprawnoœæ
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
	
	void checkGameEnd(); //Funkcja sprawdzaj¹ca czy gra siê zakoñczy³a oraz z jakim wynikiem

	Piece checkPiece(int x, int y); //Funkcja sprawdzaj¹ca czy na danej pozycji znajduje siê figura

	void saveFile(String s); //Funkcja zapisuj¹ca partiê do pliku
	void loadFile(String s); //Funkcja wczytuj¹ca partiê z pliku
	void loadMoves(); //Funkcja wykonuj¹ca za³adowane ruchy

	const RenderWindow& getWindow() const { return this->window; } //Funkcja zwracaj¹ca okno
	int getWindowState() { return windowState; } //Funkcja zwracaj¹ca stan okna
};