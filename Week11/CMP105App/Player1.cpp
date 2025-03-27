#include "Player1.h"

Player1::Player1()
{
}

void Player1::handleInput(float dt)
{
	int left_right = input->isKeyDown(sf::Keyboard::D) - input->isKeyDown(sf::Keyboard::A);	// curious, may need to investigate later.
	velocity.x += ACCELERATION * left_right;

	if (on_floor && input->isKeyDown(sf::Keyboard::Space) && velocity.y >= 0)
	{
		velocity.y = JUMP_IMPULSE;
		on_floor = false;
	}
}

void Player1::update(float dt)
{
	move(velocity * dt);
	velocity.x = 0;
	if (on_floor) velocity.y = 0;
	else velocity.y += GRAVITY;
}

void Player1::collisionResponse(GameObject* collider)
{
	if (collider->getCollisionBox().top <= getCollisionBox().top + getSize().y)
		on_floor = true;
}
