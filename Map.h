#ifndef MAP_H
#define MAP_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

using namespace std;
class Maps
{
protected:

public:
	sf::Sprite S;
	sf::Texture T;
	sf::RectangleShape shape, encounterBOX;
	sf::Music mapMus;
	float movementSpeed = 200.f;
	sf::Vector2f Position;
	float gridSizeF = 16;
	Maps();
	//Fcs
	virtual ~Maps();
	virtual void render(sf::RenderTarget* target);
	float getThePlayerPositionX();
	float getThePlayerPositionY();
	float getEncounterBoxX();
	float getEncounterBoxy();
	void setThePlayerPosition(float x, float y);
	void MapMusInit();
	void updateMapMusic();
	void update();
	void move(const float& dt, const float dir_x, const float dir_y);

};
#endif