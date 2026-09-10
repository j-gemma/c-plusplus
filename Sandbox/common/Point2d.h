#pragma once

#include <cmath>
#include <iostream>

#include "input.h"

void runPoint2d();

class Point2d {

private:
	double m_x{ 0.0 };
	double m_y{ 0.0 };

public:

	Point2d() = default;

	Point2d(double x, double y)
		: m_x{ x }, m_y{ y }
	{

	}

	void print() const {
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	double distanceTo(Point2d second) {

		return sqrt(pow((second.m_x - m_x), 2) + pow((second.m_y - m_y), 2));

	}
};

