#pragma once

template <typename T>
struct TriadStruct {

	T first{};
	T second{};
	T third{};

};

void runTriadStruct();

template <typename T>
void print(const TriadStruct<T>& triad);