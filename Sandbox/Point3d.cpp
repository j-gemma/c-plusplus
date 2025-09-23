#include <iostream>
#include "input.h"
#include "Point3d.h"
#include "Vector3d.h"

Point3d::Point3d(double x, double y, double z)
	: m_x{ x }, m_y{ y }, m_z{ z }
{
}

void Point3d::print() const
{
	std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point3d::setValues(int xval, int yval, int zval) {
	m_x = xval;
	m_y = yval;
	m_z = zval;
}

bool Point3d::isEqual(Point3d p) const {
	return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
}

void Point3d::moveByVector(const Vector3d& v) {
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void runClassExample() {

	Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

	return;

}



