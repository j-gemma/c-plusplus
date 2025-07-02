#pragma once

template <typename T>
struct Triad {

	T first{};
	T second{};
	T third{};

};

void runTriad();

template <typename T>
void print(const Triad<T>& triad);