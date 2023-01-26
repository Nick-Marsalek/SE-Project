#ifndef BATTLESTATE_H
#define BATTLESTATE_h
#include "State.h"
#include "Button.h"
#include "Monster.h"
#include <chrono>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class BattleState : public State
{
private:
	void initKeybinds();
	void initButtons();
	void initMonsters();
	std::map<std::string, Button*>buttons;
	Pokemon Totodile;
	Pokemon Cyndaquil;
	Pokemon Chikorita;
	Pokemon Pikachu;
	sf::Font debugFont;
	sf::Text debugText;

	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Texture intro;
	sf::Sprite introSprite;
	sf::RectangleShape transition;

	
	sf::Texture pokemonTexture;
	sf::Texture pokemonTexture2;
	sf::Sprite playerPokemonIntro;
	sf::Sprite playerPokemon;
	sf::Sprite enemyPokemonIntro;
	sf::Sprite enemyPokemon;

	sf::Music battleTheme;

	bool openingAnimationDone;
	bool secondAnimationDone;
	bool playerTurn;
	bool cpuTurn;
	bool pokemonCaught;
	bool playerDead;
	bool showDamageText;
	bool endBattle;


	//player stuff
	string pokemonName;
	int evolveLevel;
	bool canEvolve;
	int pid;
	int hp;
	int currentHP;
	int attack;
	int defense;
	int speed;
	int yield;
	int currentLevel;
	int currentXp;
	int totalMoney;

	//cpu
	string cpuPoke;
	int cpuLevel;
	int cpuHP;
	int cpuCurrentHP;
	int cpuATTACK;
	int cpuDEF;
	int cpuSPEED;
	int cpuYIELD;

	//Battle UI
	sf::Text PlayerPoke, EnemyPoke, PlayerHP, EnemyHP;
	int damage;
	sf::Text damageText, damageText2;


public:
	BattleState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume);
	virtual ~BattleState();

	//Functions
	void debugTextInit();
	void endState();
	void updateButtons();
	void updateDebugText();
	void initMusic();
	void initBattleUI();
	void updateInput(const float& dt);
	//Battle Functions
	void initBattle();
	void initSprites();
	void introAnimation();
	void startBattle();
	void startCPUTurn();
	void atmpCatch();
	void endBattleState();

	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};
#endif
