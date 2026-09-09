#pragma once
#include "..\common\input.h"

#include <array>
#include <iostream>
#include <cassert>
#include <format>

struct Item {

	std::string_view name{};
	int gold{};

};

namespace Animals {

	enum Type {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals,
	};
	;
	struct Data {

		std::string_view name{};
		int legs{};
		std::string_view sound{};

	};

	constexpr std::array types{ chicken, dog, cat, elephant, duck, snake };
	constexpr std::array data{
		Data{ "chicken",    2, "cluck" },
		Data{ "dog",        4, "woof" },
		Data{ "cat",        4, "meow" },
		Data{ "elephant",   4, "pawoo" },
		Data{ "duck",       2, "quack" },
		Data{ "snake",      0, "hissss" },
	};

	static_assert(std::size(types) == max_animals);
	static_assert(std::size(data) == max_animals);

	inline std::istream& operator>>(std::istream& in, Animals::Type& animal) {
		std::string input{};
		std::getline(in >> std::ws, input);

		for (std::size_t index{ 0 }; index < Animals::max_animals; index++) {
		
			if ( input == Animals::data[index].name) {

				animal = static_cast<Animals::Type>(index);
				return in;
			}

			in.setstate(std::ios_base::failbit);
			return in;
		}

	}

}
int printAnimalsInfo(int matchIndex);

int printRestOfAnimals(int matchIndex);

int matchAnimals(std::string& animal);

int printArrayBackwardsUsingPointers(const char ptr[]);

int printArrayUsingPointers(const char ptr[]);

int runPrintArrayUsingPointers();

int runArrayOfAnimals();

int runArrayIntro();

int runPrintArray();

int runPrintItems();

template <typename T, std::size_t N>
int printArray(const std::array<T, N>& arr) {

	assert(arr.size() > 0 && "Dude! Your array can't hold anything!\n");

	std::cout << std::format("The array ({}", arr[0]);

	for (size_t i{}; i < arr.size() - 1; i++) {
		std::cout << std::format(", {}", arr[i + 1]);

	}

	std::cout << std::format(") has length {}\n", arr.size());
	return 0;
}

