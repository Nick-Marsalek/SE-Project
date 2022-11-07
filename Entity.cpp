#include "Entity.h"
#include "GameState.h"

Entity::Entity()
{
	if (!this->T.loadFromFile("Assets/Sprites/Brendan.png"))
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
	int ytext = 0;
	int xtext = 0;
	if (dir_x < 0) //Moving Left
	{
		ytext = ((int)S.getPosition().x) / 15 % 3;
		xtext = 30;
		ytext = ytext * 21;
		this->S.setTextureRect(sf::IntRect(xtext,ytext,14,21));
		this->S.setScale(1.0f, 1.0f);
	}
	else if (dir_y > 0) //Moving Downward
	{
		ytext = ((int)S.getPosition().y)/15 % 3;
		ytext = ytext * 21;
		xtext = 0;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 21));
	}
	else if (dir_x > 0) //Moving Right
	{
		ytext = ((int)S.getPosition().x) / 15 % 3;
		ytext = ytext * 21;
		xtext = 30;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 21));
		this->S.setScale(-1.0f, 1.0f);
	}
	else if(dir_y < 0) //Moving Upward
	{
		ytext = ((int)S.getPosition().y) / 15 % 3;
		ytext = ytext * 21;
		xtext = 14;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 21));
	}
	this->S.move(dir_x * this->movementSpeed*dt, dir_y * this->movementSpeed*dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->S);
}
