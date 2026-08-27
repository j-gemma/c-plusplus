#include "ch23_7quiz.h"
#include <initializer_list>
#include <random>

//my wrong answer... I forgot I could access members of 'this'... even though I'm in chapter 23/28 lmao
//long day + brainfart, I guess.
//Note: this does print the correct result, but does not match the code solution on learncpp.com
//I will have to come back to this and investigate whether this is an acceptable alternate implementation
//and why or why not.
//
//void IntArray::operator=(std::initializer_list<int> list){
//  delete this->m_data;
//  this->m_length = list.size();
//  this->m_data = new int[static_cast<int>(list.size())] {};
//
//  std::copy(list.begin(), list.end(), this->m_data);
//}

//correct answer - I peeked at the solution but I'm writing this now without looking at it
IntArray& IntArray::operator=(std::initializer_list<int> list){
  int length{static_cast<int>(list.size())};

  if(length != m_length){
    delete m_data;
    m_length = length;
    m_data = new int[length];
  }

  std::copy(list.begin(), list.end(), m_data);

  return *this;
}

int ch23_7quizMain()
{
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}
