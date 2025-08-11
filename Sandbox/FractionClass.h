#pragma once
#include <iosfwd> // forward declare streams

class FractionClass {
public:
    explicit FractionClass(int num = 0, int den = 1);

    FractionClass multiply(const FractionClass& f1);
    
    int getNumerator() const;

    int getDenominator() const;

private:
    int m_numerator{};
    int m_denominator{};
};

void runFractionClass();

void printFraction(FractionClass f);