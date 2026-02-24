#pragma once
#include <iosfwd> // forward declare streams

class Fraction {
public:
    explicit Fraction(int num = 0, int den = 1);

    Fraction multiply(const Fraction& f1);
    
    int getNumerator() const;

    int getDenominator() const;

private:
    int m_numerator{};
    int m_denominator{};
};

void runFractionClass();

void printFraction(Fraction f);