#pragma once
#include <array>
#include <iostream>
#include <cassert>


struct Item {

	std::string_view name{};
	int gold{};

};

namespace Animal {

	enum Type {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals,
	};

	struct Data {
		
		int legs{};
		std::string name{};
		std::string sound{};
		
	};

	using namespace std::string_view_literals;
	constexpr std::array animalNames{ "chicken"sv, "dog"sv,"cat"sv,
									 "elephant"sv, "duck"sv, "snake"sv };

	static_assert(animalNames.size() == max_animals);

	
}

constexpr std::string_view getAnimalName(Animal::Type name) {
	return Animal::animalNames[name];
}

std::ostream& operator<<(std::ostream out, Animal::Type animal) {
	return out << getAnimalName(animal);
}

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