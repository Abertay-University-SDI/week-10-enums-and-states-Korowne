#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;	// oh I missed that
	audio = aud;

	// initialize game objects
	font.loadFromFile("font/arial.ttf");	// For easier testing in some spots ( though I dunno, nice to have it there i guess)
	text.setFont(font);
	text.setPosition(500, 500);
	text.setCharacterSize(24);
	text.setString("MENU");
}

Menu::~Menu()
{

}

void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void Menu::update(float dt)
{

}

void Menu::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}
