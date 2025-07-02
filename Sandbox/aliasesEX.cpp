#include <iostream>
#include "constants.h"
#include "aliasesEX.h"

using namespace Constants;

int runAliases()
{
	std::cout << "Enter a number of degrees: ";
	Degrees degrees{};
	std::cin >> degrees;

	Radians radians{ convertToRadians(degrees) };
	std::cout << degrees << " degrees is " << radians << " radians.\n";

	return 0;
}

Radians convertToRadians(Degrees degrees)
{
	return degrees * pi / 180;
}