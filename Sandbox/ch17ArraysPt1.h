#pragma once
#include <array>
#include <iostream>
#include <cassert>


struct Item {

	std::string_view name{};
	int gold{};

};

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