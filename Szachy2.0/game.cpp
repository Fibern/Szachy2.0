#include "game.h"
#include "piece.h"

Game::Game()
{
	this->player = 1;
	this->windowState = 1;

	this->initWindow();
	this->initBoard();
	this->startingPosition();
	this->checkMoves();
	this->setPromotionPieces();

	this->initBackgroundMenu();
	this->initTextMenu();

	this->initTextGameMenu();

	this->initTextAfterGameMenu();

	this->initTextSL();
	//for (int i = 0; i < (int)possibleMovesWhite.size(); i++)
	//	cout << possibleMovesWhite[i] << endl;
}

void Game::setPromotionPieces() {
	promotionWhite[0].setPiece('Q', 1, 0, 0);
	promotionWhite[1].setPiece('R', 1, 0, 0);
	promotionWhite[2].setPiece('B', 1, 0, 0);
	promotionWhite[3].setPiece('N', 1, 0, 0);
	promotionWhite[0].changeSet(0);
	promotionWhite[1].changeSet(0);
	promotionWhite[2].changeSet(0);
	promotionWhite[3].changeSet(0);
	promotionWhite[0].scale(0.5f, 0.5f);
	promotionWhite[1].scale(0.5f, 0.5f);
	promotionWhite[2].scale(0.5f, 0.5f);
	promotionWhite[3].scale(0.5f, 0.5f);

	promotionBlack[0].setPiece('Q', 0, 0, 0);
	promotionBlack[1].setPiece('R', 0, 0, 0);
	promotionBlack[2].setPiece('B', 0, 0, 0);
	promotionBlack[3].setPiece('N', 0, 0, 0);
	promotionBlack[0].changeSet(0);
	promotionBlack[1].changeSet(0);
	promotionBlack[2].changeSet(0);
	promotionBlack[3].changeSet(0);
	promotionBlack[0].scale(0.5f, 0.5f);
	promotionBlack[1].scale(0.5f, 0.5f);
	promotionBlack[2].scale(0.5f, 0.5f);
	promotionBlack[3].scale(0.5f, 0.5f);
}

