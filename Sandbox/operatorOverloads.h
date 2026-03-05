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
	int m_length{ 0 };
	int* m_arr{ nullptr };

public:
	explicit IntArray(int len)
		:m_length{ len }
	{
		assert(m_length > 0 && "Oops! Please provide positive array size!\n");

		m_arr = new int[static_cast<size_t>(m_length)] {};

	}

	~IntArray() {
		delete m_arr;
	}

void deepCopy(const IntArray& source);

IntArray& operator=(const IntArray& source);

//int& operator[](const size_t index);

int& operator[](const size_t index) {
	assert(index < m_length);
	return m_arr[index];
}

int& operator[](const size_t index) const {
	assert(index < m_length);
	return m_arr[index];
}

friend std::ostream& operator<<(std::ostream& out, const IntArray& arr) {
	for (size_t i{}; i < arr.m_length; i++) {
		out << arr[i] << " ";
	}

	return out;
}

};

int testIntArray();

void question1A();

void question1B();

int runOperatorOverloads();
