#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

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

class Average {

private:
	std::int32_t m_total{};
	int m_count{};

public:

	Average() {}

	Average& operator+=(std::int32_t toAdd);
	
	friend std::ostream& operator<<(std::ostream& out, const Average avg) {
		if (avg.m_count == 0) out << 0;

		else out << static_cast<double>(avg.m_total) / avg.m_count;

		return out;}
	
};

class IntArray {
private:
	int m_length;
	int* m_arr[];

public:
	IntArray(int len)
		:m_length{ len }
	{
		assert(m_length > 0 && "Oops! Please provide positive array size!\n");

		int* m_arr{ new int[m_length]{} }

	}

};

int testIntArray();

void question1A();

void question1B();

int runOperatorOverloads();
