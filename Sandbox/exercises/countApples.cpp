#include <iostream>

std::string_view getQuantityPhrase(int num) {

	switch (num) {
	case 0:
		return "none";

	case 1:
		return "a single";

	case 2:
		return "a couple of";

	case 3:
		return "a few";

	default:
		if (num < 0)return "negative";
		else return "many";
	}
}

std::string_view getApplesPluralized(int numApples) {
	return (numApples == 1) ? "apple" : "apples";
}


int countApples()
{
	constexpr int maryApples{ 3 };
	std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

	std::cout << "How many apples do you have? ";
	int numApples{};
	std::cin >> numApples;

	std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

	return 0;
}