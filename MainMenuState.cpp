#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(850, 500, 230, 75,
		&this->font, "New Game", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70,70,70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	//sf::Color(70,70,70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["EXIT_STATE"] = new Button(880, 700, 170, 75,
		&this->font, "Quit", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->sprtieInit();
	this->debugTextInit();

	this->startPressed = false;
	this->openingAnimationDone = false;
	this->buttonTransitionRun = false;

	this->backround.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->backround.setFillColor(sf::Color::White);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}


void MainMenuState::sprtieInit()
{
	if(!this->mainMenuTexture.loadFromFile("Assets/Sprites/mainMenu.png"))
		throw("Failed to load mainMenu Sprite");
	this->mainMenuSprite.setTexture(this->mainMenuTexture);
	this->mainMenuSprite.setTextureRect(sf::IntRect(0, 1033, 239, 159));
	this->mainMenuSprite.setScale(8.5, 7.3);

	if (!this->mainMenuLogoTexture.loadFromFile("Assets/Sprites/mainMenu2.png"))
		throw("Failed to load logo");
	this->mainMenuLogoSprite.setTexture(this->mainMenuLogoTexture);
	this->mainMenuLogoSprite.setTextureRect(sf::IntRect(264, 226, 170, 61));
	this->mainMenuLogoSprite.setScale(5, 5);
	if (!this->gammaTitle.loadFromFile("Assets/Sprites/gammaLetter.png"))
		throw("Failed to load logo");
	this->gammaSprite.setTexture(this->gammaTitle);
	this->gammaSprite.setTextureRect(sf::IntRect(0, 0, 800, 800));
	this->gammaSprite.setScale(0.35, 0.35);
	//301, 353
	this->enterText.setTexture(mainMenuLogoTexture);
	this->enterText.setTextureRect(sf::IntRect(301, 353, 94, 8));
	this->enterText.setScale(7, 7);
	//7 , 7
}

void MainMenuState::debugTextInit()
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

void MainMenuState::endState()
{
	std::cout << "Ending MainMenu State" << std::endl;
}

void MainMenuState::updateSprites()
{
	this->mainMenuSprite.setPosition(sf::Vector2f(0, 0));
	this->mainMenuLogoSprite.setPosition(sf::Vector2f(520, 0));
	this->gammaSprite.setPosition(sf::Vector2f(820, 200));
	this->enterText.setPosition(sf::Vector2f(650,825));
}

void MainMenuState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("START"))))
	{
		startPressed = true;
	}
	this->checkForQuit();

}
void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["GAME_STATE"]->isActive())
	{
		buttonTransitionRun = true;
		//this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	if (this->buttons["EXIT_STATE"]->isActive())
	{
		this->quit = true;
	}
}
void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateSprites();
	if(startPressed)
		this->updateButtons();
	this->updateDebugText();
	static float alpha = 255;
	if (!openingAnimationDone)
	{
		
		backround.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 0.90;
		if (alpha <= 1)
		{
			openingAnimationDone = true;
		}
	}
	if (buttonTransitionRun)
		buttonTransition();
	

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;


}

void MainMenuState::updateDebugText()
{
	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100) / 100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100) / 100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
}

void MainMenuState::buttonTransition()
{
	static float alpha = 1;
		this->backround.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 1.1;
		if (alpha >= 255)
		{
			alpha = 1;
			buttonTransitionRun = false;
			this->backround.setFillColor(sf::Color(0, 0, 0, alpha));
			this->states->push(new GameState(this->window, this->supportedKeys, this->states));
		}
}

void MainMenuState::renderSprites(sf::RenderTarget* target)
{
	target->draw(this->mainMenuSprite);
	target->draw(this->mainMenuLogoSprite);
	target->draw(this->gammaSprite);
	if(!startPressed)
		target->draw(this->enterText);
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	//this->gamestate_button->render(target);
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{	
	if (!target)
	{
		target = this->window;
	}
	
	renderSprites(target);
	if(startPressed)
		this->renderButtons(target);
	target->draw(this->debugText);
	target->draw(this->backround);

	
	
}

