#pragma once

template<int N>
constexpr int factorial() {

	static_assert(N >= 0, "factorial(): N must be nonnegative");

	if constexpr (N < 2) return 1;
	else return N * factorial<N - 1>();
}

int testFactorial();

void printResult(double x, double y, char operation);

constexpr bool isEven(int x);

int calculate(int x, int y, char c);
