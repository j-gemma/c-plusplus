#include <iostream>
#include "triad.h"

template <typename T>
void print(const Triad<T>& triad) {
	std::cout << "[" << triad.first << ", " << triad.second << ", " << triad.third << "]";
}

void runTriad()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);
}