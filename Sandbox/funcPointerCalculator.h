#pragma once
#include "input.h"
#include <functional>
#include <iostream>

class UserInput {
	int m_firstNum{};
	char m_operator{};
	int m_secondNum{};

public:
	UserInput()
		: m_firstNum{ getTFromUser<int>("\nEnter an integer: ") }
		, m_operator{ getMathOperator() }
		, m_secondNum{ getTFromUser<int>("\nEnter an integer: ") }
	{
		if (m_operator == '/') {
			while (m_secondNum == 0) {
				m_secondNum = getTFromUser<int>("\nCannot divide by 0, please pick another integer: ");
			}
		}
	}

	char getOperator() { return m_operator; }

	int getFirstNum() { return m_firstNum; }

	int getSecondNum() { return m_secondNum; }

private:

	char getMathOperator() {
		char temp{ getTFromUser<char>("\nEnter an operator (+, -,*, / ) :") };
		if (temp == '+' ||
			temp == '-' ||
			temp == '*' ||
			temp == '/') return temp;
		else return getMathOperator();
	}

};

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char c);

void runPointerCalculator();



