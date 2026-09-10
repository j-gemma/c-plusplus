#include "Point2d.h"

void runPoint2d()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };

	//Point2d third{ 4.0 }; // should error if uncommented

	first.print();
	second.print();

	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	return;
}
