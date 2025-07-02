#include <iostream>
#include <bitset>
#include "miscUnused.h"
#include "input.h"

namespace Monster {
	enum MonsterType {
		orc,
		goblin,
		troll,
		ogre,
		skeleton
	};
}

int scopedEnumFunctionExample() {
	[[maybe_unused]]Monster::MonsterType monster{ Monster::troll };
	return 0;
}

int testFactorial()
{
	static_assert(factorial<0>() == 1);
	static_assert(factorial<3>() == 6);
	static_assert(factorial<5>() == 120);

	//factorial<-3>(); // should fail to compile

	return 0;
}

constexpr bool isEven(int x) {
	return !(x % 2);
}

int calculate(int x, int y, char c) {
	switch (c) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	case '%': return x % y;
	default: return 0;
	}
}

void printResult(double x, double y, char operation) {

	switch (operation) {

	case '+':
		std::cout << x << " + " << y << " is " << x + y;
		break;

	case '-':
		std::cout << x << " - " << y << " is " << x - y;
		break;

	case '*':
		std::cout << x << " * " << y << " is " << x * y;
		break;

	case '/':
		std::cout << x << " / " << y << " is " << x / y;
		break;

	default:
		std::cout << "";

	}
}

int bitFlags()
{
	[[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
	[[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
	[[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
	[[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
	[[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

	std::uint8_t myArticleFlags{ option_favorited };

	myArticleFlags &= option_deleted;

	std::cout << std::bitset<8>{ myArticleFlags } << '\n';

	return 0;
} 

void compareInt() {

	int smaller{ getIntFromUser("")};

	int larger{ getIntFromUser("")};

	if (smaller > larger) {
		std::cout << "Swapping values.\n";
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	}

	std::cout << "The larger value is:" << larger << '\n';

	std::cout << "The smaller value is:" << smaller;


}
