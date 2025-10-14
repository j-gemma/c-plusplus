#include "enumIndex.h"

int runEnumIndex() {
	
	assert(std::size(Animals::legs) == Animals::numAnimals);

	std::cout << std::format("An elephant has {} legs", Animals::legs[Animals::elephant]);

	return 0;

}