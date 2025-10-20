#pragma once
#include <chrono>
#include <random>
#include <iostream>

class Random
{
private:
	static std::mt19937 generate();

	static inline std::mt19937 mt{ generate() };

public:

	static int get(int min, int max) { return std::uniform_int_distribution{ min, max }(mt); }

	template <typename T>
	static T get(T min, T max) { return std::uniform_int_distribution<T>{min, max}(mt); }
};

void runRandomClass();