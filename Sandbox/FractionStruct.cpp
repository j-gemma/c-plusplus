#include <iostream>
#include "FractionStruct.h"
#include "input.h"

FractionStruct getFractionFromUser() {
	int num = getIntFromUser("Enter a value for the numerator: ");
	int temp{};

	while (temp == 0) temp = getIntFromUser("Enter a non-zero value for the denominator: ");

	int den = temp;

	return { num, den };
}

void runFractionStruct() {

	FractionStruct f1{ getFractionFromUser() };
	FractionStruct f2{ getFractionFromUser() };

	std::cout << "Your Fractions multiplied together: ";
	printFraction(multiplyFractions(f1, f2));


}

FractionStruct multiplyFractions(FractionStruct f1, FractionStruct f2) {

	return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };

}

void printFraction(FractionStruct frac) {
	std::cout << frac.numerator << "/" << frac.denominator;
}