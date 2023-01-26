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
	cout << "CPU PIKACHU HP: " << this->Pikachu.HP << endl;
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
	ifs2.close();
	if (this->cpuPoke == "Totodile")
	{
		cpuHP = this->Totodile.HP + (2 * this->cpuLevel);
		cpuCurrentHP = this->Totodile.HP + (2 * this->cpuLevel);
		cpuATTACK = this->Totodile.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Totodile.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Totodile.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Totodile.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Chikorita")
	{
		cpuHP = this->Chikorita.HP + (2 * this->cpuLevel);
		cpuCurrentHP = this->Chikorita.HP + (2 * this->cpuLevel);
		cpuATTACK = this->Chikorita.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Chikorita.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Chikorita.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Chikorita.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Cyndaquil")
	{
		cpuHP = this->Cyndaquil.HP + (2 * this->cpuLevel);
		cpuCurrentHP = this->Cyndaquil.HP + (2 * this->cpuLevel);
		cpuATTACK = this->Cyndaquil.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Cyndaquil.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Cyndaquil.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Cyndaquil.YLD + this->cpuLevel;
	}
	else if (this->cpuPoke == "Pikachu")
	{
		cpuHP = this->Pikachu.HP + (2 * this->cpuLevel);
		cpuCurrentHP = this->Pikachu.HP + (2 * this->cpuLevel);
		cpuATTACK = this->Pikachu.ATK + (2 * this->cpuLevel);
		cpuDEF = this->Pikachu.DEF + (2 * this->cpuLevel);
		cpuSPEED = this->Pikachu.SPE + (2 * this->cpuLevel);
		cpuYIELD = this->Pikachu.YLD + this->cpuLevel;
	}

	
}

BattleState::BattleState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume)
	: State(window, supportedKeys, states, volume)
{
	srand(time(NULL));
	this->initKeybinds();
	this->debugTextInit();
	this->initButtons();
	this->initMonsters();
	this->initBattle();
	this->initSprites();
	this->initBattleUI();
	this->openingAnimationDone = false;
	this->secondAnimationDone = false;
	this->pokemonCaught = false;
	this->cpuTurn = false;
	this->playerTurn = true;
	this->showDamageText = true;
	this->endBattle = false;
	this->playerDead = false;
	this->quit = false;
	this->transition.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->transition.setFillColor(sf::Color::Black);
	this->initMusic();
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
	this->quit = true;
	

}

