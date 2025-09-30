#pragma once
#include <string>
#include <string_view>

class Monster {

public:
	enum Type {
		ogre,
		dragon,
		orc,
		spider,
		slime,
		goblin,
		skeleton,
		troll,
		vampire,
		zombie,
		maxMonsterTypes
	};

private:

	Monster::Type m_type{};

	//use std::string here so that monster is the *owner* of its name 
// (as opposed to std::string_view) which is a viewer
	std::string m_name{ "???" };
	
	std::string m_roar{ "meh" };

	int m_health{ 10 };

public:

	Monster() = default;

	Monster(Monster::Type type, std::string name="Larry", std::string roar="meh", int hp=10)
		: m_type { type }
		, m_name { name }
		, m_roar { roar }
		, m_health{ hp }
	{
	};


	constexpr std::string_view getTypeString() const;
	const std::string& Name() const { return m_name; };
	const std::string& Roar() const { return m_roar; };
	int Health() const { return m_health; };
	void print() const;
};

void printMonster(const Monster& m);

void instantiateMonsters();

void runInstantiateMonsters();

Monster initMonster();

void runInitMonster();

int runMonsterStats();

int runMonsterGenerator();

int runGenerate100Monsters();