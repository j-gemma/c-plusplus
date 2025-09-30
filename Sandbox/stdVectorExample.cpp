#include "stdVectorExample.h"


std::vector squares{ 1, 4, 9, 16, 25 };

std::vector<double> temps (365);

int runGet3Numbers() {

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