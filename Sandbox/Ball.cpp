#include <iostream>
#include "input.h"
#include "Ball.h"


class Ball {

private:
	std::string m_color{ "black" };
	double m_radius{ 10 };

public:

	Ball(std::string color = "black", double radius = 10) :
		m_color{ color }, m_radius{ radius } {
	}

	Ball(double radius) :
		Ball{ "black", radius} {
	}

	std::string getColor() {
		return m_color;
	}

	double getRadius() {
		return m_radius;
	}
};


void print(Ball b) {
	std::cout << "Ball(" << b.getColor() << ", " << b.getRadius() << ")\n";
}

void runBallClass() {
	/*Ball blue{ "blue", 10.0 };
	print(blue);*/

	/*Ball red{ "red", 12.0 };
	print(red);*/

	Ball def{};
	Ball blue{ "blue" };
	Ball twenty{ 20.0 };
	Ball blueTwenty{ "blue", 20.0 };

	return;

}
