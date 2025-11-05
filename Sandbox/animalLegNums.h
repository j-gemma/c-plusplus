#pragma once
#include <iostream>

enum class AnimalClass {
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

constexpr std::string_view getAnimalName(AnimalClass animal);

void printNumberOfLegs(AnimalClass animal);

void runAnimalLegNums();

