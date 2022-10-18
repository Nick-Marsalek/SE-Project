#ifndef ENTITY_H
#define ENTITY_H
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

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed = 100.f;

public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float dir_x, const float dir_y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};

#endif // ENTITY_H