void Game::initWindow()
{
	this->window.create(VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBackgroundMenu()
{
	if (!this->boardt.loadFromFile("images/brown.png"))
		cout << "Can't load board texture!" << endl;
	this->boardt.setRepeated(true);
	this->board.setTextureRect({ 0, 0, 800, 800 });
	this->board.setTexture(this->boardt);
}

void Game::initTextMenu()
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;

	textMenu[0].setFont(font);
	textMenu[0].setFillColor(Color::Black);
	textMenu[0].setString("Play!");
	textMenu[0].setPosition(Vector2f(800 / 2 - 30.f, 800 / 8 * 4));

	textMenu[1].setFont(font);
	textMenu[1].setFillColor(Color::Black);
	textMenu[1].setString("Load game");
	textMenu[1].setPosition(Vector2f(800 / 2 - 67.f, 800 / 8 * 5));

	textMenu[2].setFont(font);
	textMenu[2].setFillColor(Color::Black);
	textMenu[2].setString("Exit");
	textMenu[2].setPosition(Vector2f(800 / 2 - 30.f, 800 / 8 * 6));
}

void Game::drawMenu()
{
	this->window.draw(board);
	for (int i = 0; i < 3; i++)
		this->window.draw(textMenu[i]);
	this->logot.loadFromFile("images/logo.png");
	this->logo.setTexture(this->logot);
	this->window.draw(logo);
	logo.setPosition(Vector2f(200, 100));
}

void Game::updateWindowMenu()
{
	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseMoved)
		{
			if (Mouse::getPosition(window).x >= textMenu[0].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[0].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[0].getGlobalBounds().left + textMenu[0].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[0].getGlobalBounds().top + textMenu[0].getGlobalBounds().height + 5)
				textMenu[0].setFillColor(Color::White);
			else if (Mouse::getPosition(window).x >= textMenu[1].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[1].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[1].getGlobalBounds().left + textMenu[1].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[1].getGlobalBounds().top + textMenu[1].getGlobalBounds().height + 5)
				textMenu[1].setFillColor(Color::White);
			else if (Mouse::getPosition(window).x >= textMenu[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[2].getGlobalBounds().left + textMenu[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[2].getGlobalBounds().top + textMenu[2].getGlobalBounds().height + 5)
				textMenu[2].setFillColor(Color::White);
			else
			{
				textMenu[0].setFillColor(Color::Black);
				textMenu[1].setFillColor(Color::Black);
				textMenu[2].setFillColor(Color::Black);
			}
		}

		if (e.type == Event::MouseButtonPressed)
			if (Mouse::getPosition(window).x >= textMenu[0].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[0].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[0].getGlobalBounds().left + textMenu[0].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[0].getGlobalBounds().top + textMenu[0].getGlobalBounds().height + 5)
				windowState = 0;
			else if (Mouse::getPosition(window).x >= textMenu[1].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[1].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[1].getGlobalBounds().left + textMenu[1].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[1].getGlobalBounds().top + textMenu[1].getGlobalBounds().height + 5) {
				windowState = 7;
				playerInput = "";
				textSL[1].setString("");
			}
			else if (Mouse::getPosition(window).x >= textMenu[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textMenu[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textMenu[2].getGlobalBounds().left + textMenu[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textMenu[2].getGlobalBounds().top + textMenu[2].getGlobalBounds().height + 5)
				this->window.close();
	}
}

void Game::initTextGameMenu()
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;

	textGameMenu[0].setFont(font);
	textGameMenu[0].setFillColor(Color::Black);
	textGameMenu[0].setString("Resume");
	textGameMenu[0].setPosition(Vector2f(800 / 2 - 50.f, 800 / 8 * 4));

	textGameMenu[1].setFont(font);
	textGameMenu[1].setFillColor(Color::Black);
	textGameMenu[1].setString("Save game");
	textGameMenu[1].setPosition(Vector2f(800 / 2 - 67.f, 800 / 8 * 5));

	textGameMenu[2].setFont(font);
	textGameMenu[2].setFillColor(Color::Black);
	textGameMenu[2].setString("Exit");
	textGameMenu[2].setPosition(Vector2f(800 / 2 - 30.f, 800 / 8 * 6));
}

void Game::drawGameMenu()
{
	this->window.draw(board);
	for (int i = 0; i < 3; i++)
		this->window.draw(textGameMenu[i]);
	this->logot.loadFromFile("images/logo.png");
	this->logo.setTexture(this->logot);
	this->window.draw(logo);
	logo.setPosition(Vector2f(200, 100));
}

void Game::updateWindowGameMenu()
{
	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseMoved)
		{
			if (Mouse::getPosition(window).x >= textGameMenu[0].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[0].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[0].getGlobalBounds().left + textGameMenu[0].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[0].getGlobalBounds().top + textGameMenu[0].getGlobalBounds().height + 5)
				textGameMenu[0].setFillColor(Color::White);
			else if (Mouse::getPosition(window).x >= textGameMenu[1].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[1].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[1].getGlobalBounds().left + textGameMenu[1].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[1].getGlobalBounds().top + textGameMenu[1].getGlobalBounds().height + 5)
				textGameMenu[1].setFillColor(Color::White);
			else if (Mouse::getPosition(window).x >= textGameMenu[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[2].getGlobalBounds().left + textGameMenu[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[2].getGlobalBounds().top + textGameMenu[2].getGlobalBounds().height + 5)
				textGameMenu[2].setFillColor(Color::White);
			else
			{
				textGameMenu[0].setFillColor(Color::Black);
				textGameMenu[1].setFillColor(Color::Black);
				textGameMenu[2].setFillColor(Color::Black);
			}
		}

		if (e.type == Event::MouseButtonPressed)
			if (Mouse::getPosition(window).x >= textGameMenu[0].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[0].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[0].getGlobalBounds().left + textGameMenu[0].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[0].getGlobalBounds().top + textGameMenu[0].getGlobalBounds().height + 5)
				windowState = 0;
			else if (Mouse::getPosition(window).x >= textGameMenu[1].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[1].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[1].getGlobalBounds().left + textGameMenu[1].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[1].getGlobalBounds().top + textGameMenu[1].getGlobalBounds().height + 5) {
				windowState = 6;
				playerInput = "";
				textSL[1].setString("");
			}
			else if (Mouse::getPosition(window).x >= textGameMenu[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textGameMenu[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textGameMenu[2].getGlobalBounds().left + textGameMenu[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textGameMenu[2].getGlobalBounds().top + textGameMenu[2].getGlobalBounds().height + 5)
				this->window.close();
	}
}

void Game::initTextAfterGameMenu()
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;

	for (int i = 0; i < 3; i++) {
		textAfterGameMenu[i].setFont(font);
		textAfterGameMenu[i].setFillColor(Color::Black);
	}
	textAfterGameMenu[0].setString("1-0 White wins");
	textAfterGameMenu[0].setPosition(Vector2f(800 / 2 - 90.f, 800 / 8 * 4));
	textAfterGameMenu[1].setString("0-1 Black wins");
	textAfterGameMenu[1].setPosition(Vector2f(800 / 2 - 93.f, 800 / 8 * 4));
	textAfterGameMenu[2].setString("1/2-1/2 Draw");
	textAfterGameMenu[2].setPosition(Vector2f(800 / 2 - 85.f, 800 / 8 * 4));


	textAfterGameMenu[3].setFont(font);
	textAfterGameMenu[3].setFillColor(Color::Black);
	textAfterGameMenu[3].setString("Save game");
	textAfterGameMenu[3].setPosition(Vector2f(800 / 2 - 67.f, 800 / 8 * 5));

	textAfterGameMenu[4].setFont(font);
	textAfterGameMenu[4].setFillColor(Color::Black);
	textAfterGameMenu[4].setString("Exit");
	textAfterGameMenu[4].setPosition(Vector2f(800 / 2 - 30.f, 800 / 8 * 6));
}

void Game::drawAfterGameMenu()
{
	this->window.draw(board);
	for (int i = 0; i < 5; i++) {
		if (windowState == 3 && (i == 1 || i == 2))
			continue;
		else if (windowState == 4 && (i == 0 || i == 2))
			continue;
		else if (windowState == 5 && (i == 0 || i == 1))
			continue;
		this->window.draw(textAfterGameMenu[i]);
	}
	this->logot.loadFromFile("images/logo.png");
	this->logo.setTexture(this->logot);
	this->window.draw(logo);
	logo.setPosition(Vector2f(200, 100));
}

void Game::updateWindowAfterGameMenu()
{
	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseMoved)
		{
			if (Mouse::getPosition(window).x >= textAfterGameMenu[3].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textAfterGameMenu[3].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textAfterGameMenu[3].getGlobalBounds().left + textAfterGameMenu[3].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textAfterGameMenu[3].getGlobalBounds().top + textAfterGameMenu[3].getGlobalBounds().height + 5)
				textAfterGameMenu[3].setFillColor(Color::White);
			else if (Mouse::getPosition(window).x >= textAfterGameMenu[4].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textAfterGameMenu[4].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textAfterGameMenu[4].getGlobalBounds().left + textAfterGameMenu[4].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textAfterGameMenu[4].getGlobalBounds().top + textAfterGameMenu[4].getGlobalBounds().height + 5)
				textAfterGameMenu[4].setFillColor(Color::White);
			else
			{
				textAfterGameMenu[3].setFillColor(Color::Black);
				textAfterGameMenu[4].setFillColor(Color::Black);
			}
		}

		if (e.type == Event::MouseButtonPressed)
			if (Mouse::getPosition(window).x >= textAfterGameMenu[3].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textAfterGameMenu[3].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textAfterGameMenu[3].getGlobalBounds().left + textAfterGameMenu[3].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textAfterGameMenu[3].getGlobalBounds().top + textAfterGameMenu[3].getGlobalBounds().height + 5) {
				windowState = 6;
				playerInput = "";
				textSL[1].setString("");
			}
			else if (Mouse::getPosition(window).x >= textAfterGameMenu[4].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textAfterGameMenu[4].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textAfterGameMenu[4].getGlobalBounds().left + textAfterGameMenu[4].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textAfterGameMenu[4].getGlobalBounds().top + textAfterGameMenu[4].getGlobalBounds().height + 5)
				this->window.close();
	}
}

void Game::initTextSL()
{
	if (!font.loadFromFile("Comic_Sans.ttf"))
		cout << "Can't load font!" << endl;

	for (int i = 0; i < 6; i++) {
		textSL[i].setFont(font);
		textSL[i].setFillColor(Color::Black);
	}

	textSL[0].setString("Input file name:");
	textSL[0].setPosition(Vector2f(800 / 2 - 110.f, 800 / 8 * 4));

	textSL[1].setPosition(Vector2f(800 / 2 - 93.f, 800 / 8 * 5));

	textSL[2].setString("Save game");
	textSL[2].setPosition(Vector2f(800 / 2 - 67.f, 800 / 8 * 6));
	textSL[3].setString("Load game");
	textSL[3].setPosition(Vector2f(800 / 2 - 67.f, 800 / 8 * 6));

	textSL[4].setString("Back to game");
	textSL[4].setPosition(Vector2f(800 / 2 - 80.f, 800 / 8 * 7));

	textSL[5].setString("Back to menu");
	textSL[5].setPosition(Vector2f(800 / 2 - 84.f, 800 / 8 * 7));
}

void Game::drawSL()
{
	this->window.draw(board);
	for (int i = 0; i < 6; i++) {
		if (windowState == 6 && (i == 3 || i == 5))
			continue;
		else if (windowState == 7 && (i == 2 || i == 4))
			continue;
		this->window.draw(textSL[i]);
	}
	this->logot.loadFromFile("images/logo.png");
	this->logo.setTexture(this->logot);
	this->window.draw(logo);
	logo.setPosition(Vector2f(200, 100));
}

void Game::updateWindowSL()
{
	pos = Mouse::getPosition(window);

	//cout << playerInput.toAnsiString() << endl;

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();

		if (e.type == Event::MouseMoved)
		{
			if (windowState == 6 && Mouse::getPosition(window).x >= textSL[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[2].getGlobalBounds().left + textSL[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[2].getGlobalBounds().top + textSL[2].getGlobalBounds().height + 5)
				textSL[2].setFillColor(Color::White);
			else if (windowState == 7 && Mouse::getPosition(window).x >= textSL[3].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[3].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[3].getGlobalBounds().left + textSL[3].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[3].getGlobalBounds().top + textSL[3].getGlobalBounds().height + 5)
				textSL[3].setFillColor(Color::White);
			else if (windowState == 6 && Mouse::getPosition(window).x >= textSL[4].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[4].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[4].getGlobalBounds().left + textSL[4].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[4].getGlobalBounds().top + textSL[4].getGlobalBounds().height + 5)
				textSL[4].setFillColor(Color::White);
			else if (windowState == 7 && Mouse::getPosition(window).x >= textSL[5].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[5].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[5].getGlobalBounds().left + textSL[5].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[5].getGlobalBounds().top + textSL[5].getGlobalBounds().height + 5)
				textSL[5].setFillColor(Color::White);
			else
			{
				for (int i = 2; i < 6; i++)
					textSL[i].setFillColor(Color::Black);
			}
		}

		if (e.type == Event::TextEntered) {
			playerInput += e.text.unicode;
			textSL[1].setString(playerInput);
		}
		else if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
			if (playerInput.getSize() > 1)
				playerInput.erase(playerInput.getSize() - 1, 1);
			else {
				playerInput = "";
				textSL[1].setString("");
			}
		}

		if (playerInput.getSize() > 0)
			if (playerInput[playerInput.toAnsiString().length() - 1] == '\b')
				playerInput.erase(playerInput.getSize() - 1, 1);

		textSL[1].setString(playerInput);

		if (e.type == Event::MouseButtonPressed)
			if (windowState == 6 && Mouse::getPosition(window).x >= textSL[2].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[2].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[2].getGlobalBounds().left + textSL[2].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[2].getGlobalBounds().top + textSL[2].getGlobalBounds().height + 5) {
				saveFile(playerInput);
				windowState = 1;
			}
			else if (windowState == 7 && Mouse::getPosition(window).x >= textSL[3].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[3].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[3].getGlobalBounds().left + textSL[3].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[3].getGlobalBounds().top + textSL[3].getGlobalBounds().height + 5) {
				startingPosition();
				windowState = 0;
				loadFile(playerInput);
			}
			else if (windowState == 6 && Mouse::getPosition(window).x >= textSL[4].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[4].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[4].getGlobalBounds().left + textSL[4].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[4].getGlobalBounds().top + textSL[4].getGlobalBounds().height + 5)
				windowState = 0;
			else if (windowState == 7 && Mouse::getPosition(window).x >= textSL[5].getGlobalBounds().left - 5 && Mouse::getPosition(window).y >= textSL[5].getGlobalBounds().top - 5 && Mouse::getPosition(window).x < textSL[5].getGlobalBounds().left + textSL[5].getGlobalBounds().width + 5 && Mouse::getPosition(window).y < textSL[5].getGlobalBounds().top + textSL[5].getGlobalBounds().height + 5)
				windowState = 1;
	}
}

void Game::initBoard()
{
	if (!this->boardt.loadFromFile("images/board.png"))
		cout << "Can't load board texture!" << endl;
	/*this->boardt.setRepeated(true);*/
	//this->board.setTextureRect({ 0, 0, 800, 800 });
	this->board.setTexture(this->boardt);
}

void Game::updateWindow()
{
	pos = Mouse::getPosition(window);

	while (this->window.pollEvent(this->e)) {
		if (this->e.type == sf::Event::Closed)
			this->window.close();
		if (e.type == Event::MouseButtonPressed) {
			bounds = {};
			if (e.key.code == Mouse::Left) {
				if (!promotion) {
					for (int i = 0; i < 16; i++) {
						if (player && white[i].getSet()) {
							bounds = (IntRect)white[i].getSprite().getGlobalBounds();
							tmp = white[i];
						}
						else if (!player && black[i].getSet()) {
							bounds = (IntRect)black[i].getSprite().getGlobalBounds();
							tmp = black[i];
						}
						if (bounds.contains(pos.x, pos.y)) {
							dragging[i] = 1;
							break;
						}
					}
				}
				else {
					for (int i = 0; i < 16; i++) {
						if (player && white[i].getPromotion()) {
							for (int j = 0; j < 4; j++) {
								bounds = (IntRect)promotionWhite[j].getSprite().getGlobalBounds();
								if (bounds.contains(pos.x, pos.y)) {
									white[i].promoted(promotionWhite[j].getType());
									updatePromotion(i);
									break;
								}
							}
						}
						else if (!player && black[i].getPromotion()) {
							for (int j = 0; j < 4; j++) {
								bounds = (IntRect)promotionBlack[j].getSprite().getGlobalBounds();
								if (bounds.contains(pos.x, pos.y)) {
									black[i].promoted(promotionBlack[j].getType());
									updatePromotion(i);
									break;
								}
							}
						}
					}
				}
			}
		}

		if (e.type == Event::MouseButtonReleased) {
			for (int i = 0; i < 16; i++) {
				if (e.key.code == Mouse::Left && dragging[i]) {

					dragging[i] = 0;
					dx = (float)floor(pos.x / 100) * 100;
					dy = (float)floor(pos.y / 100) * 100;
					if (player)
						tmpMove = white[i].cordToString((int)dx / 100, (int)dy / 100);
					else
						tmpMove = black[i].cordToString((int)dx / 100, (int)dy / 100);

					if (isLegal(tmpMove)) {
						if (player) {
							white[i].setPos(dx, dy);
							white[i].updateCord(dx / 100, dy / 100);
							if (tmpMove == "Ke1c1") {
								white[0].setPos(300, dy);
								white[0].updateCord(3, dy / 100);
							}
							if (tmpMove == "Ke1g1") {
								white[7].setPos(500, dy);
								white[7].updateCord(5, dy / 100);
							}
						}
						else {
							black[i].setPos(dx, dy);
							black[i].updateCord(dx / 100.f, dy / 100.f);
							if (tmpMove == "Ke8c8") {
								black[0].setPos(300, dy);
								black[0].updateCord(3, dy / 100);
							}
							if (tmpMove == "Ke8g8") {
								black[7].setPos(500, dy);
								black[7].updateCord(5, dy / 100);
							}
						}

						updateMoves((int)(dx / 100), int(dy / 100), i);


					}
					else {
						tmpMove = "";
						if (player)
							white[i].setPos((float)bounds.left, (float)bounds.top);
						else
							black[i].setPos((float)bounds.left, (float)bounds.top);
					}
				}
			}
		}

		for (int i = 0; i < 16; i++) {
			if (dragging[i]) {
				if (player && white[i].getSet()) {
					white[i].setPos(pos.x - 50.f, pos.y - 50.f);
				}
				else if (!player && black[i].getSet()) {
					black[i].setPos(pos.x - 50.f, pos.y - 50.f);
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			windowState = 2;

	}
}

void Game::drawBoard()
{
	this->window.draw(board);

	for (int i = 0; i < 16; i++) {
		if (white[i].getSet() && !dragging[i])
			this->window.draw(white[i].getSprite());
		if (black[i].getSet() && !dragging[i])
			this->window.draw(black[i].getSprite());
		if (white[i].getPromotion() || black[i].getPromotion()) {
			if (player) {
				x = white[i].getX() * 100;
				y = white[i].getY() * 100;
				promotionWhite[0].changeColor(0);
				promotionWhite[1].changeColor(0);
				promotionWhite[2].changeColor(0);
				promotionWhite[3].changeColor(0);

				promotionWhite[0].setPos((float)x, (float)y);
				promotionWhite[1].setPos((float)x + 50.f, (float)y);
				promotionWhite[2].setPos((float)x, (float)y + 50.f);
				promotionWhite[3].setPos((float)x + 50.f, (float)y + 50.f);

				this->window.draw(promotionWhite[0].getSprite());
				this->window.draw(promotionWhite[1].getSprite());
				this->window.draw(promotionWhite[2].getSprite());
				this->window.draw(promotionWhite[3].getSprite());

			}
			else {
				x = black[i].getX() * 100;
				y = black[i].getY() * 100;
				promotionBlack[0].changeColor(0);
				promotionBlack[1].changeColor(0);
				promotionBlack[2].changeColor(0);
				promotionBlack[3].changeColor(0);

				promotionBlack[0].setPos((float)x, (float)y);
				promotionBlack[1].setPos((float)x + 50.f, (float)y);
				promotionBlack[2].setPos((float)x, (float)y + 50.f);
				promotionBlack[3].setPos((float)x + 50.f, (float)y + 50.f);

				this->window.draw(promotionBlack[0].getSprite());
				this->window.draw(promotionBlack[1].getSprite());
				this->window.draw(promotionBlack[2].getSprite());
				this->window.draw(promotionBlack[3].getSprite());

			}
		}
	}
	for (int i = 0; i < 16; i++) {
		if (dragging[i]) {
			if (player) {
				if (black[i].getSet())
					this->window.draw(black[i].getSprite());
				this->window.draw(white[i].getSprite());
			}
			else {
				if (white[i].getSet())
					this->window.draw(white[i].getSprite());
				this->window.draw(black[i].getSprite());
			}
		}
	}
}

void Game::renderWindow()
{
	this->window.clear();
	if (windowState == 0)
		this->drawBoard();
	else if (windowState == 1)
		this->drawMenu();
	else if (windowState == 2)
		this->drawGameMenu();
	else if (windowState == 3 || windowState == 4 || windowState == 5)
		this->drawAfterGameMenu();
	else if (windowState == 6 || windowState == 7)
		this->drawSL();
	this->window.display();
}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::startingPosition()
{
	white[0].setPiece('R', 1, 0, 7);
	white[1].setPiece('N', 1, 1, 7);
	white[2].setPiece('B', 1, 2, 7);
	white[3].setPiece('Q', 1, 3, 7);
	white[4].setPiece('K', 1, 4, 7);
	white[5].setPiece('B', 1, 5, 7);
	white[6].setPiece('N', 1, 6, 7);
	white[7].setPiece('R', 1, 7, 7);

	black[0].setPiece('R', 0, 0, 0);
	black[1].setPiece('N', 0, 1, 0);
	black[2].setPiece('B', 0, 2, 0);
	black[3].setPiece('Q', 0, 3, 0);
	black[4].setPiece('K', 0, 4, 0);
	black[5].setPiece('B', 0, 5, 0);
	black[6].setPiece('N', 0, 6, 0);
	black[7].setPiece('R', 0, 7, 0);

	for (int i = 8; i < 16; i++)
	{
		white[i].setPiece('P', 1, i - 8, 6);
		black[i].setPiece('P', 0, i - 8, 1);
	}

}

void Game::checkMoves() {
	//Funkcja zapisuje wszystkie ruchy
	check = 0;
	for (int i = 0; i < 32; i++) {
		if (i < 16) {
			type = white[i].getType();
			tmpM = white[i];
		}
		else {
			type = black[i - 16].getType();
			tmpM = black[i - 16];
		}
		if (tmpM.getSet()) {
			switch (type)
			{
			case 'K':
				checkKing(tmpM);
				break;
			case 'Q':
				checkQueen(tmpM);
				break;
			case 'R':
				checkRook(tmpM);
				break;
			case 'B':
				checkBishop(tmpM);
				break;
			case 'N':
				checkKnight(tmpM);
				break;
			case 'P':
				checkPawn(tmpM);
				break;
			default:
				break;
			}
		}
	}
	checkAttacked();
	checkCastle(white[4]);
	checkCastle(black[4]);
	checkPin(white[4]);
	checkPin(black[4]);
	checkCheck(white[4]);
	checkCheck(black[4]);
	checkGameEnd();
}

//Funkcje dla każdej figury
void Game::checkRook(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	for (int i = x + 1; i < 8; i++) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(i, y)) : possibleMovesBlack.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(i, y)) : possibleMovesBlack.push_back(tmp.cordToString(i, y));
	}

	for (int i = x - 1; i >= 0; i--) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(i, y)) : possibleMovesBlack.push_back(tmp.cordToString(i, y));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(i, y)) : possibleMovesBlack.push_back(tmp.cordToString(i, y));
	}

	for (int i = y + 1; i < 8; i++) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x, i)) : possibleMovesBlack.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x, i)) : possibleMovesBlack.push_back(tmp.cordToString(x, i));
	}

	for (int i = y - 1; i >= 0; i--) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x, i)) : possibleMovesBlack.push_back(tmp.cordToString(x, i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x, i)) : possibleMovesBlack.push_back(tmp.cordToString(x, i));
	}

}

