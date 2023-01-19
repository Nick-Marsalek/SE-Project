#include "Entity.h"

Entity::Entity()
{
	if (!this->T.loadFromFile("Assets/Sprites/Brendan.png"))
	{
		throw("Failed to load sprite Sheet for player.\n");
	}
	this->S.setTexture(this->T);
	this->S.setTextureRect(sf::IntRect(0,0,14,21)); //X, Y, W, H
	this->S.setScale(5.0f, 5.0f);
	this->playerCollisonBox.setSize(sf::Vector2f(70, 40));
	this->playerCollisonBox.setFillColor(sf::Color(0, 255, 0, 0));
	this->playerCollisonBox.setPosition(sf::Vector2f(940, 540));
	this->movingRight = false;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float dir_x, const float dir_y, float mapx, float mapy)
{
	int ytext = 0;
	int xtext = 0;
	if (dir_x < 0) //Moving Left
	{
		this->movingRight = false;
		//ytext = ((int)S.getPosition().x) / 15 % 3;
		ytext = (int)(mapx)*(-1) / 25 % 4;
		xtext = 30;
		ytext = ytext * 22;
		this->S.setTextureRect(sf::IntRect(xtext,ytext,14,22));
		this->S.setScale(5.0f, 5.0f);
	}
	else if (dir_y > 0) //Moving Downward
	{
		this->movingRight = false;
		//ytext = ((int)S.getPosition().y)/15 % 3;
		ytext = (int)(mapy) * (-1) / 25 % 4;
		ytext = ytext * 22;
		xtext = 0;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 22));
		this->S.setScale(5.0f, 5.0f);
	}

	else if (dir_x > 0) //Moving Right
	{
		//ytext = ((int)S.getPosition().x) / 15 % 3;
		ytext = (int)(mapx) * (-1) / 25 % 4;
		ytext = ytext * 22;
		xtext = 30;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 22));
		this->S.setScale(-5.0f, 5.0f);
		this->movingRight = true;
		
	}
	else if (dir_y < 0) //Moving Upward
	{
		this->movingRight = false;
		//ytext = ((int)S.getPosition().y) / 15 % 3;
		ytext = (int)(mapy) * (-1) / 25 % 4;
		ytext = ytext * 22;
		xtext = 14;
		this->S.setTextureRect(sf::IntRect(xtext, ytext, 14, 22));
		this->S.setScale(5.0f, 5.0f);
	}
	
	//this->S.move(dir_x * this->movementSpeed*dt, dir_y * this->movementSpeed*dt);
	//Position = this->S.getPosition();
	//this->playerCollisonBox.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
	Position = this->playerCollisonBox.getPosition();
}

void Entity::idle()
{
	this->S.setTextureRect(sf::IntRect(0, 0, 14, 21)); //X, Y, W, H
}

void Entity::update(const float& dt)
{
	//this->playerCollisonBox.setPosition(sf::Vector2f(this->S.getPosition().x, this->S.getPosition().y+60));
	if(!movingRight)
		this->S.setPosition(sf::Vector2f(this->playerCollisonBox.getPosition().x, this->playerCollisonBox.getPosition().y-60));
	else
	{
		this->S.setPosition(sf::Vector2f(this->playerCollisonBox.getPosition().x+70, this->playerCollisonBox.getPosition().y - 60));

	}
}

void Entity::render(sf::RenderTarget* target)
{
		target->draw(this->S);
		target->draw(this->playerCollisonBox);
		
}
