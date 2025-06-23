#pragma once
#include <bitset>

void ignoreLine();

double getDoubleFromUser(void);

int getIntFromUser(std::string message);

char getCharFromUser(std::string message);

char getOperation();

void printResult(double x, double y, char operation);

int getAge(void);

int getNameLength(void);

constexpr bool isEven(int x);

int accumulate(int x);

int calculate(int x, int y, char c);

std::string_view getQuantityPhrase(int num);

std::string_view getApplesPluralized(int numApples);

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits);

int testFactorial();

int runAdder();

int runMult();

int runSub();

int runSwap();

int askWhichPgm();

template< typename T >
T add(T x, T y) {
	return x + y;
}

template< typename T >
T mult(T x, int y) {
	return x * y;
}

template < typename T, typename U >
auto sub(T x, U y){
	return x - y;
}


namespace constants
{
	constexpr double pi{ 3.14159 };
}


using Degrees = double;
using Radians = double;
Radians convertToRadians(Degrees degrees);

template<int N>
constexpr int factorial() {

	static_assert(N >= 0, "factorial(): N must be nonnegative");

	if constexpr (N < 2) return 1;
	else return N * factorial<N - 1>();
}

enum class Animal {
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};


constexpr std::string_view getAnimalName(Animal animal);

void printNumberOfLegs(Animal animal);

void runAnimalLegNums();

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


//int main()
//{
//	std::cout << accumulate(4) << '\n'; // prints 4
//	std::cout << accumulate(3) << '\n'; // prints 7
//	std::cout << accumulate(2) << '\n'; // prints 9
//	std::cout << accumulate(1) << '\n'; // prints 10
//
//	return 0;
//} 