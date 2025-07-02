#include <iostream>

int accumulate(int x) {
	static int accumulator{ 0 };

	return accumulator += x;
}

int runAccumulate()
{
	std::cout << accumulate(4) << '\n'; // prints 4
	std::cout << accumulate(3) << '\n'; // prints 7
	std::cout << accumulate(2) << '\n'; // prints 9
	std::cout << accumulate(1) << '\n'; // prints 10

	return 0;
}