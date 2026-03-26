#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

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

		return out;
	}
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

	IntArray(const IntArray& source)
		: m_length{ source.m_length }
	{
		if (this != &source) deepCopy(source);
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

class FixedPoint2 {
private:
	__int16 m_base{};
	__int8 m_decimal{};

public:

	FixedPoint2(__int16 whole, __int8 frac)
		:m_base{}
		,m_decimal{}
	{
		bool negative{};
		if (whole < 0 || frac < 0) negative = true;

		m_base = static_cast<__int16>(abs(whole) + abs(frac/100));
		m_decimal = static_cast<__int8>(abs(frac % 100));

		if (negative) {
			m_base = -m_base;
			m_decimal = -m_decimal;
		}
	}

	// We'll delegate to the prior constructor so we don't have to duplicate the negative number and overflow handling logic
	FixedPoint2(double d) :
		FixedPoint2(
			static_cast<std::int16_t>(std::trunc(d)),
			static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)
		)
	{
	}

	FixedPoint2 operator-() const;

	//FixedPoint2(double d)
	//{
	//	bool negative{(d < 0)};

	//	double abs_d{ abs(d) };
	//	int floor_abs_d{ static_cast<int>(floor(abs_d)) };
	//	
	//	negative ? *this = FixedPoint2(-static_cast<__int16>(floor_abs_d), static_cast<__int8>(-round(100 * (abs_d - floor_abs_d))))
	//		: *this = FixedPoint2(static_cast<__int16>(std::floor(d)), static_cast<__int8>(round(100 * (abs_d) - floor_abs_d)));

	//}

	friend bool testDecimal(const FixedPoint2& fp);

	explicit operator double() const {
		if (m_base < 0 || m_decimal < 0) return { -(abs(m_base) + (abs(m_decimal / 100.0))) };
		else return m_base + (m_decimal / 100.0);
	}
	
	friend bool operator==(FixedPoint2 fp1, FixedPoint2 fp2);

	friend std::istream& operator>>(std::istream& in, FixedPoint2& fp);

};

FixedPoint2 operator+(FixedPoint2 fp1, FixedPoint2 fp2);

int testIntArray();

int test1FixedPoint2();

int test2FixedPoint2();

void question1A();

void question1B();

int runOperatorOverloads();
