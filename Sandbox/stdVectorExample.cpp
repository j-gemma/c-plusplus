#include "stdVectorExample.h"

std::vector squares{ 1, 4, 9, 16, 25 };

std::vector<double> temps (365);

void runGet3Numbers() {
	[[maybe_unused]] int result{ get3Numbers() };
	return;
}

int get3Numbers() {
	size_t n{ 3 };
	std::cout << "Welcome. You will enter " << std::to_string(n) << " integers.\n";

	std::vector<int> v(n);
	int sum{};
	int product{ 1 };

	for (std::size_t i = 0; i < v.size(); i++) {

		v[i] = getIntFromUser("Enter integer number " + std::to_string(i + 1) + ":\n");
		sum += v[i];
		product *= v[i];
	}
	std::cout << "The sum is: " << std::to_string(sum) << ".\n";
	std::cout << "The product is: " << std::to_string(product) << ".\n";

	return 0;
}

void runLengthAndIndex() {
	[[maybe_unused]]int result{ lengthAndIndex() };
}

int lengthAndIndex() {

	std::vector hello{ 'h' ,'e' ,'l' ,'l' ,'o' };

	std::cout << "The array has " << std::size(hello) << " elements.\n";
	std::cout << hello.at(1) << hello[1];

	return 0;
}

int runPrintElement() {
	
	//std::cout << "Behold: " << static_cast<std::vector<int>::size_type>(-1) << ".\n";

	std::vector v1{ 0, 1, 2, 3, 4 };
	printElement(v1, 2);
	printElement(v1, 5);

	std::vector v2{ 1.1, 2.2, 3.3 };
	printElement(v2, 0);
	printElement(v2, -1);

	return 0;
}

template <typename T>
void printElement(const std::vector<T>& v, int index) {
	
	if (static_cast<std::vector<T>::size_type>(index) >= v.size() || index < 0) std::cout << "Invalid Index.\n";
	else std::cout << "The element has value " << v.at(static_cast<std::vector<T>::size_type>(index)) << ".\n";

	return;
}