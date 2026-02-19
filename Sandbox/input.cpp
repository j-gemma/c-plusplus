#include <iostream>
#include <string>
#include "input.h"

double getDoubleFromUser(void) {

	double x{};

	std::cout << "Enter a double value: ";

	std::cin >> x;

	ignoreLine();
	return x;

}

double getDoubleFromUser(std::string message) {
	while (true) {
		double x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		ignoreLine();
		return x;
	}

}

int getIntFromUser(std::string message) {
	while (true) {
		int x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		ignoreLine();
		return x;
	}

}

int getIntFromUserWithBounds(std::string message, int lbound, int ubound) {
	while (true) {
		int x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		if (x < lbound || x > ubound) {
			message = "Whoops! Try again.";
			continue;
		}

		ignoreLine();
		return x;
	}

}

int getIntFromUserWithLowerBound(std::string message, int lbound) {
	while (true) {
		int x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		if (x < lbound) {
			message = "Whoops! Try again.";
			continue;
		}

		ignoreLine();
		return x;

	}
}

char getCharFromUser(std::string message) {
	while (true) {
		char x{};
		std::cout << message;
		std::cin >> x;

		if (!std::cin) {
			//Handle failure
			message = "Whoops! Try again.";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		//If extraneous input, treat as failure case
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}

		ignoreLine();
		return x;
	}


}

char getOperation() {

	char x{};

	std::cout << "Enter +, -, *, or /: ";

	std::cin >> x;

	return x;
}

int getAge(void) {

	int age{};
	std::cout << "Enter your age: ";
	std::cin >> age;
	return age;

}

int getNameLength(void) {

	std::string name{};
	std::cout << "Enter your full name: ";
	std::getline(std::cin >> std::ws, name);

	return static_cast<int>(name.length());

}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

bool hasUnextractedInput() {
	return (!std::cin.eof() && std::cin.peek() != '\n');
}

std::vector<int> getPositiveIntsFromUser() {

	std::cout << "Enter numbers to add (use -1 to stop): ";
	std::vector<int> ints{};

	while (true) {

		int x{};
		std::cin >> x;

		if (x == -1) break;

		if (!std::cin) {
			//Handle failure
			std::cout << "Whoops! Try again.";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		////If extraneous input, treat as failure case
		//if (hasUnextractedInput()) {
		//	ignoreLine();
		//	continue;
		//}

		//ignoreLine();
		ints.push_back(x);
	}
	return ints;
}

char askPlayAgain() {

	char again{ getCharFromUser("Would you like to play again (y/n)?") };

	if (again == 'y' or again == 'n') return again;
	else return askPlayAgain();
}