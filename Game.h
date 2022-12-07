#pragma once

#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"

class Game
{
private:
	//Window variables
	sf::RenderWindow* window;
	sf::Event ev;

	//Keeps track of time to draw
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Private Functions
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	


public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Public Functions
	void updateDt();
	void pollEvents();
	void update();
	void render();


};

#endif // !GAME_H