#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
#include "Button.h"
#include "Map.h"
#include "MainMenuState.h"
class GameState: public State
{
private:
	Maps MA;
	Entity player;
	sf::Sprite buttonSprite;
	sf::Sprite buttonSpriteBag;
	sf::Sprite buttonSpriteSave;

	sf::Texture buttonTexture;

	sf::Sprite startMenuSprite;
	sf::Texture startMenuTexture;

	bool startMenuActive;
	bool startTransition;
	bool pokemon;
	bool settings;
	bool save;
	bool main_menu;
	sf::RectangleShape startMenuBox, transitionBackground;
	sf::Font debugFont;
	sf::Text debugText;
	std::map<std::string, Button*>buttons;

	void initKeybinds();
	void initButtons();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float *volume);
	virtual ~GameState();

	//Functions
	void debugTextInit();
	void endState();
	void updateInput(const float& dt);
	void updateButtons();
	void updateStartMenu();
	void updateDebugText();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
	
};

#endif //GAMESTATE_H
