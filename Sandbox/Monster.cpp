#include <iostream>
#include "input.h"
#include "Monster.h"

using enum Monster::MonsterType;

constexpr std::string_view getMonsterType(Monster::MonsterType mt) {

	switch (mt) {
	case ogre:		return "Ogre";
	case dragon:	return "Dragon";
	case orc:		return "Orc";
	case spider:	return "Giant Spider";
	case slime:		return "Slime";

	default: return "Unknown";
	}

}

//pass monster by ref here because copying compound types gets expensive fast
void printMonster(Monster& m) {
	std::cout << "This " << getMonsterType(m.type) << " is named " << m.name << " and has " << m.health << " health.\n";
}

void instantiateMonsters() {

	Monster torg{ ogre, "Torg", 145 };
	Monster blurp{ slime, "Blurp", 23 };

	printMonster(torg);
	printMonster(blurp);

}

void runInstantiateMonsters() {
	instantiateMonsters();
}