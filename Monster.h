#ifndef MONSTER_H
#define MONSTER_H

using namespace std;
#include <string>
#include <fstream>

typedef string Name;
typedef double Weight;
typedef double Height;
typedef uint8_t EvoLevel;
typedef uint8_t DexID;
typedef uint8_t BSE_HP;
typedef uint8_t BSE_ATK;
typedef uint8_t BSE_DEF;
typedef uint8_t BSE_SPD;
typedef uint8_t BSE_SPA;
typedef uint8_t BSE_SPD;
typedef uint8_t BSE_SPE;
typedef uint8_t EXP_YLD;

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
		EXP_YLD yld);
	string file;
	Name name;
	struct Type Type;
	Weight weight;
	Height height;
	EvoLevel EVO;
	bool canEvolve;
	DexID PID;
	ExpGroup EXP;
	BSE_HP HP;
	BSE_ATK ATK;
	BSE_SPA SPA;
	BSE_DEF DEF;
	BSE_SPD SPD;
	BSE_SPE SPE;
	EXP_YLD YLD;
};

void init_pokemon();
#endif // MONSTER_H