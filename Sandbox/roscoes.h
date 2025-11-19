#pragma once
#include <array>
#include <iostream>
#include <vector>

#include "ClassRandom.h"
#include "input.h"


namespace Potion {

	enum Type {
		healing, 
		mana, 
		speed, 
		invisibility, 
		max_potions
	};

	constexpr std::array types{ healing, mana, speed, invisibility };

	constexpr std::array cost{ 20, 30, 12, 50 };
	constexpr std::array<std::string_view, max_potions> name{ "healing", "mana", "speed", "invisibility" };

	static_assert(std::size(name) == max_potions);
	static_assert(std::size(types) == max_potions);
	static_assert(std::size(cost) == max_potions);
}

class Player {
	
private:
	const std::string m_name{};
	std::vector<int> m_inventory{std::vector<int>(Potion::max_potions)};
	int m_wealth{Random::get(80, 120)};

public:

	Player(const std::string& name)
		: m_name{ name }
	{
	}

	int getWealth(){ return m_wealth; }

	void setWealth(int newTotal) { m_wealth = newTotal; }

	const std::string_view name() { return m_name; }

	void addToInventory(size_t index) { ++m_inventory[index]; }
	std::vector<int>& getInventory() { return m_inventory; }
};

int displayShop();

Player greetAndInitPlayer();

bool isValidInput(char input);

int updatePlayer(Player gamer, char purchase);

int printExitStats(Player gamer);

int runRoscoes();

