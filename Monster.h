#ifndef MONSTER_H
#define MONSTER_H

using namespace std;
#include <string>
#include <fstream>

typedef string Name;
typedef double Weight;
typedef double Height;
typedef int EvoLevel;
typedef int DexID;
typedef int BSE_HP;
typedef int BSE_ATK;
typedef int BSE_DEF;
typedef int BSE_SPD;
typedef int BSE_SPA;
typedef int BSE_SPD;
typedef int BSE_SPE;
typedef int EXP_YLD;

enum class BaseType {
	Bug,
	Dark,
	Dragon,
	Electric,
	Fairy,
	Fighting,
	Fire,
	Flying,
	Ghost,
	Grass,
	Ground,
	Ice,
	Normal,
	Poison,
	Psychic,
	Rock,
	Steel,
	Water,
	None
};

struct Type {
	BaseType Base;
	BaseType Sub;
};

enum Gender {
	Male,
	Female,
	Unknown
};

enum ExpGroup {
	Expidited,
	Normal,
	Paced
};

class Pokemon {


public:
	Pokemon(Name name,
		EvoLevel level,
		bool canEvolve,
		DexID Pid,
		BSE_HP hp,
		BSE_ATK atk,
		BSE_DEF def,
		BSE_SPE spe,
		EXP_YLD yld);
	Pokemon();
	string file;
	Name name;
	struct Type Type;
	EvoLevel EVO;
	bool canEvolve;
	DexID PID;
	BSE_HP HP;
	BSE_ATK ATK;
	BSE_DEF DEF;
	BSE_SPE SPE;
	EXP_YLD YLD;
	string getName();
};

//void init_pokemon();
#endif // MONSTER_H