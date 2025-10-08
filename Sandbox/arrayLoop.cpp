
//#include <format>

#include "arrayLoop.h"
#include "input.h"


template <typename T>
int printArray(std::vector<T>& arr) {
	for (size_t i{ 0 }; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}

	if (arr.size() > 0) std::cout << '\n';

	return 0;
}

template <typename T>
int searchArray(std::vector<T>& array, T key) {
	for (size_t i{ 0 }; i < array.size(); i++) {
		if (array[i] == key) return static_cast<int>(i);
	}
	return -1;
}

int askForInt(int minInclusive, int maxInclusive) {

	int response{ getIntFromUser(std::format("Enter a number between {} and {}: ", minInclusive, maxInclusive)) };

	if ((response >= minInclusive) and (response <= maxInclusive)) return response;
	else return askForInt(minInclusive, maxInclusive);
}

int runArrayLoopEx() {
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	printArray(arr);

	return 0;
}

int runArraySearch() {

	std::vector array{ 4, 6, 7, 3, 8, 2, 1, 9 };
	int key = askForInt(1, 9);
	printArray(array);
	int result{ searchArray(array, key) };
	if (result == -1) std::cout << std::format("The number {} was not found", key);
	else std::cout << std::format("The number {} has index {}", key, result);
	return 0;
}