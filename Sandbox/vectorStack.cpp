#include "vectorStack.h"

int pushValue(int value, std::vector<int>& stack) {
	
	stack.push_back(value);
	std::cout << "Push " << value << "\t";
	printStack(stack);

	return 0;
}

int popValue(std::vector<int>& stack) {
	
	stack.pop_back();
	std::cout << "Pop " << "\t";
	printStack(stack);
	return 0;

}


int printStack(std::vector<int>& stack) {

	if (stack.empty()) {
		std::cout << "(Stack: empty)\n";
	}
	else {
		std::cout << "(Stack: ";

		for (auto i : stack) {
			std::cout << " " << i;
		}
		std::cout << ")\n";
	}

	return 0;
}

int runVectorStack() {
	std::vector<int> stack{};

	pushValue(1, stack);
	pushValue(2, stack);
	pushValue(3, stack);
	popValue(stack);
	pushValue(4, stack);
	for ([[maybe_unused]]int i : stack) {
		popValue(stack);
	}

	return 0;

}