void Game::checkPawn(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	if (!tmp.getColor()) {
		p = checkPiece(x, y + 1);
		if (!p.getSet()) {
			possibleMovesBlack.push_back(tmp.cordToString(x, y + 1));
			if (y == 1) {
				p = checkPiece(x, y + 2);
				if (!p.getSet())
					possibleMovesBlack.push_back(tmp.cordToString(x, y + 2));
			}
		}
		if (x < 7) {
			p = checkPiece(x + 1, y + 1);
			if ((p.getSet() && p.getColor()) || tmp.getColor() != player || tmp.getType() == 'K')
				possibleMovesBlack.push_back(tmp.cordToString(x + 1, y + 1));
		}
		if (x > 0) {
			p = checkPiece(x - 1, y + 1);
			if ((p.getSet() && p.getColor()) || tmp.getColor() != player || tmp.getType() == 'K')
				possibleMovesBlack.push_back(tmp.cordToString(x - 1, y + 1));
		}
		if (y == 4) {
			p = checkPiece(x - 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMovesBlack.push_back(tmp.cordToString(x - 1, y + 1));
			p = checkPiece(x + 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMovesBlack.push_back(tmp.cordToString(x + 1, y + 1));
		}

	}
	else {
		p = checkPiece(x, y - 1);
		if (!p.getSet()) {
			possibleMovesWhite.push_back(tmp.cordToString(x, y - 1));
			if (y == 6) {
				p = checkPiece(x, y - 2);
				if (!p.getSet())
					possibleMovesWhite.push_back(tmp.cordToString(x, y - 2));
			}
		}
		if (x < 7) {
			p = checkPiece(x + 1, y - 1);
			if ((p.getSet() && !p.getColor()) || tmp.getColor() != player || tmp.getType() == 'K')
				possibleMovesWhite.push_back(tmp.cordToString(x + 1, y - 1));
		}
		if (x > 0) {
			p = checkPiece(x - 1, y - 1);
			if ((p.getSet() && !p.getColor()) || tmp.getColor() != player || tmp.getType() == 'K')
				possibleMovesWhite.push_back(tmp.cordToString(x - 1, y - 1));
		}
		if (y == 3) {
			p = checkPiece(x - 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMovesWhite.push_back(tmp.cordToString(x - 1, y - 1));
			p = checkPiece(x + 1, y);
			if (p.getSet() && p.getEnPassant())
				possibleMovesWhite.push_back(tmp.cordToString(x + 1, y - 1));
		}
	}
}

void Game::checkBishop(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	for (int i = 1; i < 8 - x && i < 8 - y; i++) {
		p = checkPiece(x + i, y + i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + i, y + i)) : possibleMovesBlack.push_back(tmp.cordToString(x + i, y + i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + i, y + i)) : possibleMovesBlack.push_back(tmp.cordToString(x + i, y + i));
	}

	for (int i = 1; i < 8 - x && i <= y; i++) {
		p = checkPiece(x + i, y - i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + i, y - i)) : possibleMovesBlack.push_back(tmp.cordToString(x + i, y - i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + i, y - i)) : possibleMovesBlack.push_back(tmp.cordToString(x + i, y - i));
	}

	for (int i = 1; i <= x && i < 8 - y; i++) {
		p = checkPiece(x - i, y + i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - i, y + i)) : possibleMovesBlack.push_back(tmp.cordToString(x - i, y + i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - i, y + i)) : possibleMovesBlack.push_back(tmp.cordToString(x - i, y + i));
	}

	for (int i = 1; i <= x && i <= y; i++) {
		p = checkPiece(x - i, y - i);
		if (p.getSet()) {
			if (p.getColor() == player && p.getType() != 'K')
				break;
			else {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - i, y - i)) : possibleMovesBlack.push_back(tmp.cordToString(x - i, y - i));
				break;
			}
		}
		else
			tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - i, y - i)) : possibleMovesBlack.push_back(tmp.cordToString(x - i, y - i));
	}
}

