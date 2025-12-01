#include "classRandom.h"

std::mt19937 Random::generate()
{
	std::random_device rd{};

	std::seed_seq ss{
		static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
		rd(), rd(), rd(), rd(), rd(), rd(), rd(), };

	return std::mt19937{ ss };

}

void runRandomClass()
{
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

	return;
}