void BattleState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["TACKLE_ATTACK"]->isActive())
	{
		if (this->playerTurn == true)
		{
			volatile float n = rand() % 30 + 1;
			this->damage = static_cast<int>(((n + 70.0) / 100) * (10 + (this->attack - this->cpuATTACK)));
			if (this->damage < 1) {
				this->damage = 1;
			}
			this->cpuCurrentHP -= damage;
			this->damageText.setString("You hit for " + to_string(this->damage) + "!");
			this->showDamageText = true;
			this->playerTurn = false;
			this->cpuTurn = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}


		//cout << "BUTTON" << endl;
	}
	if (this->buttons["GROWL_ATTACK"]->isActive())
	{
		this->cpuATTACK -= 10;
		this->playerTurn = false;
		this->cpuTurn = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	if (this->buttons["CATCH_POKEMON"]->isActive())
	{
		this->atmpCatch();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
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
	cout << this->pokemonName << endl;
	ifs >> this->evolveLevel;
	cout << this->evolveLevel << endl;
	ifs >> this->canEvolve;
	cout << this->canEvolve << endl;
	ifs >> this->pid;
	cout << this->pid << endl;
	ifs >> this->hp;
	cout << this->hp << endl;
	ifs >> this->currentHP;
	cout << this->currentHP << endl;
	ifs >> this->attack;
	cout << this->attack << endl;
	ifs >> this->defense;
	cout << this->defense << endl;
	ifs >> this->speed;
	cout << this->speed << endl;
	ifs >> this->yield;
	cout << this->yield << endl;
	ifs >> this->currentLevel;
	cout << this->currentLevel << endl;
	ifs >> this->currentXp;
	ifs >> this->totalMoney;
	ifs.close();
	//this->hp = this->hp + (2 * this->currentLevel);
	//this->currentHP = this->currentHP + (2 * this->currentLevel);
	//this->attack = this->attack + (2 * this->currentLevel);
	//this->defense = this->defense + (2 * this->currentLevel);
	//this->speed = this->speed + (2 * this->currentLevel);
	//this->yield = this->yield + (2 * this->currentLevel);

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
	this->updateButtons();
	if (this->battleTheme.getStatus() != this->battleTheme.Playing)
	{
		this->battleTheme.play();
		this->battleTheme.setVolume(*this->volume);
	}
	static float alpha = 255;
	if (!this->openingAnimationDone)
	{
		this->transition.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 0.95;
		if (alpha <= 1)
		{
			this->openingAnimationDone = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	if (openingAnimationDone && !secondAnimationDone)
	{
		alpha += 1;
		this->transition.setFillColor(sf::Color(0, 0, 0, alpha));
		alpha *= 1.05;
		if (alpha >= 255)
		{
			this->secondAnimationDone = true;
			alpha = 1;
		}
	}
	this->PlayerHP.setString(to_string(this->currentHP) + "/" + to_string(this->hp));
	this->EnemyHP.setString(to_string(this->cpuCurrentHP) + "/" + to_string(this->cpuHP));
	if (cpuTurn == true)
	{
		this->startCPUTurn();
	}
	if (endBattle == true)
	{
		this->transition.setFillColor(sf::Color(0, 0, 0, alpha));
		//this->battleTheme.setVolume(this->battleTheme.getVolume()-0.1);
		alpha *= 1.025;
		if (alpha >= 255)
		{
			this->endBattleState();
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
		target->draw(this->PlayerPoke);
		target->draw(this->EnemyPoke);
		target->draw(this->PlayerHP);
		target->draw(this->EnemyHP);
		if (this->playerTurn == true)
			this->renderButtons(target);
		if (this->showDamageText == true)
		{
			target->draw(this->damageText);
			target->draw(this->damageText2);
		}
		if (this->endBattle == true)
		{
			target->draw(this->background);
			if(!playerDead)
				target->draw(this->playerPokemon);
			if(!pokemonCaught)
				target->draw(this->enemyPokemon);
			target->draw(this->transition);
			target->draw(this->damageText);
		}
			
	}

	
	
	
}

void BattleState::startBattle()
{

}

void BattleState::initBattleUI()
{
	this->PlayerPoke.setFont(this->debugFont);
	this->PlayerPoke.setString(this->pokemonName + " Lvl: " + to_string(this->currentLevel));
	this->PlayerPoke.setFillColor(sf::Color::White);
	this->PlayerPoke.setCharacterSize(72);
	this->PlayerPoke.setOutlineColor(sf::Color::Black);
	this->PlayerPoke.setOutlineThickness(5.f);
	this->PlayerPoke.setPosition(200, 600);

	this->EnemyPoke.setFont(this->debugFont);
	this->EnemyPoke.setString(this->cpuPoke + " Lvl: " + to_string(this->cpuLevel));
	this->EnemyPoke.setFillColor(sf::Color::White);
	this->EnemyPoke.setCharacterSize(72);
	this->EnemyPoke.setOutlineColor(sf::Color::Black);
	this->EnemyPoke.setOutlineThickness(5.f);
	this->EnemyPoke.setPosition(1200, 100);

	this->PlayerHP.setFont(this->debugFont);
	this->PlayerHP.setString(to_string(this->currentHP) + "/" + to_string(this->hp));
	this->PlayerHP.setFillColor(sf::Color::White);
	this->PlayerHP.setCharacterSize(72);
	this->PlayerHP.setOutlineColor(sf::Color::Black);
	this->PlayerHP.setOutlineThickness(5.f);
	this->PlayerHP.setPosition(200, 700);

	this->EnemyHP.setFont(this->debugFont);
	this->EnemyHP.setString(to_string(this->cpuCurrentHP) + "/" + to_string(this->cpuHP));
	this->EnemyHP.setFillColor(sf::Color::White);
	this->EnemyHP.setCharacterSize(72);
	this->EnemyHP.setOutlineColor(sf::Color::Black);
	this->EnemyHP.setOutlineThickness(5.f);
	this->EnemyHP.setPosition(1200, 200);

	this->damageText.setFont(this->debugFont);
	this->damageText.setFillColor(sf::Color::White);
	this->damageText.setCharacterSize(72);
	this->damageText.setOutlineColor(sf::Color::Black);
	this->damageText.setOutlineThickness(5.f);
	this->damageText.setPosition(1200, 800);

	this->damageText2.setFont(this->debugFont);
	this->damageText2.setFillColor(sf::Color::White);
	this->damageText2.setCharacterSize(72);
	this->damageText2.setOutlineColor(sf::Color::Black);
	this->damageText2.setOutlineThickness(5.f);
	this->damageText2.setPosition(200, 400);

}

void BattleState::initMusic()
{
	if (!this->battleTheme.openFromFile("Assets/Music/battleTheme.wav"))
	{
		throw("Failed to load title screen music");
	}
	this->battleTheme.setLoop(true);
	this->battleTheme.setVolume(*this->volume);
}

void BattleState::atmpCatch()
{
	srand(time(NULL));
	volatile int CR = rand() % 100 + 1;
	if (CR >= this->cpuCurrentHP)
	{
		cout << this->cpuPoke << " has been caught!" << endl;
		this->damageText.setString(this->cpuPoke + " has been Caught!");
		this->damageText.setPosition(900, 500);
		this->playerTurn = false;
		this->cpuTurn = false;
		this->showDamageText = false;
		this->pokemonCaught = true;
		ofstream ofs;
		ofs.open("Data/pokemonCaught.dat", std::ios_base::app);
		if (ofs.fail())
		{
			throw("Battle State failed to write to pokemon Caught");
		}
		ofs << this->cpuPoke << endl;
		ofs.close();
		this->endBattle = true;
	}
	else
	{
		cout << this->cpuPoke << " dodged the ball!" << endl;
		this->startCPUTurn();
	}
}

void BattleState::endBattleState()
{
	this->battleTheme.stop();
	this->openingAnimationDone = false;
	this->secondAnimationDone = false;
	this->endState();
}

void BattleState::startCPUTurn()
{
	volatile int n = rand() % 2 + 1;
	volatile float m = rand() % 30 + 1;
	if (this->cpuCurrentHP > 0)
	{
		switch (n)
		{
		case 1:
			cout << "Enemy " << this->cpuPoke << " used TACKLE!" << endl;
			this->damage = static_cast<int>(((m + 70.0) / 100) * (10 + (this->cpuATTACK - this->defense)));
			if (this->damage < 1) {
				this->damage = 1;
			}
			this->currentHP -= damage;
			this->damageText2.setString("You took " + to_string(damage) + "!");
			if (this->currentHP > 0)
			{
				cout << this->pokemonName << " took " << damage << " damage!" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(300));
				this->cpuTurn = false;
				this->playerTurn = true;
				break;
			}
			else
			{
				this->damageText.setString("You lost!");
				this->damageText.setPosition(900, 500);
				this->cpuTurn = false;
				this->playerTurn = false;
				this->endBattle = true;
				this->playerDead = true;
			}
		case 2:
			this->damageText2.setString(this->cpuPoke + " used GROWL!\nBut it failed!");
			cout << "Enemy " << this->cpuPoke << " used GROWL! But it failed!" << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			this->cpuTurn = false;
			this->playerTurn = true;
			break;
		}
	}
	else
	{
		this->cpuCurrentHP = 0;
		this->endBattle = true;
		cout << "Enemy " << this->cpuPoke << " has Fainted!" << endl;
		this->pokemonCaught = true;
		int money = rand() % 34;
		this->damageText.setString(this->cpuPoke + " has been defeated!\n\n You got $"+to_string(money));
		this->damageText.setPosition(900, 500);

		volatile float xpEarned = rand() % 20 + cpuYIELD;
		int previousLevel = this->currentLevel;
		this->currentXp += (int)(xpEarned);
		if (this->currentXp > (50 + 5*(this->currentLevel)))
		{
			cout << "Level Up!" << endl;
			this->currentLevel += 1;
			this->hp = this->hp + (2 * previousLevel);
			this->currentHP = this->currentHP + (2 * previousLevel);
			this->attack = this->attack + (2 * previousLevel);
			this->defense = this->defense + (2 * previousLevel);
			this->speed = this->speed + (2 * previousLevel);
			this->yield = this->yield + (2 * previousLevel);
			this->currentXp = 0;
		}
		ofstream ofs;
		ofs.open("Data/playerSave.dat");
		if (ofs.fail())
			throw("Failed to open player save");

		ofs << this->pokemonName;
		ofs << " ";
		ofs << this->evolveLevel;
		ofs << " ";
		ofs << this->canEvolve;
		ofs << " ";
		ofs << this->pid;
		ofs << " ";
		ofs << (this->hp);
		ofs << " ";
		ofs << (this->hp);
		ofs << " ";
		ofs << (this->attack);
		ofs << " ";
		ofs << (this->defense);
		ofs << " ";
		ofs << (this->speed);
		ofs << " ";
		ofs << (this->yield);
		ofs << " ";
		ofs << this->currentLevel;
		ofs << " ";
		ofs << this->currentXp;
		ofs << " ";
		ofs << (this->totalMoney+money);
		ofs.close();
		this->cpuTurn = false;

	}
}

