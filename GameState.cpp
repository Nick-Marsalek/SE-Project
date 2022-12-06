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
	this->buttons["START_POKEMON"] = new Button(100, 100, 50, 12,
		&this->debugFont, "Pokemon", sf::Color::Black, 20,
		0.5, 0.5, sf::Color::Black, 0.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["START_BAG"] = new Button(100, 100, 50, 12,
		&this->debugFont, "Bag", sf::Color::Black, 20,
		0.5, 0.5, sf::Color::Black, 0.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume)
	: State(window, supportedKeys, states, volume)
{
	this->initKeybinds();
	this->initButtons();
	this->startMenuActive = false;
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
	this->startMenuSprite.setScale(sf::Vector2f(1.35, 1.51));
	
	

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
	this->debugText.setScale(0.5, 0.5);
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
	
}

void GameState::updateButtons()
{
	this->buttons.at("START_POKEMON")->update(this->mousePosView, player.Position.x - 149, player.Position.y - 115);
	this->buttons.at("START_BAG")->update(this->mousePosView, player.Position.x - 149, player.Position.y - 90);
		//it.second->update(this->mousePosView, player.Position.x - 149, player.Position.y - 115);

	this->buttonSprite.setPosition(player.Position.x - 160, player.Position.y - 120);
	this->buttonSpriteBag.setPosition(player.Position.x - 160, player.Position.y - 95);
	this->buttonSpriteSave.setPosition(player.Position.x - 160, player.Position.y - 70);

}

void GameState::updateStartMenu()
{
	static int bufferon = 0;
	static int bufferoff = 0;
	this->startMenuSprite.setPosition(player.Position.x - 160, player.Position.y - 120);
	
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
	this->debugText.setPosition(sf::Vector2f(player.Position.x - 160, player.Position.y - 120));
}

void GameState::update(const float& dt)
{

	sf::View view(player.Position, sf::Vector2f(320.f, 240.f));
	this->startMenuBox.setPosition(sf::Vector2f(player.Position.x - 160, player.Position.y - 120));
	this->window->setView(view);
	this->updateMousePositions();

	this->updateInput(dt);

	this->updateStartMenu();
	
	this->player.update(dt);

	this->updateButtons();

	this->updateDebugText();


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
	this->player.render(target);

	target->draw(this->debugText);

	if (this->startMenuActive) {
		
		target->draw(this->startMenuBox);
		target->draw(this->startMenuSprite);
		target->draw(this->buttonSprite);
		target->draw(this->buttonSpriteBag);
		target->draw(this->buttonSpriteSave);
		this->renderButtons(target);
		
	}
}
