#pragma once
#include <array>
#include <iostream>

#include "ClassRandom.h"
#include "input.h"

static std::string playerName;
static int wealth{};

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

int shop();

int greet();

int runRoscoes();

