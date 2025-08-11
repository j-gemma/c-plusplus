#include <iostream>
#include "FractionClass.h"
#include "input.h"

FractionClass::FractionClass(int num, int den)
	: m_numerator{ num }, m_denominator{ den }
	{

	}

FractionClass FractionClass::multiply(const FractionClass& f) {
	return FractionClass{ m_numerator * f.m_numerator, m_denominator * f.m_denominator };
	}

int FractionClass::getNumerator() const {
	return m_numerator;
	}
	
int FractionClass::getDenominator() const {
	return m_denominator;
	}

FractionClass getFractionFromUser() {
	int num = getIntFromUser("Enter a value for the numerator: ");

	int temp{};
	while (temp == 0) temp = getIntFromUser("Enter a non-zero value for the denominator: ");
	int den = temp;

	return FractionClass{ num, den };
}

void runFractionClass() {
	FractionClass f1{ getFractionFromUser() };

	FractionClass f2{ getFractionFromUser() };

	std::cout << "Your fractions multiplied together: "; 
	printFraction(f1.multiply(f2));

	return;
}

void printFraction(FractionClass f) {
	std::cout << f.getNumerator() << '/' << f.getDenominator() << '\n';
}