void Game::checkKnight(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();

	p = checkPiece(x - 2, y - 1);
	if (((p.getSet() && (p.getColor() != player || p.getType() == 'K')) || !p.getSet()) && x - 2 >= 0 && y - 1 >= 0)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - 2, y - 1)) : possibleMovesBlack.push_back(tmp.cordToString(x - 2, y - 1));
	p = checkPiece(x - 2, y + 1);
	if (((p.getSet() && (p.getColor() != player || p.getType() == 'K')) || !p.getSet()) && x - 2 >= 0 && y + 1 < 8)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - 2, y + 1)) : possibleMovesBlack.push_back(tmp.cordToString(x - 2, y + 1));
	p = checkPiece(x - 1, y - 2);
	if (((p.getSet() && (p.getColor() != player || p.getType() == 'K')) || !p.getSet()) && x - 1 >= 0 && y - 2 >= 0)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - 1, y - 2)) : possibleMovesBlack.push_back(tmp.cordToString(x - 1, y - 2));
	p = checkPiece(x - 1, y + 2);
	if (((p.getSet() && (p.getColor() != player || p.getType() == 'K')) || !p.getSet()) && x - 1 >= 0 && y + 2 < 8)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x - 1, y + 2)) : possibleMovesBlack.push_back(tmp.cordToString(x - 1, y + 2));
	p = checkPiece(x + 1, y - 2);
	if (((p.getSet() && (p.getColor() != player) || p.getType() == 'K') || !p.getSet()) && x + 1 < 8 && y - 2 >= 0)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + 1, y - 2)) : possibleMovesBlack.push_back(tmp.cordToString(x + 1, y - 2));
	p = checkPiece(x + 1, y + 2);
	if (((p.getSet() && (p.getColor() != player) || p.getType() == 'K') || !p.getSet()) && x + 1 < 8 && y + 2 < 8)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + 1, y + 2)) : possibleMovesBlack.push_back(tmp.cordToString(x + 1, y + 2));
	p = checkPiece(x + 2, y - 1);
	if (((p.getSet() && (p.getColor() != player) || p.getType() == 'K') || !p.getSet()) && x + 2 < 8 && y - 1 >= 0)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + 2, y - 1)) : possibleMovesBlack.push_back(tmp.cordToString(x + 2, y - 1));
	p = checkPiece(x + 2, y + 1);
	if (((p.getSet() && (p.getColor() != player) || p.getType() == 'K') || !p.getSet()) && x + 2 < 8 && y + 1 < 8)
		tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + 2, y + 1)) : possibleMovesBlack.push_back(tmp.cordToString(x + 2, y + 1));
}

