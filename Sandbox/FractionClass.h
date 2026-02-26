#pragma once
#include <iostream>
#include <numeric>
#include <iosfwd> // forward declare streamso
#include "input.h"

class Fraction {
public:
    Fraction(int num = 0, int den = 1);

    Fraction multiply(const Fraction& f1);
    
    int getNumerator() const;

    int getDenominator() const;

    void print() const;

    void reduce();

    friend Fraction operator*(const Fraction& a, const Fraction& b);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

    friend std::istream& operator>>(std::istream& in, Fraction& f);

    friend bool operator==(const Fraction f1, const Fraction f2){ 
        return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator); 
    }

    friend bool operator!=(const Fraction f1, const Fraction f2) {
        return (!operator==(f1, f2));
    }

    friend bool operator<(const Fraction f1, const Fraction f2) {
        return (f2.m_denominator * f1.m_numerator) < (f1.m_denominator * f2.m_numerator);
    }

    friend bool operator>(const Fraction f1, const Fraction f2) {
        return operator<(f2, f1);
    }

    friend bool operator<=(const Fraction f1, const Fraction f2) {
        return !operator>(f1, f2);
    }

    friend bool operator>=(const Fraction f1, const Fraction f2) {
        return !operator<(f1, f2);
    }


   // friend Fraction operator*(const Fraction& a, int b);

   //friend Fraction operator*(int a, const Fraction& b);
private:
    int m_numerator{};
    int m_denominator{};
};

void runFractionClass();


