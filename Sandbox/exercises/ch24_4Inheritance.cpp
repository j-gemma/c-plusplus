#include "ch24_4Inheritance.h"

std::ostream& operator<<(std::ostream& out, const Apple& apple){

  out << "Apple(" << apple.getName() << ", " <<  apple.getColor() << ", " << apple.getFiber() << ")";
  return out;

}

std::ostream& operator<<(std::ostream& out, const Banana& banana){

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

int printFruits2()
{

	Apple a{ "red" };
	Banana b{};
  GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
