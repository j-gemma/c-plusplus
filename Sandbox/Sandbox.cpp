#include <iostream>
#include <limits>
#include <string>
#include <bitset>
#include <cstdint>
#include <algorithm>
#include "constants.h"
#include "Sandbox.h"

#include <iostream>
#include <limits> // for std::numeric_limits

int runAdder() {
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}

int runMult() {

	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}


int runSub() {
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << factorial<3>();

}

bool hasUnextractedInput() {
	return (!std::cin.eof() && std::cin.peek() != '\n');
}

double getDoubleFromUser(void) {

	double x{};

	std::cout << "Enter a double value: ";

	std::cin >> x;

	return x;


}

int getIntFromUser(std::string message) {
	while (true) {
		int x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}
		
		if (x < 1 || x > 100) {
			message = "Whoops! Try again.";
			continue;
		}
		
		return x;
  }

}

namespace Monster {
	enum MonsterType {
		orc,
		goblin,
		troll,
		ogre,
		skeleton
	};
}
	

int mainFunc() {
	[[maybe_unused]]Monster::MonsterType monster{ Monster::MonsterType::troll };
	return 0;
}

char getCharFromUser(std::string message) {
	while (true) {
		char x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		return x;
	}
	
	
}

char getOperation() {

	char x{};

	std::cout << "Enter +, -, *, or /: ";

	std::cin >> x;

	return x;
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

int getAge(void) {

	int age{};
	std::cout << "Enter your age: ";
	std::cin >> age;
	return age;

}

int getNameLength(void) {

	std::string name{};
	std::cout << "Enter your full name: ";
	std::getline(std::cin >> std::ws, name);

	return static_cast<int>(name.length());

}

constexpr bool isEven(int x) {
	return !(x % 2);
}

// Write the function getQuantityPhrase() here

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

// Write the function getApplesPluralized() here

std::string_view getApplesPluralized(int numApples) {
	return (numApples == 1) ? "apple" : "apples";
}

//int countApples()
//{
//	constexpr int maryApples{ 3 };
//	std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";
//
//	std::cout << "How many apples do you have? ";
//	int numApples{};
//	std::cin >> numApples;
//
//	std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";
//
//	return 0;
//}

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
	return bits >> 3 | bits << 1;
}

//int rotateBits()
//{
//	std::bitset<4> bits1{ 0b0001 };
//	std::cout << rotl(bits1) << '\n';
//
//	std::bitset<4> bits2{ 0b1001 };
//	std::cout << rotl(bits2) << '\n';
//
//	return 0;
//}

//int bitFlags()
//{
//	[[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
//	[[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
//	[[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
//	[[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
//	[[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };
//
//	std::uint8_t myArticleFlags{ option_favorited };
//
//	myArticleFlags &= option_deleted;
//
//	std::cout << std::bitset<8>{ myArticleFlags } << '\n';
//
//	return 0;
//} 

//int compareInt() {
//
//	int smaller{ getIntFromUser() };
//
//	int larger{ getIntFromUser() };
//
//	if (smaller > larger) {
//		std::cout << "Swapping values.\n";
//		int temp{ smaller };
//		smaller = larger;
//		larger = temp;
//	}
//
//	std::cout << "The larger value is:" << larger << '\n';
//
//	std::cout << "The smaller value is:" << smaller;
//
//
//}

//int main()
//{
//	std::cout << "How many students are in your class? ";
//	int students{};
//	std::cin >> students;
//
//
//	if (students > Constants::maxClassSize)
//		std::cout << "There are "<< students - Constants::maxClassSize << " too many students in this class";
//	else
//		std::cout << "This class isn't too large";
//
//	return 0;
//}

int accumulate(int x) {
	static int accumulator{ 0 };

	return accumulator += x;
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

int testFactorial()
{
	static_assert(factorial<0>() == 1);
	static_assert(factorial<3>() == 6);
	static_assert(factorial<5>() == 120);

	//factorial<-3>(); // should fail to compile

	return 0;
}


using Degrees = double;
using Radians = double;

Radians convertToRadians(Degrees degrees)
{
	return degrees * constants::pi / 180;
}

int runAliases()
{
	std::cout << "Enter a number of degrees: ";
	Degrees degrees{};
	std::cin >> degrees;

	Radians radians{ convertToRadians(degrees) };
	std::cout << degrees << " degrees is " << radians << " radians.\n";

	return 0;
}

int askWhichPgm() {
	return getIntFromUser("Which program?");
}

void sort2(int& x, int& y) {
	if (x > y) {
		std::swap(x, y);
	}
}

int runSwap()
{
	int x{ 7 };
	int y{ 5 };

	std::cout << x << ' ' << y << '\n'; // should print 7 5

	sort2(x, y); // make sure sort works when values need to be swapped
	std::cout << x << ' ' << y << '\n'; // should print 5 7

	sort2(x, y); // make sure sort works when values don't need to be swapped
	std::cout << x << ' ' << y << '\n'; // should print 5 7

	return 0;
}

constexpr std::string_view getAnimalName(Animal animal) {
	using enum Animal;

	switch (animal) {
	case pig: return "pig";
	case chicken: return "chicken";
	case goat: return "goat";
	case cat: return "cat";
	case dog: return "dog";
	case duck: return "duck";

	default: return "wyd";
	}

}

void printNumberOfLegs(Animal animal) {
	using enum Animal;

	std::cout << "A " << getAnimalName(animal) << " has ";

	switch (animal) {
	case pig:
	case goat:
	case cat:
	case dog:
		std::cout << 4;
		break;
	
	case chicken:
	case duck: 
		std::cout << 2;
		break;

	default: std::cout << "idk man\n";
	}

	std::cout << " legs.\n";
}

void runAnimalLegNums() {

	using enum Animal;

	Animal kitty{ cat };
	printNumberOfLegs(kitty);
	printNumberOfLegs(chicken);
}


//int main()
//{
//	std::cout << accumulate(4) << '\n'; // prints 4
//	std::cout << accumulate(3) << '\n'; // prints 7
//	std::cout << accumulate(2) << '\n'; // prints 9
//	std::cout << accumulate(1) << '\n'; // prints 10
//
//	return 0;
//} 