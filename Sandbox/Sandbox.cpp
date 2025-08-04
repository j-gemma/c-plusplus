#include <iostream>
#include "input.h"
#include "Sandbox.h"

class Point2d {


	double m_x{ 0.0 };
	double m_y{ 0.0 };

	Point2d(double x, double y) :
		m_x{ x }, m_y{ y }
	{

	}

public:
	void print() const {
		std::cout << "Point2d(" << m_x << ", " << m_y << ")";
	}
};

int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };

	// Point2d third{ 4.0 }; // should error if uncommented

	first.print();
	second.print();

	return 0;
}