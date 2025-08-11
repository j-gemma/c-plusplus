#pragma once

struct FractionStruct {
	int numerator{};
	int denominator{};
};

FractionStruct multiplyFractions(FractionStruct f1, FractionStruct f2);

FractionStruct getFractionFromUser();

void runFractionStruct();

void printFraction(FractionStruct frac);

