#include "Pause.h"

Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;	// oh I missed that
	audio = aud;

	// initialize game objects
	font.loadFromFile("font/arial.ttf");	// For easier testing in some spots ( though I dunno, nice to have it there i guess)
	text.setFont(font);
	text.setPosition(500, 500);
	text.setCharacterSize(50);
	text.setString("PAUSE");
}

Pause::~Pause()
{
}

void Pause::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void Pause::update(float dt)
{

}

void Pause::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}
