#include "animalLegNums.h"
#include <iostream>

void runAnimalLegNums() {

	using enum AnimalClass;

	AnimalClass kitty{ cat };
	printNumberOfLegs(kitty);
	printNumberOfLegs(chicken);
}

void printNumberOfLegs(AnimalClass animal) {
	using enum AnimalClass;

	std::cout << "A " << getAnimalName(animal) << " has ";

	switch (animal) {
	case pig:
	case goat:
	case cat:
	case dog:
		std::cout << 4;
		break;

	case chicken:
	case duck:
		std::cout << 2;
		break;

	default: std::cout << "idk man\n";
	}

	std::cout << " legs.\n";
}

constexpr std::string_view getAnimalName(AnimalClass animal) {
	using enum AnimalClass;

	switch (animal) {
	case pig: return "pig";
	case chicken: return "chicken";
	case goat: return "goat";
	case cat: return "cat";
	case dog: return "dog";
	case duck: return "duck";

	default: return "???";
	}

}