void Game::checkKing(Piece tmp) {
	x = tmp.getX();
	y = tmp.getY();
	p = {};
	for (int i = -1; i < 2 && x + i < 8; i++) {
		if (i + x < 0)
			continue;
		for (int j = -1; j < 2 && y + j < 8; j++) {
			if ((i == 0 && j == 0) || j + y < 0)
				continue;
			p = checkPiece(x + i, y + j);
			if (!p.getSet() || (p.getSet() && player != p.getColor())) {
				tmp.getColor() ? possibleMovesWhite.push_back(tmp.cordToString(x + i, y + j)) : possibleMovesBlack.push_back(tmp.cordToString(x + i, y + j));
			}
		}
	}
}

void Game::checkQueen(Piece tmp) {
	checkRook(tmp);
	checkBishop(tmp);
}

Piece Game::checkPiece(int x, int y) {
	tmpSet = 0;
	for (int i = 0; i < 16; i++) {
		if (white[i].getX() == x && white[i].getY() == y) {
			tmpM = white[i];
			if (tmpM.getSet()) {
				tmpSet = 1;
				break;
			}
		}
		if (black[i].getX() == x && black[i].getY() == y) {
			tmpM = black[i];
			if (tmpM.getSet()) {
				tmpSet = 1;
				break;
			}
		}
	}
	if (!tmpSet)
		tmpM = {};
	return tmpM;
}

bool Game::isLegal(string tmpMove) {
	if (player) {
		for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
			if (tmpMove == "Ke1c1" && possibleMovesWhite[i] == "O-O-O")
				return 1;
			if (tmpMove == "Ke1g1" && possibleMovesWhite[i] == "O-O")
				return 1;
			if (tmpMove == possibleMovesWhite[i])
				return 1;
		}
	}
	else {
		for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
			if (tmpMove == "Ke8c8" && possibleMovesBlack[i] == "O-O-O")
				return 1;
			if (tmpMove == "Ke8g8" && possibleMovesBlack[i] == "O-O")
				return 1;
			if (tmpMove == possibleMovesBlack[i])
				return 1;
		}
	}

	return 0;
}

void Game::takes(int x, int y) {
	for (int i = 0; i < 16; i++) {
		if (white[i].getX() == x && white[i].getY() == y && white[i].getSet() && player) {
			white[i].changeSet(0);
			break;
		}
		if (black[i].getX() == x && black[i].getY() == y && black[i].getSet() && !player) {
			black[i].changeSet(0);
			break;
		}
	}
}

