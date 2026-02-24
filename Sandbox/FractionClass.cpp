#include <iostream>
#include "FractionClass.h"
#include "input.h"

Fraction::Fraction(int num, int den)
	: m_numerator{ num }, m_denominator{ den }
	{

	}

Fraction Fraction::multiply(const Fraction& f) {
	return Fraction{ m_numerator * f.m_numerator, m_denominator * f.m_denominator };
	}

int Fraction::getNumerator() const {
	return m_numerator;
	}
	
int Fraction::getDenominator() const {
	return m_denominator;
	}

Fraction getFractionFromUser() {
	int num = getIntFromUser("Enter a value for the numerator: ");

	int temp{};
	while (temp == 0) temp = getIntFromUser("Enter a non-zero value for the denominator: ");
	int den = temp;

	return Fraction{ num, den };
}

void runFractionClass() {
	Fraction f1{ getFractionFromUser() };

	Fraction f2{ getFractionFromUser() };

	std::cout << "Your fractions multiplied together: "; 
	printFraction(f1.multiply(f2));

	return;
}

void printFraction(Fraction f) {
	std::cout << f.getNumerator() << '/' << f.getDenominator() << '\n';
}
