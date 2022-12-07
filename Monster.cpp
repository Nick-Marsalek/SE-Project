#include "Monster.h"
Pokemon::Pokemon(Name name,
	EvoLevel level,
	bool canEvolve,
	DexID Pid,
	BSE_HP hp,
	BSE_ATK atk,
	BSE_DEF def,
	BSE_SPE spe,
	EXP_YLD yld)
{
	this->name = name;
	this->EVO = level;
	this->canEvolve = canEvolve;
	this->PID = Pid;
	this->HP = hp;
	this->ATK = atk;
	this->DEF = def;
	this->SPE = spe;
	this->YLD = yld;
}

Pokemon::Pokemon()
{
	this->name = "Nothing";
	this->EVO = 10;
	this->canEvolve = true;
	this->PID = 999;
	this->HP = 999;
	this->ATK = 999;
	this->DEF = 999;
	this->SPE = 999;
	this->YLD = 999;
}

string Pokemon::getName()
{
	string returnName = this->name;
	return returnName;
}

//void init_pokemon()
//{
//	ifstream pkmn;
//	Pokemon P;
//	Name name;
//	BaseType type;
//	BaseType Sub;
//	Weight weight;
//	Height height;
//	Gender gender;
//	EvoLevel level;
//	bool canEvolve;
//	DexID Pid;
//	ExpGroup experience;
//	BSE_HP hp;
//	BSE_ATK atk;
//	BSE_SPA spa;
//	BSE_DEF def;
//	BSE_SPD spd;
//	BSE_SPE spe;
//	EXP_YLD yld;
//
//	pkmn.open("Data/PKMN/PKMN.txt");
//	if (pkmn.fail())
//	{
//		throw("Failed to open Pokemon Data File");
//	}
//	while (pkmn >> name >> type >> Sub >> weight >> height >> level >> canEvolve >> Pid >> experience >> hp >> atk >> spa >> def >> spd >> spe)
//	{
//
//	}
//}