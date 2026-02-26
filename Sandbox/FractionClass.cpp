#include "FractionClass.h"

Fraction::Fraction(int num, int den)
	: m_numerator{ num }, m_denominator{ den }
	{
	reduce();
	}

void Fraction::print() const {
	std::cout << m_numerator << '/' << m_denominator << '\n';
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
	f1.multiply(f2).print();

	return;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
	return Fraction(a.m_numerator * b.m_numerator, a.m_denominator * b.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {

    out << f.m_numerator << '/' << f.m_denominator;

    return out;

}

std::istream& operator>>(std::istream& in, Fraction& f) {
    
	int x{};
    int y{};
	char ignore{};

    in >> x >> ignore >> y;
    if (y == 0) in.setstate(std::ios_base::failbit);

    f = in ? Fraction{ x, y } : Fraction{};
    
    return in;

}

void Fraction::reduce() {
	int gcd{ std::gcd(m_numerator, m_denominator) };
	if (gcd) {
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

}


//Fraction operator*(Fraction a, int b) {
//	return Fraction(a.m_numerator * b, a.m_denominator);
//}

//Fraction operator*(int a, Fraction b) { return operator*(b, a); }
