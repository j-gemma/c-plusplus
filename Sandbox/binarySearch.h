#pragma once
#include <iostream>
#include <iterator>
#include <numeric>
#include <cassert>
#include <functional>

#include "input.h"

using BinarySearch = std::function<int(const int* array, int target, int min, int max)>;

int iterativeBinarySearch(const int* array, int target, int min, int max);

int recursiveBinarySearch(const int* array, int target, int min, int max);

int runBinarySearch();
