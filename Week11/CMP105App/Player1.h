#pragma once
#include "Framework/GameObject.h"
class Player1 : public GameObject
{
public:

	Player1();

	void handleInput(float dt) override;
	void update(float dt) override;
	void collisionResponse(GameObject* collider) override;

private:

	const float ACCELERATION = 50.0f;
	const float JUMP_IMPULSE = -200.0f;
	const float GRAVITY = 0.098f;

	bool on_floor = false;
};

