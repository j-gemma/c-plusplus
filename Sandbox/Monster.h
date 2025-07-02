#pragma once

struct Monster {

	enum class MonsterType {
		ogre,
		dragon,
		orc,
		spider,
		slime,
	};

	MonsterType type{ MonsterType::orc };

	//use std::string here so that monster is the *owner* of its name 
	// (as opposed to std::string_view) which is a viewer
	std::string name{ "Joeschmoe" };

	int health{ 10 };

};

constexpr std::string_view getMonsterType(Monster::MonsterType mt);

void printMonster(Monster& m);

void instantiateMonsters();

void runInstantiateMonsters();