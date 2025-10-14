#pragma once

#include <iostream>
#include <vector>
#include "input.h"

bool isNameInArray(std::vector<std::string_view>& names, std::string& key);

int runFindName();

template <typename T>
bool isValueInArray(std::vector<T>& array,  const T& key) {
	for (const auto& value : array) {
		if (value == key) return true;
	}
	return false;
}