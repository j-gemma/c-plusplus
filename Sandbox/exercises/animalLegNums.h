#pragma once
#include <iostream>

namespace AnimalClass{
enum class AnimalClass {
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

};
constexpr std::string_view getAnimalName(AnimalClass::AnimalClass animal);

void printNumberOfLegs(AnimalClass::AnimalClass animal);

void runAnimalLegNums();

