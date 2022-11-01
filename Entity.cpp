#include "Entity.h"
#include "GameState.h"

Entity::Entity()
{
	if (!this->T.loadFromFile("Assets/Brendan.png"))
	{
		throw("Failed to load sprite Sheet for player.\n");
	}
	this->S.setTexture(this->T);
	this->S.setTextureRect(sf::IntRect(0,0,14,21)); //X, Y, W, H
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	this->S.move(dir_x * this->movementSpeed*dt, dir_y * this->movementSpeed*dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->S);
}