void Game::updateMoves(int x, int y, int i) {

	gameMoves.push_back(tmpMove);

	checkPromotion(i);
	player = !player;
	takes(x, y);
	if (promotion)
		player = !player;

	possibleMovesWhite.clear();
	possibleMovesBlack.clear();
	clearEnPassant();

	if (white[i].getPromotion())
		white[i].changeSet(0);
	if (black[i].getPromotion())
		black[i].changeSet(0);

	if (player) {
		if (black[i].getType() == 'P' && tmpMove[2] == '7' && tmpMove[4] == '5')
			black[i].setEnPassant(1);
		if (black[i].getType() == 'P' && tmpMove[1] != tmpMove[3] && tmpMove[2] == '4')
			takes(x, y - 1);
	}
	else {
		if (white[i].getType() == 'P' && tmpMove[2] == '2' && tmpMove[4] == '4')
			white[i].setEnPassant(1);
		if (white[i].getType() == 'P' && tmpMove[1] != tmpMove[3] && tmpMove[2] == '5')
			takes(x, y + 1);

	}

	checkMoves();
	//system("cls");

	for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
		//	if (possibleMovesWhite[j][0] == 'K')
		//		cout << possibleMovesWhite[j] << endl;
	}


	for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
		//if (possibleMovesBlack[j][0] == 'B') 
			//cout << possibleMovesBlack[j] << endl;
	}
	//for (int i = 0; i < (int)gameMoves.size(); i++)
	//{
	//	cout << gameMoves[i] << " ";
	//}

}

void Game::updatePromotion(int i) {
	gameMoves[gameMoves.size() - 1] += '=';
	gameMoves[gameMoves.size() - 1] += player ? white[i].getType() : black[i].getType();
	checkPromotion(i);
	player = !player;
	possibleMovesWhite.clear();
	possibleMovesBlack.clear();
	checkMoves();
}

void Game::clearEnPassant() {
	for (int i = 8; i < 16; i++) {
		if (player)
			black[i].setEnPassant(0);
		else
			white[i].setEnPassant(0);
	}
}

void Game::checkPromotion(int i) {

	this->promotion = 0;

	if (white[i].getType() == 'P' && white[i].getY() == 0) {
		this->promotion = 1;
	}
	if (black[i].getType() == 'P' && black[i].getY() == 7) {
		this->promotion = 1;
	}

}

void Game::checkAttacked() {
	if (player) {
		for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
			if (possibleMovesWhite[i][0] == 'K') {
				for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
					if (possibleMovesBlack[j][0] == 'P' && possibleMovesBlack[j][1] == possibleMovesBlack[j][3])
						continue;
					if (possibleMovesBlack[j][3] == possibleMovesWhite[i][1] && possibleMovesBlack[j][4] == possibleMovesWhite[i][2]) {
						if (possibleMovesBlack[j][0] == 'R' || possibleMovesBlack[j][0] == 'Q') {
							if (possibleMovesBlack[j][1] == possibleMovesBlack[j][3] && possibleMovesWhite[i][1] == possibleMovesWhite[i][3] && possibleMovesBlack[j][1] == possibleMovesWhite[i][1] && possibleMovesWhite[i][4] != possibleMovesBlack[j][2]) {
								possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
								i--;
								break;
							}
							if (possibleMovesBlack[j][2] == possibleMovesBlack[j][4] && possibleMovesWhite[i][2] == possibleMovesWhite[i][4] && possibleMovesBlack[j][2] == possibleMovesWhite[i][2] && possibleMovesWhite[i][3] != possibleMovesBlack[j][1]) {
								possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
								i--;
								break;
							}
						}

						if (possibleMovesBlack[j][0] == 'B' || possibleMovesBlack[j][0] == 'Q') {
							if (possibleMovesBlack[j][1] - possibleMovesWhite[i][1] == possibleMovesWhite[i][2] - possibleMovesBlack[j][2]) {
								if (possibleMovesBlack[j][3] - possibleMovesWhite[i][3] == possibleMovesWhite[i][4] - possibleMovesBlack[j][4] && possibleMovesWhite[i][4] != possibleMovesBlack[j][2]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
									i--;
									break;
								}
							}
							if (possibleMovesBlack[j][1] - possibleMovesWhite[i][1] == possibleMovesBlack[j][2] - possibleMovesWhite[i][2]) {
								if (possibleMovesBlack[j][3] - possibleMovesWhite[i][3] == possibleMovesBlack[j][4] - possibleMovesWhite[i][4] && possibleMovesWhite[i][4] != possibleMovesBlack[j][2]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
									i--;
									break;
								}
							}
						}

					}
					if (possibleMovesBlack[j][3] == possibleMovesWhite[i][3] && possibleMovesBlack[j][4] == possibleMovesWhite[i][4]) {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						break;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
			if (possibleMovesBlack[i][0] == 'K') {
				for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
					if (possibleMovesWhite[j][0] == 'P' && possibleMovesWhite[j][1] == possibleMovesWhite[j][3])
						continue;
					if (possibleMovesWhite[j][3] == possibleMovesBlack[i][1] && possibleMovesWhite[j][4] == possibleMovesBlack[i][2]) {
						if (possibleMovesWhite[j][0] == 'R' || possibleMovesWhite[j][0] == 'Q') {
							if (possibleMovesWhite[j][1] == possibleMovesWhite[j][3] && possibleMovesBlack[i][1] == possibleMovesBlack[i][3] && possibleMovesWhite[j][1] == possibleMovesBlack[i][1] && possibleMovesBlack[i][4] != possibleMovesWhite[j][2]) {
								possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
								i--;
								break;
							}
							if (possibleMovesWhite[j][2] == possibleMovesWhite[j][4] && possibleMovesBlack[i][2] == possibleMovesBlack[i][4] && possibleMovesWhite[j][2] == possibleMovesBlack[i][2] && possibleMovesBlack[i][3] != possibleMovesWhite[j][1]) {
								possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
								i--;
								break;
							}
						}

						if (possibleMovesWhite[j][0] == 'B' || possibleMovesWhite[j][0] == 'Q') {
							if (possibleMovesWhite[j][1] - possibleMovesBlack[i][1] == possibleMovesBlack[i][2] - possibleMovesWhite[j][2]) {
								if (possibleMovesWhite[j][3] - possibleMovesBlack[i][3] == possibleMovesBlack[i][4] - possibleMovesWhite[j][4] && possibleMovesBlack[i][4] != possibleMovesWhite[j][2]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
									i--;
									break;
								}
							}
							if (possibleMovesWhite[j][1] - possibleMovesBlack[i][1] == possibleMovesWhite[j][2] - possibleMovesBlack[i][2]) {
								if (possibleMovesWhite[j][3] - possibleMovesBlack[i][3] == possibleMovesWhite[j][4] - possibleMovesBlack[i][4] && possibleMovesBlack[i][4] != possibleMovesWhite[j][2]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
									i--;
									break;
								}
							}
						}

					}
					if (possibleMovesWhite[j][3] == possibleMovesBlack[i][3] && possibleMovesWhite[j][4] == possibleMovesBlack[i][4]) {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						break;
					}
				}
			}
		}
	}
}

