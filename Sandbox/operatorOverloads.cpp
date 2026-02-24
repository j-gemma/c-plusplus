#include "operatorOverloads.h"

void question1A() {
	Fraction f1{ 1, 4 };
	f1.print();
	
	Fraction f2{ 1, 2 };
	f2.print();

	return;
}


void question1B() {

	Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{ 0, 6 };
    f7.print();

	return;
}


int runOperatorOverloads()
{
    std::cout << "Question 1A: \n";
	question1A();

    std::cout << "-----------------------------------------\n";
    
    std::cout << "Question 1B: \n";
    question1B();

	return 0;
}

