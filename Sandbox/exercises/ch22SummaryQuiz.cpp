#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int ch22SummaryQuizMain()
{
  //myAnswer
	auto res{ std::make_shared<Resource>() };
	std::shared_ptr<Resource> ptr1{ res };
	std::shared_ptr<Resource> ptr2{ ptr1 };

  //quiz Answer
  //auto ptr1{ std::make_shared<Resource>() };
  //auto ptr2{ ptr1 };

	return 0;
}
