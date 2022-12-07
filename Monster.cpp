#include "Monster.h"
Pokemon::Pokemon(Name name,
	BaseType type,
	BaseType Sub,
	Weight weight,
	Height height,
	Gender gender,
	EvoLevel level,
	bool canEvolve,
	DexID Pid,
	ExpGroup experience,
	BSE_HP hp,
	BSE_ATK atk,
	BSE_SPA spa,
	BSE_DEF def,
	BSE_SPD spd,
	BSE_SPE spe,
	EXP_YLD yld)
{
	this->name = name;
	this->Type.Base = type;
	this->Type.Sub = Sub;
	this->weight = weight;
	this->height = height;
	this->EVO = level;
	this->canEvolve = canEvolve;
	this->PID = Pid;
	this->EXP = experience;
	this->HP = hp;
	this->ATK = atk;
	this->DEF = def;
	this->SPA = spa;
	this->SPD = spd;
	this->SPE = spe;
	this->YLD = yld;
}

void init_pokemon()
{
	ifstream pkmn;
	Pokemon P;
	Name name;
	BaseType type;
	BaseType Sub;
	Weight weight;
	Height height;
	Gender gender;
	EvoLevel level;
	bool canEvolve;
	DexID Pid;
	ExpGroup experience;
	BSE_HP hp;
	BSE_ATK atk;
	BSE_SPA spa;
	BSE_DEF def;
	BSE_SPD spd;
	BSE_SPE spe;
	EXP_YLD yld;

	pkmn.open("Data/PKMN/PKMN.txt");
	if (pkmn.fail())
	{
		throw("Failed to open Pokemon Data File");
	}
	while (pkmn >> name >> type >> Sub >> weight >> height >> level >> canEvolve >> Pid >> experience >> hp >> atk >> spa >> def >> spd >> spe)
	{

	}
}