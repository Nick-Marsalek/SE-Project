#include "NewGameState.h"

void NewGameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
}

void NewGameState::initKeybinds()
{
	std::ifstream ifs("Config/newgamestate_keys.ini");
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

void NewGameState::initButtons()
{
	this->buttons["FIRE_STARTER"] = new Button(400, 300, 230, 75,
		&this->font, "Cyndaquil", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));

	this->buttons["WATER_STARTER"] = new Button(800, 300, 230, 75,
		&this->font, "Totodile", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));

	this->buttons["GRASS_STARTER"] = new Button(1200, 300, 230, 75,
		&this->font, "Chikorita", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 255));
}

NewGameState::NewGameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume) : State(window, supportedKeys, states, volume)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->debugTextInit();
	this->sprtieInit();
}

NewGameState::~NewGameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void NewGameState::debugTextInit()
{
	
	this->debugText.setFont(this->font);
	this->debugText.setString("TEST");
	this->debugText.setCharacterSize(15);
	this->debugText.setPosition(0, 0);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setScale(2, 2);
}

void NewGameState::sprtieInit()
{
	if (!spriteSheet.loadFromFile("Assets/Sprites/pokemonSprites3.png"))
	{
		throw("Failed to load texture pokemonsprites3");
	}
	this->water.setTexture(this->spriteSheet);
	this->water.setTextureRect(sf::IntRect(17, 177, 62 - 17, 220 - 177));
	this->water.setScale(5, 5);
	this->water.setPosition(800, 400);

	this->fire.setTexture(this->spriteSheet);
	this->fire.setTextureRect(sf::IntRect(89, 108, 134 - 89, 148 - 108));
	this->fire.setScale(5, 5);
	this->fire.setPosition(400, 400);

	this->grass.setTexture(this->spriteSheet);
	this->grass.setTextureRect(sf::IntRect(17, 37, 62 - 17, 76 - 37));
	this->grass.setScale(5, 5);
	this->grass.setPosition(1200, 400);

}

void NewGameState::endState()
{
	std::cout << "Ending MainMenu State" << std::endl;
}

void NewGameState::updateInput(const float& dt)
{
}

void NewGameState::updateButtons()
{
	ofstream ofs;
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}
	if (this->buttons["FIRE_STARTER"]->isActive())
	{
		cout << "This button works\n";
		//set player position -480, -550
		
		ofs.open("Data/playerPosition.dat");
		if (ofs.fail())
		{
			throw("Player position failed to set");
		}
		ofs << -480;
		ofs << " ";
		ofs << -550;
		ofs.close();

		ofs.open("Data/pokemonCaught.dat");
		if (ofs.fail())
		{
			throw("Pokemon caught failed to open");
		}
		ofs << " ";
		ofs.close();

		ofs.open("Data/playerSave.dat");
		if (ofs.fail())
		{
			throw("Player save failed to open");
		}
		// name evolvl bool pid hp curhp attk def speed yld currlvl
		ofs << "Cyndaquil 17 1 2 39 39 52 50 65 10 5 0";
		ofs.close();

		this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->volume));
	}

	if (this->buttons["WATER_STARTER"]->isActive())
	{
		ofs.open("Data/playerPosition.dat");
		if (ofs.fail())
		{
			throw("Player position failed to set");
		}
		ofs << -480;
		ofs << " ";
		ofs << -550;
		ofs.close();

		ofs.open("Data/pokemonCaught.dat");
		if (ofs.fail())
		{
			throw("Pokemon caught failed to open");
		}
		ofs << "";
		ofs.close();

		ofs.open("Data/playerSave.dat");
		if (ofs.fail())
		{
			throw("Player save failed to open");
		}
		// name evolvl bool pid hp curhp attk def speed yld currlvl
		ofs << "Totodile 18 1 1 50 50 65 64 43 10 5 0";
		ofs.close();

		this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->volume));
	}

	if (this->buttons["GRASS_STARTER"]->isActive())
	{
		ofs.open("Data/playerPosition.dat");
		if (ofs.fail())
		{
			throw("Player position failed to set");
		}
		ofs << -480;
		ofs << "";
		ofs << -550;
		ofs.close();

		ofs.open("Data/pokemonCaught.dat");
		if (ofs.fail())
		{
			throw("Pokemon caught failed to open");
		}
		ofs << "";
		ofs.close();

		ofs.open("Data/playerSave.dat");
		if (ofs.fail())
		{
			throw("Player save failed to open");
		}
		// name evolvl bool pid hp curhp attk def speed yld currlvl
		ofs << "Chikorita 18 1 3 45 45 49 65 45 10 5 0";
		ofs.close();

		this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->volume));
	}
	
}

void NewGameState::update(const float& dt)
{
	this->updateMousePositions();

	this->updateButtons();

	this->updateDebugText();
}

void NewGameState::updateDebugText()
{
	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100) / 100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100) / 100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
}

void NewGameState::renderSprites(sf::RenderTarget* target)
{
}

void NewGameState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void NewGameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->renderButtons(target);
	target->draw(this->debugText);
	target->draw(this->water);
	target->draw(this->fire);
	target->draw(this->grass);
}
