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

//Q3/Q4

template<typename T>
std::pair<size_t, size_t>  minAndMaxIndices(const std::vector<T>& things) {
	size_t minIndex{};
	size_t maxIndex{};

	T min{ things[0] };
	T max{ things[0] };

	for (size_t i{ 0 }; i < things.size(); i++) {
		T t{ things[i] };
		if (t > max) {
			max = t;
			maxIndex = i;
		}
		if (t < min) {
			min = t;
			minIndex = i;
		}
	}
	return std::pair{ minIndex, maxIndex };
}

template <typename T>
std::string vectorContents(const std::vector<T>& things) {
	std::string contents = std::format("{}", things[0]); // print first element

	for (size_t i = 1; i < things.size(); ++i) {
		contents += std::format(", {}", things[i]);
	}

	return contents;
}

int runMinAndMaxIndices() {
	std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
	std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

	auto minMax{ minAndMaxIndices(v1) };
		
	size_t minIndex{ minMax.first };
	size_t maxIndex{ minMax.second };
	auto min{ v1[minIndex] };
	auto max{ v1[maxIndex] };
	
	printVectorInfo(v1, minIndex, maxIndex, min, max);
	
	auto minMax2 = minAndMaxIndices(v2);
	
	minIndex = minMax2.first;
	maxIndex = minMax2.second;
	auto min2{ v2[minIndex] };
	auto max2{ v2[maxIndex] };

	printVectorInfo(v2, minIndex, maxIndex, min2, max2);

	return 0;
}

int searchIntsFromUser() {

	std::vector<int> ints{ getPositiveIntsFromUser()};
	if (size(ints) == 0) {
		std::cout << "Vector is empty\n\n";
		return -1;
	}
	std::pair<size_t, size_t> minMax { minAndMaxIndices(ints) };
	
	size_t minIndex{ minMax.first };
	size_t maxIndex{ minMax.second };
	auto min{ ints[minIndex] };
	auto max{ ints[maxIndex] };

	printVectorInfo(ints, minIndex, maxIndex, min, max);
	return 0;
}

int runQuiz16() {
	
	printBag(initBag());
	runMinAndMaxIndices();
	searchIntsFromUser();
	playCPPMan();

	return 0;
}