void Game::checkCastle(Piece tmp) {
	if (tmp.getColor() != player)
		return;
	x = tmp.getX();
	y = tmp.getY();

	if (tmp.getCastle()) {
		p = checkPiece(0, y);
		if (p.getCastle() && p.getSet()) {
			if (!checkPiece(1, y).getSet() && !checkPiece(2, y).getSet() && !checkPiece(3, y).getSet()) {
				if (player) {
					possibleMovesWhite.push_back("O-O-O");
					for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
						if (possibleMovesBlack[i][4] == '1') {
							if (possibleMovesBlack[i][3] == 'e' || possibleMovesBlack[i][3] == 'c' || possibleMovesBlack[i][3] == 'd') {
								possibleMovesWhite.pop_back();
								break;
							}
						}
					}
				}
				else {
					possibleMovesBlack.push_back("O-O-O");
					for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
						if (possibleMovesWhite[i][4] == '8') {
							if (possibleMovesWhite[i][3] == 'e' || possibleMovesWhite[i][3] == 'c' || possibleMovesWhite[i][3] == 'd') {
								possibleMovesBlack.pop_back();
								break;
							}
						}
					}
				}
			}
		}
		p = checkPiece(7, y);
		if (p.getCastle() && p.getSet()) {
			if (!checkPiece(6, y).getSet() && !checkPiece(5, y).getSet()) {
				if (player) {
					possibleMovesWhite.push_back("O-O");
					for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
						if (possibleMovesBlack[i][4] == '1') {
							if (possibleMovesWhite[i][3] == 'e' || possibleMovesBlack[i][3] == 'f' || possibleMovesBlack[i][3] == 'g') {
								possibleMovesWhite.pop_back();
								break;
							}
						}
					}
				}
				else {
					possibleMovesBlack.push_back("O-O");
					for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
						if (possibleMovesWhite[i][4] == '8') {
							if (possibleMovesWhite[i][3] == 'e' || possibleMovesWhite[i][3] == 'f' || possibleMovesWhite[i][3] == 'g') {
								possibleMovesBlack.pop_back();
								break;
							}
						}
					}
				}
			}
		}
	}
}

void Game::checkPin(Piece tmp) {
	if (tmp.getColor() != player)
		return;
	x = tmp.getX();
	y = tmp.getY();
	pinned = {};
	for (int i = x + 1; i < 8; i++) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'R') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][2] != possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][2] != possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = x - 1; i >= 0; i--) {
		p = checkPiece(i, y);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'R') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][2] != possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][2] != possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = y + 1; i < 8; i++) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'R') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][1] != possibleMovesWhite[j][3]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][1] != possibleMovesBlack[j][3]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = y - 1; i >= 0; i--) {
		p = checkPiece(x, i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'R') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][1] != possibleMovesWhite[j][3]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][1] != possibleMovesBlack[j][3]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};

	for (int i = 1; i < 8 - x && i < 8 - y; i++) {
		p = checkPiece(x + i, y + i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'B') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][3] - possibleMovesWhite[j][1] != possibleMovesWhite[j][2] - possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][3] - possibleMovesBlack[j][1] == possibleMovesBlack[j][2] - possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = 1; i < 8 - x && i <= y; i++) {
		p = checkPiece(x + i, y - i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'B') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][1] - possibleMovesWhite[j][3] != possibleMovesWhite[j][2] - possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][1] - possibleMovesBlack[j][3] == possibleMovesBlack[j][2] - possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = 1; i <= x && i < 8 - y; i++) {
		p = checkPiece(x - i, y + i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'B') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][1] - possibleMovesWhite[j][3] != possibleMovesWhite[j][2] - possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][1] - possibleMovesBlack[j][3] == possibleMovesBlack[j][2] - possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
	pinned = {};
	for (int i = 1; i <= x && i <= y; i++) {
		p = checkPiece(x - i, y - i);
		if (p.getSet()) {
			if (pinned.getSet()) {
				if (p.getColor() == pinned.getColor())
					break;
				if (p.getType() == 'Q' || p.getType() == 'B') {
					if (player) {
						for (int j = 0; j < (int)possibleMovesWhite.size(); j++) {
							if (possibleMovesWhite[j][0] == 'O')
								continue;
							if (possibleMovesWhite[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesWhite[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesWhite[j][3] - possibleMovesWhite[j][1] != possibleMovesWhite[j][2] - possibleMovesWhite[j][4]) {
									possibleMovesWhite.erase(possibleMovesWhite.begin() + j);
									j--;
								}
							}
						}
					}
					else {
						for (int j = 0; j < (int)possibleMovesBlack.size(); j++) {
							if (possibleMovesBlack[j][0] == 'O')
								continue;
							if (possibleMovesBlack[j][1] == static_cast<char>(pinned.getX() + 'a') && possibleMovesBlack[j][2] == to_string(8 - pinned.getY())) {
								if (possibleMovesBlack[j][3] - possibleMovesBlack[j][1] == possibleMovesBlack[j][2] - possibleMovesBlack[j][4]) {
									possibleMovesBlack.erase(possibleMovesBlack.begin() + j);
									j--;
								}
							}
						}
					}
					break;
				}
			}
			else {
				if (p.getColor() != tmp.getColor())
					break;
				else {
					pinned = p;
				}
			}
		}
	}
}

void Game::checkCheck(Piece tmp) {

	x = tmp.getX();
	y = tmp.getY();

	if (player) {
		for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
			if ((possibleMovesWhite[i][0] == 'P' && possibleMovesWhite[i][1] == possibleMovesWhite[i][3]) || possibleMovesWhite[i][0] == 'O')
				continue;
			if (possibleMovesWhite[i][3] == static_cast<char>(x + 'a') && possibleMovesWhite[i][4] == to_string(8 - y)) {
				possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
				i--;
			}
		}
	}
	else {
		for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
			if ((possibleMovesBlack[i][0] == 'P' && possibleMovesBlack[i][1] == possibleMovesBlack[i][3]) || possibleMovesBlack[i][0] == 'O')
				continue;
			if (possibleMovesBlack[i][3] == static_cast<char>(x + 'a') && possibleMovesBlack[i][4] == to_string(8 - y)) {
				possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
				i--;
			}
		}
	}

	if (player != tmp.getColor())
		return;

	if (player) {
		for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
			if ((possibleMovesBlack[i][0] == 'P' && possibleMovesBlack[i][1] == possibleMovesBlack[i][3]) || possibleMovesBlack[i][0] == 'O')
				continue;
			if (possibleMovesBlack[i][3] == static_cast<char>(x + 'a') && possibleMovesBlack[i][4] == to_string(8 - y)) {
				clearCheck(static_cast<char>(x + 'a'), static_cast<char>(8 - y + '0'), possibleMovesBlack[i][1], possibleMovesBlack[i][2]);
				check = 1;
			}
		}
	}
	else {
		for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
			if ((possibleMovesWhite[i][0] == 'P' && possibleMovesWhite[i][1] == possibleMovesWhite[i][3]) || possibleMovesWhite[i][0] == 'O')
				continue;
			if (possibleMovesWhite[i][3] == static_cast<char>(x + 'a') && possibleMovesWhite[i][4] == to_string(8 - y)) {
				clearCheck(static_cast<char>(x + 'a'), static_cast<char>(8 - y + '0'), possibleMovesWhite[i][1], possibleMovesWhite[i][2]);
				check = 1;
			}
		}
	}
}

