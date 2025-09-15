#include <chrono>
#include <random>
#include <iostream>

class Random
{
private:
	static std::mt19937 generate()
	{
		std::random_device rd{};

		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd(), };

		return std::mt19937{ ss };

	}

	static inline std::mt19937 mt{ generate() };

public:

	static int get(int min, int max) { return std::uniform_int_distribution{ min, max }(mt); }

};



	//inline std::mt19937 generate()
	//{
	//	std::random_device rd{};

	//	// Create seed_seq with clock and 7 random numbers from std::random_device
	//	std::seed_seq ss{
	//		static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
	//			rd(), rd(), rd(), rd(), rd(), rd(), rd() };

	//	return std::mt19937{ ss };
	//}

	// Here's our global std::mt19937 object.
	// The inline keyword means we only have one global instance for our whole program.
	//static inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

	// Generate a random int between [min, max] (inclusive)
		// * also handles cases where the two arguments have different types but can be converted to int
	//inline int get(int min, int max)
	//{
	//	return std::uniform_int_distribution{ min, max }(mt);
	//}


void runRandomClass()
{
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

	return;
}