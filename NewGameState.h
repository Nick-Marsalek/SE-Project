#ifndef NEWGAMESTATE_H
#define NEWGAMESTATE_H
#include "State.h"
#include "Button.h"
#include "MainMenuState.h"
class NewGameState : public State
{
private:
	sf::Font font;
	sf::Text prompt, debugText;
	sf::Texture spriteSheet;
	sf::Sprite fire, water, grass;

	std::map<std::string, Button*>buttons;

	void initFonts();
	void initKeybinds();
	void initButtons();
public:
	NewGameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume);
	virtual ~NewGameState();
	void debugTextInit();
	void sprtieInit();
	void endState();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void updateDebugText();
	void renderSprites(sf::RenderTarget* target = nullptr);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};
#endif

