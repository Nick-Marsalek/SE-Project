#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, sf::Color textColor, unsigned int size,
	float xscale, float yscale, sf::Color outlineColor, float outlineThickness,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BUTTON_IDLE;

	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textColor);
	this->text.setCharacterSize(size);
	this->text.setScale(sf::Vector2f(xscale, yscale));
	this->text.setOutlineColor(outlineColor);
	this->text.setOutlineThickness(outlineThickness);
	//Center text in button
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}

const bool Button::isActive() const
{
	if (this->buttonState == BUTTON_ACTIVE)
		return true;
	return false;
}

void Button::update(const sf::Vector2f mousePos, float x, float y)
{
	//Update the booleans for hover and pressed
	//Hover

	if (x != 0 && y != 0)
	{
		this->shape.setPosition(x, y);
		this->text.setPosition(
			this->shape.getPosition().x,
			this->shape.getPosition().y
		);

	}
	this->buttonState = BUTTON_IDLE;
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BUTTON_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BUTTON_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BUTTON_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BUTTON_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BUTTON_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
