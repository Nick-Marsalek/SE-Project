#ifndef POKEMONSTATE_H
#define POKEMONSTATE_H
#include "State.h"
#include "Button.h"

class PokemonState : public State
{
private:
	sf::Font font;
	sf::Text prompt, debugText;
	std::map<std::string, Button*>buttons;


	void initFonts();
	void initKeybinds();
	void initButtons();
public:
	PokemonState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume);
	virtual ~PokemonState();
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
#endif // !1



