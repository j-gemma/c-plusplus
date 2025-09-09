#include <iostream>
#include "triadStruct.h"

template <typename T>
void print(const TriadStruct<T>& triad) {
	std::cout << "[" << triad.first << ", " << triad.second << ", " << triad.third << "]";
}

void runTriadStruct()
{
	TriadStruct t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	TriadStruct t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);
}