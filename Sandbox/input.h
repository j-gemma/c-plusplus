#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <optional>

double getDoubleFromUser(void);

double getDoubleFromUser(std::string message);

int getIntFromUser(std::string message);

int getIntFromUserWithBounds(std::string message, int lbound = 1, int ubound = 100);

int getIntFromUserWithLowerBound(std::string message, int lbound = 1);

char getCharFromUser(std::string message);

char getOperation();

int getAge(void);

int getNameLength(void);

void ignoreLine();

bool hasUnextractedInput();

char askPlayAgain();

template <typename T>
T getTFromUser(std::string message = "") {
	while (true) {
		T x{};
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
