#include <iostream>
#include "Random.h"
#include "Sandbox.h"

char askPlayAgain() {

	char again{ getCharFromUser("Would you like to play again (y/n)?") };

	if (again == 'y' or again == 'n') return again;
	else return askPlayAgain();
}

int runHiLo() {
	while (true) {

		constexpr int maxTries{ 7 };
		constexpr int lBound{ 1 };
		constexpr int uBound{ 100 };
		int correct{ Random::get(lBound, uBound) };
		int numGuess{ 1 };

		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << maxTries << " tries to guess what it is\n";
		bool winner { false };

		while (numGuess <= 7 && !winner) {
			std::cout << "Guess #" << numGuess++ << '\n';
					
			int guess{ getIntFromUser("") };

			if (guess < correct) std::cout << "Your guess is too low\n";
			else if (guess > correct) std::cout << "Your guess is too high\n";
			else winner = true;

		}
		if (winner) std::cout << "Correct! You win!";
		else std::cout << "Sorry, you lose. The correct number was " << correct << ".\n";

		char again = askPlayAgain();
		ignoreLine();
		
		if (again == 'y');
		else if (again == 'n') break;
	}
	std::cout << "Thank you for playing.'\n'";
	return 0;
}




