#include "perfectSquares.h"

static constexpr int squares[]{ 0, 1, 4, 9 };

int getSingleDigitInt() {

	int a{};
	do { a = getTFromUser<int>("Enter a nonnegative single digit int, or -1 to quit: "); }
	while (a < -1 || a >= 10);

	return a;
}

bool matchSquare(int a) {

	for (auto i : squares) {
			if (a == i) {
				return true;
			}
		}
		
	return false;

}

int runPerfectSquares() {

	while (true) {
		int a{ getSingleDigitInt() };
		if (a == -1) {
			std::cout << "Bye";
			break;
		}
		if (matchSquare(a)) std::cout << std::format("{} is a perfect square\n", a);
		else std::cout << std::format("{} is not a perfect square\n", a);
	}
	
	return 0;
}
