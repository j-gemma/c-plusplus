#include <iostream>
#include <memory>

class QuizFraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	QuizFraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const QuizFraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const QuizFraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int ch22pt5quiz1main()
{
	auto ptr{ std::make_unique<QuizFraction>(3, 5) };

	printFraction(ptr.get());

	return 0;
}


#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	std::weak_ptr<Resource> m_ptr {}; // initially created empty

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int ch22pt7quiz1main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}
