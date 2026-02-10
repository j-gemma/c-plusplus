#include "funcPointerCalculator.h"


void runPointerCalculator() {
	UserInput ui;
	char op{ ui.getOperator() };
	ArithmeticFunction fcn{ getArithmeticFunction(op) };
	int x{ ui.getFirstNum() };
	int y{ ui.getSecondNum() };

	std::cout << '\n' << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
	//std::cout << (fcn(ui.getFirstNum(), ui.getSecondNum()));
}

int add(int x, int y) {
	return x + y;
}

int subtract(int x, int y) {
	return x - y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}


ArithmeticFunction getArithmeticFunction(char c) {

	switch (c) {
	case '+': {
		return add;
	}
	case '-': {
		return subtract;
	}
	case '*': {
		return multiply;
	}
	case '/': {
		return divide;
	}
	default:{
		return nullptr; 
	}
	}
}