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

std::ostream& operator<<(std::ostream& out, const MyString& str) 
{
	out << str.m_str;

	return out;
}

std::string_view MyString::operator()(int startIdx, int len) {
	std::string_view look{ m_str };

	return std::string_view{ m_str }.substr(static_cast<size_t>(startIdx), static_cast<size_t>(len));
}

int testMyString() {
	
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}

int testAverageClass() {
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}

Average& Average::operator+=(std::int32_t toAdd) {
	m_total += toAdd;
	m_count++;
	return *this;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

void IntArray::deepCopy(const IntArray& source) {
	delete[] m_arr;

	m_length = source.m_length;

	if (source.m_arr) {
		m_arr = new int[static_cast<size_t>(m_length)];

		for (int i{}; i < m_length; i++) {
			m_arr[i] = source.m_arr[i];

		}
	}
	else m_arr = nullptr;
}

IntArray& IntArray::operator=(const IntArray& source) {
	if (this != &source) deepCopy(source);
	return *this;
}

//int& IntArray::operator[](const size_t index) {
//	assert(index >= 0 && index < m_length);
//	return m_arr[index];
//}

int testIntArray() {
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}

// This doesn't require access to the internals of the class, so it can be defined outside the class
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
	out << static_cast<double>(fp);
	return out;
}

int test1FixedPoint2() {
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);
	std::cout << static_cast<double>(b) << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << static_cast<double>(c) << '\n';
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);
	std::cout << static_cast<double>(d) << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << static_cast<double>(e) << '\n';
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);
	std::cout << static_cast<double>(f) << '\n';

	return 0;
}

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2 &fp)
{
    if (fp.m_base >= 0)
        return fp.m_base >= 0 && fp.m_decimal < 100;
    else
        return fp.m_base <= 0 && fp.m_decimal > -100;
}

int test2FixedPoint2() {

	FixedPoint2 a{ 1, 104 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 2.04);
	assert(testDecimal(a));

	FixedPoint2 b{ 1, -104 };
	assert(static_cast<double>(b) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c{ -1, 104 };
	assert(static_cast<double>(c) == -2.04);
	assert(testDecimal(c));

	FixedPoint2 d{ -1, -104 };
	assert(static_cast<double>(d) == -2.04);
	assert(testDecimal(d));

	return 0;
}

int test3FixedPoint2() {

	FixedPoint2 a{ 0.01 };
	std::cout << a << '\n';

	assert(static_cast<double>(a) == 0.01);

	FixedPoint2 b{ -0.01 };
	std::cout << b << '\n';

	assert(static_cast<double>(b) == -0.01);

	FixedPoint2 c{ 1.9 }; // make sure we handle single digit decimal
	std::cout << c << '\n';

	assert(static_cast<double>(c) == 1.9);

	FixedPoint2 d{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	std::cout << d << '\n';

	assert(static_cast<double>(d) == 5.01);

	FixedPoint2 e{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	std::cout << e << '\n';

	assert(static_cast<double>(e) == -5.01);

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 f{ 106.9978 }; // should be stored with base 107 and decimal 0
	std::cout << f << '\n';

	assert(static_cast<double>(f) == 107.0);

	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
	FixedPoint2 g{ -106.9978 }; // should be stored with base -107 and decimal 0
	std::cout << g << '\n';

	assert(static_cast<double>(g) == -107.0);

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
	
	std::cout << "-----------------------------------------\n";

	testMyString();

	std::cout << "-----------------------------------------\n";

	testAverageClass();

	std::cout << "-----------------------------------------\n";

	testIntArray();

	std::cout << "-----------------------------------------\n";

	test1FixedPoint2();

	std::cout << "-----------------------------------------\n";

	test2FixedPoint2();

	std::cout << "-----------------------------------------\n";

	test3FixedPoint2();

	return 0;
}

