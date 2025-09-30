#include <iostream>
#include "input.h"
#include "Monster.h"
#include "ClassRandom.h"

using enum Monster::Type;

constexpr std::string_view Monster::getTypeString() const {

	switch (this->m_type) {
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

void Monster::print() const {
	std::cout << m_name << " the " << getTypeString();

	if (m_health <= 0)
		std::cout << " is dead.\n";
	else
		std::cout << " has " << m_health << " hit points and says *" << m_roar << "*.\n";
}

//pass monster by ref here because copying compound types gets expensive fast
void printMonster(const Monster& m) {
	std::cout << "This " << m.getTypeString() << " is named " << m.Name() << " and has " << m.Health() << " health.\n";
}

void instantiateMonsters() {

	Monster torg{ ogre, "Torg", "Beep!", 145 };
	Monster blurp{ slime, "Blurp", "Boop!", 23};

	printMonster(torg);
	printMonster(blurp);

}

void runInstantiateMonsters() {
	instantiateMonsters();
}

void runInitMonster() {
Monster dude = initMonster();
	printMonster(dude);
	return;
}

Monster initMonster(){
	Monster man { Monster::skeleton, "Bones", "*rattle*", 4 };

	return man;
}

int runMonsterStats()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

	return 0;
}

namespace MonsterGenerator {

	std::string getName(int x) {
		std::string name{};
		switch (x) {
		case 0: {
			return "Grouf";
		}
		case 1: {
			return "Quouio";
		}
		case 2: {
			return "Fyeula";
		}
		case 3: {
			return "Plischk";
		}
		case 4: {
			return "Sneep";
		}
		case 5: {
			return "Ooobg";
		}
		default:
			return "MissingNo.";
		}
	}

	std::string getRoar(int x) {
		switch (x) {
		case 0: {
			return "WREEAOW";
		}
		case 1: {
			return "SKOLOOO";
		}
		case 2: {
			return "POPOPOPOPOPOPOPOPO";
		}
		case 3: {
			return "DEEDOO DEEDOO";
		}
		case 4: {
			return "PLERUMPKO";
		}
		case 5: {
			return "SKYORB'D";
		}
		default:
			return "... ? em dnif ouy did woH";
		}
	}
	Monster generate() {
		return Monster{ Monster::Type(Random::get(0, Monster::Type::maxMonsterTypes - 1)), getName(Random::get(0, 5)), 
						getRoar(Random::get(0, 5)), Random::get(0, 100) };
	}

	
}

int runMonsterGenerator() {

	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}

int runGenerate100Monsters() {

	for (int i = 0; i < 100; i++) {
		std::cout << i + 1 << ". ";
		runMonsterGenerator();
	}
	return 0;
}