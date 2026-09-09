#include <format>
#include "enumIndex.h"

int runEnumIndex() {
	
	assert(std::size(Animal::legs) == Animal::numAnimals);

	std::cout << std::format("An elephant has {} legs", Animal::legs[Animal::elephant]);

	return 0;

}
