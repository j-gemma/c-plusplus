#pragma once
#include <vector>
#include <iostream>
#include <cassert>

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
std::pair<int, int>& minAndMaxIndices(const std::vector<T>& things);

template <typename T>
std::string_view& vectorContents(const std::vector<T>& things);

template <typename T>
int runMinAndMaxIndices();

int runQuiz16();


