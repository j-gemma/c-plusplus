#pragma once
#include <iostream>
#include <vector>
#include "input.h"
#include <cassert>

int runArrayLoopEx();

int runArraySearch();

template <typename T>
int printArray(std::vector<T>& v);

template <typename T>
int findKey(std::vector<T>& array, T key);

template <typename T>
T arraySearch(std::vector<T>&, T min, T max);

int fizzBuzz(int max);

int askForInt(int minInclusive, int maxInclusive);

template <typename T>
T findMax(std::vector<T> array);


template <typename T>
T askForT(T minInclusive, T maxInclusive);

int runFindMax();

int runFizzBuzz();