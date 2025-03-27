#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	font.loadFromFile("font/arial.ttf");	// For easier testing in some spots ( though I dunno, nice to have it there i guess)
	text.setFont(font);
	text.setPosition(500, 500);
	text.setCharacterSize(24);
	text.setString("LEVEL");

	// PLAYER OBJECTS
	p = new Player1;
	p->setFillColor(sf::Color::Black);
	p->setPosition(sf::Vector2f(100, 0));
	p->setSize(sf::Vector2f(50, 50));
	p->setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	p->setInput(input);
}

Level::~Level()
{
	//delete p;
}

// handle user input
void Level::handleInput(float dt)
{
	p->handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		gameState->setCurrentState(State::MENU);
		p->setPosition(sf::Vector2f(100, 0));
	}
	if (input->isKeyDown(sf::Keyboard::Tab))
	{
		gameState->setCurrentState(State::PAUSE);
	}
}

// Update game objects
void Level::update(float dt)
{
	p->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);
	window->draw(*p);

	endDraw();
}

void Level::reset()
{
	delete p;
}

