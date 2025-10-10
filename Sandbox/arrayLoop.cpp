
//#include <format>

#include "arrayLoop.h"

template <typename T>
int printArray(std::vector<T>& arr) {
	for (size_t i{ 0 }; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}

	if (arr.size() > 0) std::cout << '\n';

	return 0;
}

template <typename T>
int findKey(std::vector<T>& array, T key) {
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

template <typename T>
T findMax(std::vector<T> array) {
	
	if (array.size() == 0) return T{};
	else {
		T max{ array[0] };
		for (size_t i{ 1 }; i < array.size(); i++) {
			if (array[i] > max) max = array[i];
		}
		return max;
	}

}

template <typename T>
T askForT(T minInclusive, T maxInclusive) {

	T response{ getTFromUser<T>(std::format("Enter a number between {} and {}: ", minInclusive, maxInclusive)) };

	if ((response >= minInclusive) and (response <= maxInclusive)) return response;
	else return askForT(minInclusive, maxInclusive);
}

template <typename T>
T arraySearch(std::vector<T>& array, T min, T max) {
	T key = askForT(min, max);
	printArray(array);
	int result{ findKey(array, key) };
	if (result == -1) std::cout << std::format("The number {} was not found.\n", key);
	else std::cout << std::format("The number {} has index {}\n", key, result);
	return 0;
}

int fizzBuzz(int max) {
	static const std::vector divisors{ 3, 5, 7, 11, 13, 17, 19 };
	static const std::vector<std::string_view> words{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

	assert(std::size(divisors) == std::size(words)&& "fizzbuzz: array sizes don't match");


	for (size_t i{1}; i <= max; i++) {
		std::string printme{};
		for (size_t j{}; j < divisors.size(); j++) {
			int divisor{ divisors[j] };
			if (i < divisor) break;
			if ((i % divisor) == 0) printme += words[j];
		}
		printme.size() == 0 ? std::cout << i : std::cout << printme;
		std::cout << '\n';
	}
	
	return 0;
}

int runArrayLoopEx() {
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	printArray(arr);

	return 0;
}

int runArraySearch() {

	std::vector array1{ 4, 6, 7, 3, 8, 2, 1, 9 };
	std::vector array2{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

	arraySearch(array1, 1, 9);
	arraySearch(array2, 1.1, 9.9);
	
	return 0;
}

int runFindMax() {
	std::vector data1{ 84, 92, 76, 81, 56 };
	std::cout << findMax(data1) << '\n';

	std::vector data2{ -13.0, -26.7, -105.5, -14.8 };
	std::cout << findMax(data2) << '\n';

	std::vector<int> data3{ };
	std::cout << findMax(data3) << '\n';

	return 0;
}

int runFizzBuzz() {
	fizzBuzz(150);
	return 0;
}