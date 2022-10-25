#include "GameState.h"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);

		}
	}
	ifs.close();

	
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->startMenuActive = false;
	this->startMenuBox.setSize(sf::Vector2f(150, 500));
	//1770
	this->startMenuBox.setPosition(sf::Vector2f(1770.f, 0));
	this->debugTextInit();
	
}

GameState::~GameState()
{

}


void GameState::debugTextInit()
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
}

void GameState::endState()
{
	std::cout << "Ending Game State" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player.move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player.move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}
}

void GameState::updateStartMenu()
{
	static int bufferon = 0;
	static int bufferoff = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("START_MENU"))))
	{	
		
		if (!startMenuActive)
		{
			if (bufferoff == 50)
			{
				this->startMenuActive = true;
				bufferoff = 0;
			}
		}
		else
		{
			if (bufferon == 50)
			{
				this->startMenuActive = false;
				bufferon = 0;
			}
		}
		
	}
	if (bufferoff != 50 && startMenuActive == false)
		bufferoff++;
	if (bufferon != 50 && startMenuActive == true)
		bufferon++;
}

void GameState::updateDebugText()
{
	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
	
	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100)/100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100)/100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();

	this->updateInput(dt);

	this->updateStartMenu();
	
	this->player.update(dt);

	this->updateDebugText();


}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->player.render(target);

	target->draw(this->debugText);

	if (this->startMenuActive) {
		target->draw(this->startMenuBox);
	}
}
