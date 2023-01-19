#include "Map.h"
Maps::Maps()
{
	if (!this->T.loadFromFile("Assets/Maps/Map_01.png"))
	{
		throw("Failed to load the map image.\n");
	}
	this->S.setTexture(this->T);
	this->S.setTextureRect(sf::IntRect(0, 0, 800, 800)); //X, Y, W, H
	this->S.setScale(5.0f, 5.0f);
	this->S.setPosition(sf::Vector2f(0, 0));
	this->MapMusInit();

	this->encounterBOX.setSize(sf::Vector2f(800, 800));
	this->encounterBOX.setFillColor(sf::Color(255, 0, 0, 0));
	this->encounterBOX.setPosition(sf::Vector2f(1920, 245));
	//250->630
	this->houseCollision.setSize(sf::Vector2f(630-250, 325));
	this->houseCollision.setFillColor(sf::Color(255, 0, 0, 0));
	this->houseCollision.setPosition(sf::Vector2f(250, -75));
}

Maps::~Maps()
{

}


void Maps::setThePlayerPosition(float x, float y)
{
	this->S.setPosition(sf::Vector2f(x, y));
}

void Maps::render(sf::RenderTarget* target)
{
	target->draw(this->S);
	target->draw(this->encounterBOX);
	target->draw(this->houseCollision);
}

float Maps::getThePlayerPositionX()
{
	return this->S.getPosition().x;
}

float Maps::getThePlayerPositionY()
{
	return this->S.getPosition().y;
}

float Maps::getEncounterBoxX()
{
	return this->encounterBOX.getPosition().x;
}

float Maps::getEncounterBoxy()
{
	return this->encounterBOX.getPosition().y;
}

float Maps::getHousex()
{
	return this->houseCollision.getPosition().x;
}

float Maps::getHousey()
{
	return this->houseCollision.getPosition().y;
}

void Maps::MapMusInit()
{
	/*if (!this->mapMus.openFromFile("Assets/Music/Overworld.wav"))
	{
		throw("Failed to load Map Music");
	}
	this->mapMus.setLoop(true);
	this->mapMus.setVolume(25);*/
	//this->mapMus.play();
}

void Maps::updateMapMusic()
{
	/*if (this->mapMus.getStatus() != this->mapMus.Playing)
	{
		this->mapMus.play();
		this->mapMus.setVolume(50);
	}*/
}

void Maps::update()
{
	//this->updateMapMusic();
}

void Maps::move(const float& dt, const float dir_x, const float dir_y)
{
	this->S.move((-1)*dir_x*this->movementSpeed*dt, (-1)*dir_y * this->movementSpeed * dt);
	this->encounterBOX.move((-1) * dir_x * this->movementSpeed * dt, (-1) * dir_y * this->movementSpeed * dt);
	this->houseCollision.move((-1) * dir_x * this->movementSpeed * dt, (-1) * dir_y * this->movementSpeed * dt);
}