#include "game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}


