#include "cppMan.h"

int playCPPMan() {
	while (true) {

		std::cout << "Welcome to cppman!!!\n\n";
		Session session{ };

		int state{ 0 };
		while (state == 0) {
			session.displayState();
			state = session.processGuess(session.getGuess());
		}

		switch (state) {

		case 1: {
			std::cout << "Hooray! You win!\n";
			break;
		}case -1: {
			std::cout << std::format("Better luck next time...the word was {}\n", session.word()) ;
			break;
		}
		default: {
			"Wtf dude!?!?!? How did you get here?";
			break;
		}

		}

		char again{ askPlayAgain() };

		if (again == 'y') {}
		else if (again == 'n') break;

	}
	std::cout << "Thank's for playing!";
	return 0;
}

const std::string& getWord(size_t i) {
	return WordList::words[i];
}

int Session::replaceDisplayIndex(size_t i, char c) {
	m_stateDisplay[i] = c;
	return 0;
}


int Session::displayState() {

	std::cout << std::format("The word is: {}", this -> getDisplayState());
	return 0;
}

std::vector<char> Session::initStateDisplay() {
	std::vector<char> stateDisplay{};
	for (size_t i{}; i < size(this->word()); i++) {
		stateDisplay.push_back('_');
	}
	return stateDisplay;
}

bool isInVector(char c, std::vector<char> check) {
	for (char d : check) if (c == d) return true;
	return false;
}

std::vector<char> Session::initUnguessed() {
	std::vector<char> temp{};
	for (char c : this->word()) {
		if (!isInVector(c, m_unguessed)) temp.push_back(c);
	}
	return temp;
}

std::string Session::getDisplayState() {
	std::string displayState{};
	for (char c : m_stateDisplay) {
		displayState += c;
	}
	displayState += "\t Guesses left : ";
	for (int i{}; i < m_guessesLeft; i++) {
		displayState += '+';
	}
	
	displayState += '\n';
	return displayState;
}

char Session::getGuess() {

	char userIn{ getTFromUser<char>("Enter your next letter: ")};

	if (!isalpha(userIn)) {
		std::cout << "That wasn't valid input. Please try again\n";
		return getGuess();
	}
	if (isInVector(userIn, m_guessed)) {
		std::cout << "You already guessed that. Try again\n";
		return getGuess();
	}
	m_guessed.push_back(userIn);
	return userIn;
}

int Session::processGuess(char guess) {
	if (isInVector(guess, m_unguessed)) {
		for (size_t i{}; i < size(m_word); i++) {
			if (m_word[i] == guess) {
				replaceDisplayIndex(i, guess);
			}
		}
		m_unguessed.erase(std::find(m_unguessed.begin(), m_unguessed.end(), guess));
		if (m_unguessed.empty()) return 1;
	
	}

	else {
		--m_guessesLeft;
		if (m_guessesLeft == 0) return -1;
	}
	return 0;

}