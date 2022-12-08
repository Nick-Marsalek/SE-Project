#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>


enum button_states{BUTTON_IDLE, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color textColor, unsigned int size,
		float xscale, float yscale, sf::Color outlineColor, float outlineThickness,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();
	//Accessors
	const bool isActive() const;

	//Functions
	void update(const sf::Vector2f mousePos, float x, float y);
	void render(sf::RenderTarget* target);
};
#endif
