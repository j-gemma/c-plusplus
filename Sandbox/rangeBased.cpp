#include "rangeBased.h"

bool isNameInArray(std::vector<std::string_view>& names, std::string& key) {
	for (std::string_view name : names) {
		if (name == key) return true;
	}
	return false;
}

int runFindName() {

	std::vector<std::string_view> names{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	std::string input{ getTFromUser<std::string>("Enter a name: ") };

	isNameInArray(names, input) ? std::cout << std::format("{} was found.\n", input) :
		std::cout << std::format("{} was not found.\n", input);
	return 0;
}
