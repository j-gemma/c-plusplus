#pragma once

struct Fraction {
	int numerator{};
	int denominator{};
};

Fraction multiplyFractions(Fraction f1, Fraction f2);

Fraction getFractionFromUser();

void runMultiplyFractions();

void printFraction(Fraction frac);

