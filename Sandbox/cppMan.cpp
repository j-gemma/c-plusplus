#include "cppMan.h"

int playCPPMan() {

	initGame();
	return 0;
}

const std::string& getWord(size_t i) {
	return WordList::words[i];
}

int initGame() {
	Session session{};

	std::cout << "Welcome to C++man (a variant of Hangman)\n"
		"To win : guess the word. To lose : run out of pluses.\n\n";

	std::cout << "The word is: ";
	for (size_t i{}; i < size(session.word()); i++) std::cout << "_";

	char letter{ getTFromUser<char>("\nEnter your next letter: ") };
	while (!isalpha(letter)) {
		std::cout << "That wasn't valid input. Please try again\n";
		letter = getTFromUser<char>("Enter your next letter: ");
	}
	std::cout << std::format("You entered: {}", letter);

	
	return 0;
}