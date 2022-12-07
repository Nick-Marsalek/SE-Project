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
	this->MapMusInit();
}

Maps::~Maps()
{

}

void Maps::render(sf::RenderTarget* target)
{
	target->draw(this->S);
}

void Maps::MapMusInit()
{
	if (!this->mapMus.openFromFile("Assets/Music/Overworld.wav"))
	{
		throw("Failed to load Map Music");
	}
	this->mapMus.setLoop(true);
	this->mapMus.setVolume(30);
	//this->mapMus.play();
}

void Maps::updateMapMusic()
{
	if (this->mapMus.getStatus() != this->mapMus.Playing)
	{
		this->mapMus.play();
		this->mapMus.setVolume(50);
	}
}

void Maps::update()
{
	this->updateMapMusic();
}

void Maps::move(const float& dt, const float dir_x, const float dir_y)
{
	this->S.move(dir_x*this->movementSpeed*dt, dir_y * this->movementSpeed * dt);
}