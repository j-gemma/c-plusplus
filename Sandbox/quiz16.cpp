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

template<typename T>
std::pair<int, int>& minAndMaxIndices(const std::vector<T>& things) {
	int minIndex{};
	int maxIndex{};

	assert(size(things) > 0 && "Oops! Can't search empty vector");

	T min{ things[0] };
	T max{ things[0] };

	for (size_t i{ 0 }; i < things.size(); i++) {
		T t{ things[i] };
		if (t > max) max = t;
		maxIndex = i;
		if (t < min) min = t;
		minIndex = i;
	}
	return std::pair{ minIndex, maxIndex };
}

template <typename T>
std::string& vectorContents(const std::vector<T>& things) {

	std::string contents{};
	for (const auto& t : things) {
		contents += t + ", ";
	}
	return contents;
}

int runMinAndMaxIndices() {
	std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
	std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

	std::pair<int, int> minMax{ minAndMaxIndices(v1) };
		
	size_t minIndex{ minMax.first };
	size_t maxIndex{ minMax.second };
	auto min{ v1[minIndex] };
	auto max{ v1[maxIndex] };

	std::cout << std::format("With array: ( {} ):\n", vectorContents(v1));
	std::cout << std::format("The min element has index {} and value {}\n", minIndex, min);
	std::cout << std::format("The max element has index {} and value {}\n\n\n", maxIndex, max);
	
	minMax = minAndMaxIndices(v2);
	
	minIndex = minMax.first;
	maxIndex = minMax.second;
	auto min2{ v2[minIndex] };
	auto max2{ v2[maxIndex] };

	std::cout << std::format("With array: ( {} ):\n", vectorContents(v2));
	std::cout << std::format("The min element has index {} and value {}\n", minIndex, min2);
	std::cout << std::format("The max element has index {} and value {}\n\n\n", maxIndex, max2);

	return 0;
}

int runQuiz16() {
	
	printBag(initBag());
	runMinAndMaxIndices();
	return 0;
}

