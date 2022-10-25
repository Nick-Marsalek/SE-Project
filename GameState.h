#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
class GameState: public State
{
private:
	Entity player;
	bool startMenuActive;
	sf::RectangleShape startMenuBox;
	sf::Font debugFont;
	sf::Text debugText;

	void initKeybinds();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	//Functions
	void debugTextInit();
	void endState();
	void updateInput(const float& dt);
	void updateStartMenu();
	void updateDebugText();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	
};

#endif //GAMESTATE_H
