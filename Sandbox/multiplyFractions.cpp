#include <iostream>
#include "multiplyFractions.h"
#include "input.h"

Fraction getFractionFromUser() {
	int num = getIntFromUser("Enter a value for the numerator: ");
	int temp{};

	while (temp == 0) temp = getIntFromUser("Enter a non-zero value for the denominator: ");

	int den = temp;

	return { num, den };
}

void runMultiplyFractions() {

	Fraction f1{ getFractionFromUser() };
	Fraction f2{ getFractionFromUser() };

	std::cout << "Your fractions multiplied together: ";
	printFraction(multiplyFractions(f1, f2));


}

Fraction multiplyFractions(Fraction f1, Fraction f2) {

	return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };

}

void printFraction(Fraction frac) {
	std::cout << frac.numerator << "/" << frac.denominator;
}