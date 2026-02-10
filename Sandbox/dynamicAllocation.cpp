#include "dynamicAllocation.h"


int dynAlloc() {

	int numNames{ getTFromUser<int>("How many names would you like to enter? ") };

	auto* names{ new std::string[static_cast<std::size_t>(numNames)]{} };

	for (int i{}; i < numNames; ++i) {
		names[i] = getTFromUser<std::string>(std::format("Enter name #{}: ", i + 1));
	}

	std::sort(names, names + numNames);

	std::cout << "\nHere is your sorted list: \n";

	for (int j{}; j < numNames; j++) {
		std::cout << std::format("Name #{}: {}\n",j + 1, names[j]);
	}

	delete[] names;

	return 0;

}

int runDynamicAllocation() {
	dynAlloc();	
	return 0;
}