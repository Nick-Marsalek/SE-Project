#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "GameState.h"
#include "Button.h"
class MainMenuState :
    public State
{

private:
	sf::RectangleShape backround;
	sf::Font font;

	sf::Sprite mainMenuSprite;
	sf::Texture mainMenuTexture;
	sf::Texture mainMenuLogoTexture;
	sf::Sprite mainMenuLogoSprite;
	sf::Texture gammaTitle;
	sf::Sprite gammaSprite;
	sf::Sprite enterText;

	bool startPressed;
	bool openingAnimationDone;
	bool buttonTransitionRun;
	

	sf::Font debugFont;
	sf::Text debugText;

	std::map<std::string, Button*>buttons;

	void initFonts();
	void initKeybinds();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void sprtieInit();
	void debugTextInit();
	void endState();
	void updateSprites();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void updateDebugText();
	void buttonTransition();
	void renderSprites(sf::RenderTarget* target = nullptr);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};
#endif //MAINMENUSTATE_H