void Game::clearCheck(char xK, char yK, char xC, char yC) {

	if (player) {
		if (xC == xK) {
			if (yK < yC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] == xK && possibleMovesWhite[i][4] > yK && possibleMovesWhite[i][4] <= yC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
			if (yK > yC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] == xK && possibleMovesWhite[i][4] < yK && possibleMovesWhite[i][4] >= yC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
		}
		else if (yC == yK) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][4] == yK && possibleMovesWhite[i][3] > xK && possibleMovesWhite[i][3] <= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K')
						continue;
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][4] == yK && possibleMovesWhite[i][3] < xK && possibleMovesWhite[i][3] >= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
		}
		else if (xC - xK == yC - yK) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] - xK == possibleMovesWhite[i][4] - yK && possibleMovesWhite[i][3] > xK && possibleMovesWhite[i][3] <= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] - xK == possibleMovesWhite[i][4] - yK && possibleMovesWhite[i][3] < xK && possibleMovesWhite[i][3] >= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
		}
		else if (xC - xK == yK - yC) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] - xK == yK - possibleMovesWhite[i][4] && possibleMovesWhite[i][3] > xK && possibleMovesWhite[i][3] <= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
					if (possibleMovesWhite[i][0] == 'K') {
						continue;
					}
					if (possibleMovesWhite[i][0] == 'O') {
						possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesWhite[i][3] - xK == yK - possibleMovesWhite[i][4] && possibleMovesWhite[i][3] < xK && possibleMovesWhite[i][3] >= xC) {
						continue;
					}
					possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
					i--;
				}
			}
		}
		else {
			for (int i = 0; i < (int)possibleMovesWhite.size(); i++) {
				if (possibleMovesWhite[i][0] == 'K') {
					continue;
				}
				possibleMovesWhite.erase(possibleMovesWhite.begin() + i);
				i--;
			}
		}
	}
	else {
		if (xC == xK) {
			if (yK < yC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] == xK && possibleMovesBlack[i][4] > yK && possibleMovesBlack[i][4] <= yC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
			if (yK > yC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] == xK && possibleMovesBlack[i][4] < yK && possibleMovesBlack[i][4] >= yC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
		}
		else if (yC == yK) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][4] == yK && possibleMovesBlack[i][3] > xK && possibleMovesBlack[i][3] <= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K')
						continue;
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][4] == yK && possibleMovesBlack[i][3] < xK && possibleMovesBlack[i][3] >= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
		}
		else if (xC - xK == yC - yK) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] - xK == possibleMovesBlack[i][4] - yK && possibleMovesBlack[i][3] > xK && possibleMovesBlack[i][3] <= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] - xK == possibleMovesBlack[i][4] - yK && possibleMovesBlack[i][3] < xK && possibleMovesBlack[i][3] >= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
		}
		else if (xC - xK == yK - yC) {
			if (xK < xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] - xK == yK - possibleMovesBlack[i][4] && possibleMovesBlack[i][3] > xK && possibleMovesBlack[i][3] <= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
			if (xK > xC) {
				for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
					if (possibleMovesBlack[i][0] == 'K') {
						continue;
					}
					if (possibleMovesBlack[i][0] == 'O') {
						possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
						i--;
						continue;
					}
					if (possibleMovesBlack[i][3] - xK == yK - possibleMovesBlack[i][4] && possibleMovesBlack[i][3] < xK && possibleMovesBlack[i][3] >= xC) {
						continue;
					}
					possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
					i--;
				}
			}
		}
		else {
			for (int i = 0; i < (int)possibleMovesBlack.size(); i++) {
				if (possibleMovesBlack[i][0] == 'K') {
					continue;
				}
				possibleMovesBlack.erase(possibleMovesBlack.begin() + i);
				i--;
			}
		}
	}

}

void Game::checkGameEnd() {
	if (player && possibleMovesWhite.size() == 0) {
		if (check)
			windowState = 4;
		else
			windowState = 5;
	}
	if (!player && possibleMovesBlack.size() == 0) {
		if (check)
			windowState = 3;
		else
			windowState = 5;
	}
}

void Game::saveFile(String s) {
	fileS.open("pgns/" + s.toAnsiString() + ".pgn");
	if (fileS.is_open()) {
		for (int i = 0; i < (int)gameMoves.size(); i++) {
			if (i % 2 == 0) {
				fileS << " " << to_string((i + 2) / 2) + ".";
			}
			fileS << " " << gameMoves[i];
		}
	}
}

void Game::loadFile(String s) {
	fileL.open("pgns/" + s.toAnsiString() + ".pgn");
	counterL = 0;
	counterFileL = 0;
	player = 1;
	if (fileL.is_open()) {
		while (!fileL.eof()) {
			fileL >> tmpMove;
			if (counterFileL % 3 != 0) {
				loadMoves();
				counterL++;
			}
			counterFileL++;
		}
		fileL.close();
	}
}

void Game::loadMoves() {
	if (player) {
		if (tmpMove == "O-O") tmpMove = "Ke1g1";
		if (tmpMove == "O-O-O") tmpMove = "Ke1c1";
	}
	else {
		if (tmpMove == "O-O") tmpMove = "Ke8g8";
		if (tmpMove == "O-O-O") tmpMove = "Ke8c8";
	}

	x = (int)tmpMove[1] - int('a');
	y = 8 - ((int)tmpMove[2] - (int)'0');

	for (int i = 0; i < 16; i++) {
		if (player && white[i].getSet() && white[i].getX() == x && white[i].getY() == y) {
			x = (int)tmpMove[3] - int('a');
			y = 8 - ((int)tmpMove[4] - (int)'0');
			white[i].setPos((float)x * 100, (float)y * 100);
			white[i].updateCord((float)x, (float)y);
			if (tmpMove == "Ke1c1") {
				white[0].setPos(300, (float)y * 100);
				white[0].updateCord(3, (float)y);
			}
			if (tmpMove == "Ke1g1") {
				white[7].setPos(500, (float)y);
				white[7].updateCord(5, (float)y * 100);
			}
			updateMoves(x, y, i);
			if (tmpMove[0] == 'P' && tmpMove[4] == '8' && tmpMove[5] == '=') {
				white[i].promoted(tmpMove[6]);
				updatePromotion(i);
			}
			break;
		}
		if (!player && black[i].getSet() && black[i].getX() == x && black[i].getY() == y) {
			x = (int)tmpMove[3] - int('a');
			y = 8 - ((int)tmpMove[4] - (int)'0');
			black[i].setPos((float)x * 100, (float)y * 100);
			black[i].updateCord((float)x, (float)y);
			if (tmpMove == "Ke8c8") {
				black[0].setPos(300, (float)y * 100);
				black[0].updateCord(3, (float)y);
			}
			if (tmpMove == "Ke8g8") {
				black[7].setPos(500, (float)y * 100);
				black[7].updateCord(5, (float)y);
			}
			updateMoves(x, y, i);
			if (tmpMove[0] == 'P' && tmpMove[4] == '8' && tmpMove[5] == '=') {
				black[i].promoted(tmpMove[6]);
				updatePromotion(i);
			}
			break;
		}
	}
}