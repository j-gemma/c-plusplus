#pragma once

#include <vector>
#include <cassert>
#include <iostream>

namespace Animals {
	enum Animals {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		numAnimals
	};

	const std::vector legs{ 2, 4, 4, 4, 2, 0 };
}

int runEnumIndex();