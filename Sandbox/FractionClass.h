#pragma once
#include <iostream>
#include <numeric>
#include <iosfwd> // forward declare streams

class Fraction {
public:
    Fraction(int num = 0, int den = 1);

    Fraction multiply(const Fraction& f1);
    
    int getNumerator() const;

    int getDenominator() const;

    void print() const;

   void reduce();

    friend Fraction operator*(const Fraction& a, const Fraction& b);

   // friend Fraction operator*(const Fraction& a, int b);

   //friend Fraction operator*(int a, const Fraction& b);
private:
    int m_numerator{};
    int m_denominator{};
};

void runFractionClass();


