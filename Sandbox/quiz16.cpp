#include "quiz16.h"

//question 1
std::vector vec1 { 0, 2, 4, 6, 8, 10 };
const std::vector vec2{ 1.2, 3.4, 5.6, 7.8 };

const std::vector<std::string_view> vec3 {"Alex", "Brad", "Charles", "Dave"};

//CTAD^
//using namespace std::literals::string_view_literals; // for sv suffix
//const std::vector names{ "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv }; // sv suffix needed for CTAD to infer std::string_view

std::vector vec4{ 12 };

std::vector<int> vec5 (12);

//q2



int countItems(const std::vector<int>& bag) {
	int sum{ 0 };
	for (auto i : bag) {
		sum += i;
	}
	return sum;
}

std::vector<int> initBag(const std::vector<int>& numPer) {

	std::vector<int> quantities{ numPer };
	assert(quantities.size() == Items::numItems && "Oops, numItems!=quantities.size()");

	return quantities;
}

int printBag(std::vector<int> quantities) {
	for (size_t i{ 0 }; i < quantities.size(); i++) {
		int qty{ quantities[i] };
		std::cout << std::format("You have {} {}.\n", qty, itemName(static_cast<Items::Items>(i), qty));
	}
	std::cout << std::format("You have {} total items.\n", countItems(quantities));

	return 0;

}

const std::string_view itemName(Items::Items item, int qty) {
	
	assert(qty >= 0 && "Oops! Negative item qty");
	std::vector singular{ "potion", "torch", "arrow" };
	std::vector plural{ "potions", "torches", "arrows"};

	if (qty == 1) return singular[item];
	else return plural[item];

}

int runQuiz16() {
	
	printBag(initBag());
	return 0;
}

