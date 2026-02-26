#pragma once
#include <algorithm>
#include <string>
#include <vector>

#include "FractionClass.h"

struct StudentGrade {
	const std::string name{};
	char grade{};
};

class GradeMap {
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](std::string_view name);
};


void question1A();

void question1B();

int runOperatorOverloads();
