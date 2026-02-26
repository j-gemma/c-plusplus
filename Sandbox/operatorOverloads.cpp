#include "operatorOverloads.h"
#include "Car.h"

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

int runIOOverload() {
    Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}

int runComparisonOverloads() {
    Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}

int runCarSort() {
	std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}


//learncpp.com quiz (ch. 21) solution helped me with this lambda
char& GradeMap::operator[](const std::string_view name) {
	auto found{ std::find_if(m_map.begin(), m_map.end(), [name](const auto& student) {
		return(student.name == name); }) };

	if (found != m_map.end()) return found->grade;
	else {
		m_map.push_back(StudentGrade{std::string{name}});
		return m_map.back().grade;
	}
}

int testGradeMap() {
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}

int runOperatorOverloads()
{
    std::cout << "Question 1A: \n";
	question1A();

    std::cout << "-----------------------------------------\n";
    
    std::cout << "Question 1B: \n";
    question1B();

	std::cout << "-----------------------------------------\n";

    runIOOverload();
	
	std::cout << "-----------------------------------------\n";

	runComparisonOverloads();

	std::cout << "-----------------------------------------\n";

	runCarSort();

	std::cout << "-----------------------------------------\n";

	testGradeMap();

	return 0;
}

