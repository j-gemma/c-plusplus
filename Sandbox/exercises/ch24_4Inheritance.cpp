#include "ch24_4Inheritance.h"

std::ostream& operator<<(std::ostream& out, Apple apple){

  out << "Apple(" << apple.getName() << ", " <<  apple.getColor() << ", " << apple.getFiber() << ")";
  return out;

}

std::ostream& operator<<(std::ostream& out, Banana banana){

  out << "Banana(" << banana.getName() << ", " <<  banana.getColor() << ")";
  return out;

}

int printFruits()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
