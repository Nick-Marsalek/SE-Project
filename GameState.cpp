#include "GameState.h"
#include "Entity.h"
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

void GameState::initButtons()
{
	this->buttons["START_POKEMON"] = new Button(1450, 0, 500, 150,
		&this->debugFont, "Pokemon", sf::Color::White, 50,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));

	this->buttons["SETTINGS"] = new Button(1450, 300, 500, 150,
		&this->debugFont, "Settings", sf::Color::White, 50,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));

	this->buttons["SAVE_GAME"] = new Button(1450, 600, 500, 150,
		&this->debugFont, "Save", sf::Color::White, 50,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));

	this->buttons["MAIN_MENU"] = new Button(1450, 900, 500, 150,
		&this->debugFont, "Main Menu", sf::Color::White, 50,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume)
	: State(window, supportedKeys, states, volume)
{
	this->initKeybinds();
	this->initButtons();
	this->startMenuActive = false;
	this->startTransition = false;
	this->pokemon = false;
	this->settings = false;
	this->save = false;
	this->main_menu = false;
	this->transitionBackground.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->transitionBackground.setFillColor(sf::Color(0, 0, 0, 0));
	this->startMenuBox.setSize(sf::Vector2f(320, 240));
	//1770
	this->debugTextInit();

	if (!this->buttonTexture.loadFromFile("Assets/Sprites/emptyButton.png"))
	{
		throw("Failed to load sprite Sheet for button.\n");
	}
	this->buttonSprite.setTexture(this->buttonTexture);
	this->buttonSprite.setTextureRect(sf::IntRect(0, 0, 360, 140)); //X, Y, W, H
	this->buttonSprite.setScale(sf::Vector2f(0.15, 0.15));

	this->buttonSpriteBag = buttonSprite;
	this->buttonSpriteSave = buttonSprite;

	if (!this->startMenuTexture.loadFromFile("Assets/Sprites/startMenuBackground.png"))
	{
		throw("Failed to load sprite Sheet for start menu Background.\n");
	}
	this->startMenuSprite.setTexture(this->startMenuTexture);
	this->startMenuSprite.setTextureRect(sf::IntRect(15, 606, 248, 159)); //X, Y, W, H
	this->startMenuSprite.setScale(sf::Vector2f(7, 7));
	this->startMenuSprite.setPosition(sf::Vector2f(1600, 0));



}

GameState::~GameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
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
	this->debugText.setScale(2, 2);
}

void GameState::endState()
{
	std::cout << "Ending Game State" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
	if (!startMenuActive)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		{
			this->MA.move(dt, -1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		{
			this->MA.move(dt, 1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		{
			this->MA.move(dt, 0.f, -1.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		{
			this->MA.move(dt, 0.f, 1.f);
		}
		else
		{
			this->player.idle();
		}

	}

}

void GameState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["START_POKEMON"]->isActive())
	{
		this->pokemon = true;
		this->startTransition = true;
	}
	if (this->buttons["SETTINGS"]->isActive())
	{
		this->settings = true;
		this->startTransition = true;
	}
	if (this->buttons["SAVE_GAME"]->isActive())
	{

	}
	if (this->buttons["MAIN_MENU"]->isActive())
	{
		this->main_menu = true;
		this->startTransition = true;
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
	//this->debugText.setPosition(player.Position.x + 120, player.Position.y - 120));
}


void GameState::update(const float& dt)
{

	this->startMenuBox.setPosition(sf::Vector2f(0, 0));
	this->updateMousePositions();

	this->updateInput(dt);

	this->updateStartMenu();

	this->MA.update();
	
	this->player.update(dt);

	this->updateButtons();

	this->updateDebugText();

	if (startTransition == true)
	{
		static float alpha = 1;
		this->transitionBackground.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 1.1;
		if (alpha >= 255)
		{
			alpha = 0;
			if (pokemon)
			{
				this->startTransition = false;
				this->pokemon = false;
				this->transitionBackground.setFillColor(sf::Color(0, 0, 0, 0));
				alpha = 1;
			}
			else if (settings)
			{
				this->settings = false;
				this->startTransition = false;
				this->transitionBackground.setFillColor(sf::Color(0, 0, 0, 0));
				alpha = 1;

				this->states->push(new SettingsState(this->window, this->supportedKeys, this->states, this->volume));
			}
			else if (main_menu)
			{
				this->main_menu = false;
				this->startTransition = false;
				this->transitionBackground.setFillColor(sf::Color(0, 0, 0, 0));
				alpha = 1;
				this->quit = true;
			}
		}
	}

}

void GameState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->MA.render(target);
	this->player.render(target);

	target->draw(this->debugText);

	if (this->startMenuActive) {
		
		//target->draw(this->startMenuBox);
		target->draw(this->startMenuSprite);
		this->renderButtons(target);
		
	}
	target->draw(this->transitionBackground);
}
