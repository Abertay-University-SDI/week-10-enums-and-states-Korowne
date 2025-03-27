#pragma once
#include "Framework/BaseLevel.h"
class Menu : public BaseLevel
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	sf::Text text;
	sf::Font font;
};

