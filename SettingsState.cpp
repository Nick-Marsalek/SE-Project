#include "SettingsState.h"

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
}

void SettingsState::initKeybinds()
{
}

void SettingsState::initButtons()
{
}

void SettingsState::initDebugText()
{
	if (!this->debugFont.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
	this->debugText.setFont(this->debugFont);
	this->debugText.setString("TEST");
	this->debugText.setCharacterSize(15);
	this->debugText.setPosition(0, 0);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setScale(2, 2);
}

SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initDebugText();
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void SettingsState::endState()
{
	std::cout << "Ending Settings State" << std::endl;
}

void SettingsState::updateSprites()
{
}

void SettingsState::updateInput(const float& dt)
{
}

void SettingsState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}
}

void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	this->updateSprites();
	this->updateDebugText();
}

void SettingsState::updateDebugText()
{
	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100) / 100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100) / 100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
}

void SettingsState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->debugText);
}
