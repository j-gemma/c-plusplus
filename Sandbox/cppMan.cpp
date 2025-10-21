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

	session.displayState();
	
	return 0;
}

int Session::replaceChar(size_t i, char c) {
	m_stateDisplay[i] = c;
	return 0;
}

int Session::addToGuessed(char letter) {
	for (char c : m_guessed) {
		if (c == letter) {
			std::cout << "You already guessed that letter.";
			return 1;
		}
	}
	m_guessed.push_back(letter);
	return 0;
}

int Session::displayState() {

	std::cout << std::format("The word is: {}", this -> getDisplayState());

	char letter{ getTFromUser<char>("\nEnter your next letter: ") };
	while (!isalpha(letter)) {
		std::cout << "That wasn't valid input. Please try again\n";
		letter = getTFromUser<char>("Enter your next letter: ");
	}
	this -> addToGuessed(letter);

	std::cout << std::format("You entered: {}", letter);
	return 0;
}

std::vector<char> Session::initStateDisplay() {
	std::vector<char> stateDisplay{};
	for (size_t i{}; i < size(this->word()); i++) {
		stateDisplay.push_back('_');
	}
	return stateDisplay;
}

std::vector<char> Session::initUnguessed() {
	std::vector<char> unguessed{};
	for (char c : this->word()) {
		unguessed.push_back(c);
	}
	return unguessed;
}

std::string Session::getDisplayState() {
	std::string displayState{};
	for (char c : m_stateDisplay) {
		displayState += c;
	}
	return displayState;
}