#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

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

class MyString {

private:
	std::string m_str{};

public:

	MyString(std::string s)
		:m_str{s}
	{ }

	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
	
	std::string_view operator()(int startIdx, int len);
};


void question1A();

void question1B();

int runOperatorOverloads();
