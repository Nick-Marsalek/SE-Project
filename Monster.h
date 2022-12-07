#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

typedef std::string Name;
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
	Water
};

class Type {
	Type(BasicType main);
	Type(BasicType main, BasicType sub);
	void addSubType(BasicType);
	bool hasType(BasicType) const;
};

enum class Gender {
	Male,
	Female,
	Unknown
};

enum class ExpGroup {
	Expidited,
	Normal,
	Paced
};

class Pokemon {
	Pokemon() = delete;
	Pokemon(Name name,
		Type type,
		Weight, weight,
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

};

#endif