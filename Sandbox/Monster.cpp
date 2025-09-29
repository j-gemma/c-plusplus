#include <iostream>
#include "input.h"
#include "Monster.h"

using enum Monster::Type;

constexpr std::string_view Monster::Type() {

	switch (mt) {
	case ogre:		return "Ogre";
	case dragon:	return "Dragon";
	case orc:		return "Orc";
	case spider:	return "Giant Spider";
	case slime:		return "Slime";
	case goblin:	return "Goblin";
	case skeleton:	return "Skeleton";
	case troll:		return "Troll";
	case vampire:	return "Vampire";
	case zombie:	return "Zombie";

	default: return "Unknown";
	}

}

//pass monster by ref here because copying compound types gets expensive fast
void printMonster(Monster& m) {
std::cout << "This " << m.Type() << " is named " << m.Name() << " and has " << m.Health() << " health.\n";
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