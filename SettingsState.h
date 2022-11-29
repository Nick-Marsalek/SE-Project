#ifndef SETTINGSSTATE_H
#define SETTINGSTATE_H
#include "MainMenuState.h"
class SettingsState :
	public State
{
private:

	std::map<std::string, Button*>buttons;

	void initFonts();
	void initKeybinds();
	void initButtons();
	void initDebugText();
	//void sprtieInit();

	sf::Font font;
	sf::Font debugFont;
	sf::Text debugText;

public:
	SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~SettingsState();

	//Functions
	void endState();
	void updateSprites();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void updateDebugText();
	//void buttonTransition();
	//void renderSprites(sf::RenderTarget* target = nullptr);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};

#endif


