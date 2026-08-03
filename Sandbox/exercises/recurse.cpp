#include "recurse.h"

int factorial(int i) {
	if (i < 0) return 0;
	if (i <= 1)
		return 1;
	else return i * factorial(i - 1);
}

int runFactorial() {
	int i{ getInt() };
	std::cout << factorial(i);
	return 0;
}

int sumDigits(int i) {
	if (i < 0) return 0;
	if (i < 10) return i;
	else return i % 10 + sumDigits(i / 10);
}

int runSumDigits() {
	int i{ getInt() };
	std::cout << sumDigits(i);
	return 0;
}

int getInt() {
	return { getTFromUser<int>("Enter an integer: ") };
}

void intToBinary(unsigned int i) {
	if (i > 1)
	{
		intToBinary(i / 2);
	}

	std::cout << i % 2;
}

int runIntToBinary() {
	while (true) {
		intToBinary( static_cast<unsigned int>(getInt()));
		std::cout << '\n';
	}
	return 0;
	}