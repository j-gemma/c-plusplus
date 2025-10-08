#pragma once
#include <iostream>
#include <vector>

int runArrayLoopEx();

int runArraySearch();

template <typename T>
int printArray(std::vector<T>& v);

template <typename T>
int searchArray(std::vector<T>& array, T key);


int askForInt(int minInclusive, int maxInclusive);

