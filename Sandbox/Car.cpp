#include "Car.h"

std::ostream& operator<<(std::ostream& out, const Car& c) {
	
	out << "(" << c.m_make << ", " << c.m_model << ")";

	return out;
}

bool operator<(const Car& a, const Car& b) {

	if (a.m_make == b.m_make) return (a.m_model < b.m_model);
	else return a.m_make < b.m_make;
}

bool operator== (const Car& c1, const Car& c2)
{
	return (c1.m_make == c2.m_make &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
	return (c1.m_make != c2.m_make ||
		c1.m_model != c2.m_model);
}

