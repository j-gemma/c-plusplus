#pragma once
#include <vector>
#include <iostream>
#include <cassert>
#include "input.h"
#include "cppMan.h"

namespace Items {

	enum Items {
		potion,
		torch,
		arrow,
		numItems
	};
}

int countItems(const std::vector<int>& bag);

std::vector<int> initBag(const std::vector<int>& numPer = { 1, 5, 10 });

int printBag(std::vector<int> quantities);

const std::string_view itemName(Items::Items item, int qty);

template<typename T>
std::pair<size_t, size_t> minAndMaxIndices(const std::vector<T>& things);

template <typename T>
std::string vectorContents(const std::vector<T>& things);

template <typename T>
int runMinAndMaxIndices();

template <typename T>
int printVectorInfo(const std::vector<T>& ts, size_t minIndex, size_t maxIndex, T& min, T& max) {

	std::cout << std::format("With array: ( {} ):\n", vectorContents(ts));
	std::cout << std::format("The min element has index {} and value {}\n", minIndex, min);
	std::cout << std::format("The max element has index {} and value {}\n\n", maxIndex, max);
	
	return 0;
}

std::vector<int> getPositiveIntsFromUser();

int searchIntsFromUser();

int runQuiz16();


