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

int runQuiz16();

