#pragma once
#include "Framework/BaseLevel.h"
class Pause : public BaseLevel
{
public:
	Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Pause();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	sf::Text text;
	sf::Font font;
};

