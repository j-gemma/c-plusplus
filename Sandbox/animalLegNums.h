#pragma once
#include <iostream>

enum class Animal {
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

constexpr std::string_view getAnimalName(Animal animal);

void printNumberOfLegs(Animal animal);

void runAnimalLegNums();

