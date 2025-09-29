#pragma once

class Monster {

enum class Type;

private:

	Monster::Type m_type{};
	
	std::string m_roar{ "meh" };

	//use std::string here so that monster is the *owner* of its name 
	// (as opposed to std::string_view) which is a viewer
	std::string m_name { "???" };

	int m_health{ 10 };

public:
	enum class Type {
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

	constexpr std::string_view const Type();
	constexpr std::string& const Name() { return m_name; };
	constexpr std::string& const Roar() { return m_roar; };
	constexpr int Health() const { return m_health; };
};



void printMonster(Monster& m);

void instantiateMonsters();

void runInstantiateMonsters();