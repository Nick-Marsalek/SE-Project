#include "BattleState.h"

void BattleState::initKeybinds()
{
	std::ifstream ifs("Config/battlestate_keys.ini");
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

void BattleState::initButtons()
{
	/*if (!this->debugFont.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}*/
	this->buttons["TACKLE_ATTACK"] = new Button(725, 200, 500, 75,
		&this->debugFont, "Tackle", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GROWL_ATTACK"] = new Button(725, 400, 500, 75,
		&this->debugFont, "Growl", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["CATCH_POKEMON"] = new Button(725, 600, 500, 75,
		&this->debugFont, "Throw Pokeball", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void BattleState::initMonsters()
{
	fstream ifs, ifs2;
	ifs.open("Data/pokemon.dat");
	if (ifs.fail())
	{
		throw("Failed to open pokemon data\n");
	}
	Name name;
	EvoLevel EVO;
	bool canEvolve;
	DexID PID;
	BSE_HP HP;
	BSE_ATK ATK;
	BSE_DEF DEF;
	BSE_SPE SPE;
	EXP_YLD YLD;
	ifs >> name;
	ifs >> EVO;
	ifs >> canEvolve;
	ifs >> PID;
	ifs >> HP;
	ifs >> ATK;
	ifs >> DEF;
	ifs >> SPE;
	ifs >> YLD;

	this->Totodile.name = name;
	this->Totodile.EVO = EVO;
	this->Totodile.canEvolve = canEvolve;
	this->Totodile.PID = PID;
	this->Totodile.HP = HP;
	this->Totodile.ATK = ATK;
	this->Totodile.DEF = DEF;
	this->Totodile.SPE = SPE;
	this->Totodile.YLD = YLD;

	ifs >> name;
	ifs >> EVO;
	ifs >> canEvolve;
	ifs >> PID;
	ifs >> HP;
	ifs >> ATK;
	ifs >> DEF;
	ifs >> SPE;
	ifs >> YLD;

	this->Cyndaquil.name = name;
	this->Cyndaquil.EVO = EVO;
	this->Cyndaquil.canEvolve = canEvolve;
	this->Cyndaquil.PID = PID;
	this->Cyndaquil.HP = HP;
	this->Cyndaquil.ATK = ATK;
	this->Cyndaquil.DEF = DEF;
	this->Cyndaquil.SPE = SPE;
	this->Cyndaquil.YLD = YLD;

	ifs >> name;
	ifs >> EVO;
	ifs >> canEvolve;
	ifs >> PID;
	ifs >> HP;
	ifs >> ATK;
	ifs >> DEF;
	ifs >> SPE;
	ifs >> YLD;

	this->Chikorita.name = name;
	this->Chikorita.EVO = EVO;
	this->Chikorita.canEvolve = canEvolve;
	this->Chikorita.PID = PID;
	this->Chikorita.HP = HP;
	this->Chikorita.ATK = ATK;
	this->Chikorita.DEF = DEF;
	this->Chikorita.SPE = SPE;
	this->Chikorita.YLD = YLD;

	ifs >> name;
	ifs >> EVO;
	ifs >> canEvolve;
	ifs >> PID;
	ifs >> HP;
	ifs >> ATK;
	ifs >> DEF;
	ifs >> SPE;
	ifs >> YLD;

	this->Pikachu.name = name;
	this->Pikachu.EVO = EVO;
	this->Pikachu.canEvolve = canEvolve;
	this->Pikachu.PID = PID;
	this->Pikachu.HP = HP;
	this->Pikachu.ATK = ATK;
	this->Pikachu.DEF = DEF;
	this->Pikachu.SPE = SPE;
	this->Pikachu.YLD = YLD;

	ifs.close();

	ifs2.open("Data/battleInfo.dat");
	if (ifs2.fail())
	{
		throw("Failed to load battleInfo.dat");
	}
	ifs2 >> this->cpuPoke;
	ifs2 >> this->cpuLevel;
	if (this->cpuPoke == "Totodile")
	{
		cpuATTACK = this->Totodile.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Totodile.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Totodile.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Totodile.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Chikorita")
	{
		cpuATTACK = this->Chikorita.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Chikorita.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Chikorita.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Chikorita.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Cyndaquil")
	{
		cpuATTACK = this->Cyndaquil.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Cyndaquil.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Cyndaquil.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Cyndaquil.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Pikachu")
	{
		cpuATTACK = this->Pikachu.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Pikachu.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Pikachu.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Pikachu.YLD + this->cpuLevel;
	}

	
}

BattleState::BattleState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume)
	: State(window, supportedKeys, states, volume)
{
	this->initKeybinds();
	this->debugTextInit();
	this->initButtons();
	this->initMonsters();
	this->initBattle();
	this->initSprites();
	this->openingAnimationDone = false;
	this->secondAnimationDone = false;
	this->pokemonCaught = false;
	this->transition.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->transition.setFillColor(sf::Color::Black);
	this->startBattle();
}

BattleState::~BattleState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void BattleState::debugTextInit()
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

void BattleState::endState()
{
	std::cout << "Ending Battle State" << std::endl;

}

void BattleState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["TACKLE_ATTACK"]->isActive())
	{

	}
	if (this->buttons["GROWL_ATTACK"]->isActive())
	{

	}
	if (this->buttons["CATCH_POKEMON"]->isActive())
	{

	}
}

void BattleState::updateDebugText()
{
	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;

	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100) / 100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100) / 100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	msg = this->Totodile.name;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
	//this->debugText.setPosition(player.Position.x + 120, player.Position.y - 120));
}

void BattleState::updateInput(const float& dt)
{

}

void BattleState::initBattle()
{
	fstream ifs;
	ifs.open("Data/playerSave.dat");
	if (ifs.fail())
	{
		throw("Failed to read player save");
	}
	ifs >> this->pokemonName;
	ifs >> this->evolveLevel;
	ifs >> this->canEvolve;
	ifs >> this->pid;
	ifs >> this->hp;
	ifs >> this->currentHP;
	ifs >> this->attack;
	ifs >> this->defense;
	ifs >> this->speed;
	ifs >> this->yield;
	ifs >> this->currentLevel;
	ifs.close();

	if (!pokemonTexture.loadFromFile("Assets/Sprites/pokemonSprites3.png"))
	{
		throw("Failed to load texture pokemonsprites3");
	}
	if (!pokemonTexture2.loadFromFile("Assets/Sprites/pokemonSprites4.png"))
	{
		throw("Failed to load texture pokemonsprites4");
	}
	
	if (this->pokemonName == "Totodile")
	{
		playerPokemon.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTextureRect(sf::IntRect(17, 177, 62 - 17, 220 - 177));
		playerPokemonIntro.setScale(5, 5);
		playerPokemonIntro.setPosition(200, 500);
		playerPokemon.setTextureRect(sf::IntRect(158, 188, 206 - 158, 233 - 188));
		playerPokemon.setScale(5, 5);
		playerPokemon.setPosition(400, 850);
	}
	else if (this->pokemonName == "Cyndaquil")
	{
		playerPokemon.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTextureRect(sf::IntRect(89, 108, 134 - 89, 148 - 108));
		playerPokemonIntro.setScale(5, 5);
		playerPokemonIntro.setPosition(220, 500);
		playerPokemon.setTextureRect(sf::IntRect(225, 112, 283 - 225, 162 - 112));
		playerPokemon.setScale(5, 5);
		playerPokemon.setPosition(400, 830);
	}
	else if (this->pokemonName == "Chikorita")
	{
		playerPokemon.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTexture(this->pokemonTexture);
		playerPokemonIntro.setTextureRect(sf::IntRect(17, 37, 62-17, 76-37));
		playerPokemonIntro.setScale(5, 5);
		playerPokemonIntro.setPosition(220, 500);
		playerPokemon.setTextureRect(sf::IntRect(161, 41, 203-161, 89-41));
		playerPokemon.setScale(5, 5);
		playerPokemon.setPosition(400, 820);
	}
	else if (this->pokemonName == "Pikachu")
	{
		playerPokemon.setTexture(this->pokemonTexture2);
		playerPokemonIntro.setTexture(this->pokemonTexture2);
		playerPokemonIntro.setTextureRect(sf::IntRect(14, 604, 62-14, 660-604));
		playerPokemonIntro.setScale(5, 5);
		playerPokemonIntro.setPosition(220, 500);
		playerPokemon.setTextureRect(sf::IntRect(153, 614, 212-153, 665-614));
		playerPokemon.setScale(5, 5);
		playerPokemon.setPosition(400, 820);
	}

	if (this->cpuPoke == "Totodile")
	{
		enemyPokemonIntro.setTexture(this->pokemonTexture);
		enemyPokemon.setTexture(this->pokemonTexture);
		enemyPokemonIntro.setTextureRect(sf::IntRect(17, 177, 62 - 17, 220 - 177));
		enemyPokemonIntro.setScale(5, 5);
		enemyPokemonIntro.setPosition(1450, 550);
		enemyPokemon.setTextureRect(sf::IntRect(17, 177, 62 - 17, 220 - 177));
		enemyPokemon.setScale(5, 5);
		enemyPokemon.setPosition(1230, 400);
	}
	else if (this->cpuPoke == "Chikorita")
	{
		enemyPokemonIntro.setTexture(this->pokemonTexture);
		enemyPokemon.setTexture(this->pokemonTexture);
		enemyPokemonIntro.setTextureRect(sf::IntRect(17, 37, 62 - 17, 76 - 37));
		enemyPokemonIntro.setScale(5, 5);
		enemyPokemonIntro.setPosition(1480, 550);
		enemyPokemon.setTextureRect(sf::IntRect(17, 37, 62 - 17, 76 - 37));
		enemyPokemon.setScale(5, 5);
		enemyPokemon.setPosition(1280, 400);
	}
	else if (this->cpuPoke == "Cyndaquil")
	{
		enemyPokemonIntro.setTexture(this->pokemonTexture);
		enemyPokemon.setTexture(this->pokemonTexture);
		enemyPokemonIntro.setTextureRect(sf::IntRect(89, 108, 134 - 89, 148 - 108));
		enemyPokemonIntro.setScale(5, 5);
		enemyPokemonIntro.setPosition(1480, 550);
		enemyPokemon.setTextureRect(sf::IntRect(89, 108, 134 - 89, 148 - 108));
		enemyPokemon.setScale(5, 5);
		enemyPokemon.setPosition(1280, 400);
	}
	else if (this->cpuPoke == "Pikachu")
	{
		enemyPokemonIntro.setTexture(this->pokemonTexture2);
		enemyPokemon.setTexture(this->pokemonTexture2);
		enemyPokemonIntro.setTextureRect(sf::IntRect(14, 604, 62 - 14, 660 - 604));
		enemyPokemonIntro.setScale(5, 5);
		enemyPokemonIntro.setPosition(1450, 500);
		enemyPokemon.setTextureRect(sf::IntRect(14, 604, 62 - 14, 660 - 604));
		enemyPokemon.setScale(5, 5);
		enemyPokemon.setPosition(1280, 350);
	}

}

void BattleState::initSprites()
{
	if (!this->intro.loadFromFile("Assets/Sprites/startMenuBackground.png"))
	{
		throw("Failed to load intro texture");
	}
	this->introSprite.setTexture(this->intro);
	this->introSprite.setTextureRect(sf::IntRect(406, 343, 629 - 406, 488 - 343));
	this->introSprite.setScale(sf::Vector2f(8.61, 7));
	this->introSprite.setPosition(sf::Vector2f(0, 0));

	if (!this->backgroundTexture.loadFromFile("Assets/Sprites/battleBackgroundSprite.png"))
	{
		throw("Could not load battle backround");
	}
	this->background.setTexture(this->backgroundTexture);
	this->background.setTextureRect(sf::IntRect(2, 22, 242-1, 134-20));
	this->background.setScale(8, 9.4);
}

void BattleState::introAnimation()
{
}

void BattleState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateDebugText();
	static float alpha = 255;
	if (!openingAnimationDone)
	{

		this->transition.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 0.95;
		if (alpha <= 1)
		{
			openingAnimationDone = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	if (openingAnimationDone && !secondAnimationDone)
	{
		this->transition.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 1.05;
		if (alpha >= 255)
		{
			secondAnimationDone = true;
			alpha = 0;
		}
	}
	
}

void BattleState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void BattleState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->debugText);
	if (!secondAnimationDone)
	{
		target->draw(this->introSprite);
		target->draw(this->playerPokemonIntro);
		target->draw(this->enemyPokemonIntro);
		target->draw(this->transition);
	}
	
	if (secondAnimationDone)
	{
		target->draw(this->background);
		target->draw(this->playerPokemon);
		target->draw(this->enemyPokemon);
		this->renderButtons(target);
	}
		
	
	
}

void BattleState::startBattle()
{

}

