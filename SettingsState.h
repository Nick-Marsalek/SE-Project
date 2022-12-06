#ifndef SETTINGSSTATE_H
#define SETTINGSTATE_H
#include "State.h"
#include "Button.h"
#include <chrono>
#include <thread>
#include <fstream>
class SettingsState :
	public State
{
private:

	std::map<std::string, Button*>buttons;

	void initFonts();
	void initKeybinds();
	void initButtons();
	void initText();
	//void sprtieInit();

	sf::Font font;
	sf::Font debugFont;
	sf::Text debugText;
	sf::Text volumeDisplay;
	sf::Text volumeTitle;
	sf::Text savedText;
	sf::RectangleShape background;

	bool buttonTransistionSettingsBool;
	bool showSavedText;



public:
	SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float *volume);
	virtual ~SettingsState();

	//Functions
	void endState();
	void updateSprites();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void updateText();
	void buttonTransition();
	//void buttonTransition();
	//void renderSprites(sf::RenderTarget* target = nullptr);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};

#endif


