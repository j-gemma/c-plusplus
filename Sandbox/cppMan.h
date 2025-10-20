#pragma once
#include <iostream>
#include <cctype>
#include "ClassRandom.h"
#include "input.h"

namespace WordList {

	static std::vector<std::string> words{ "mystery", "broccoli", "account", "almost",
		"spaghetti", "opinion", "beautiful", "distance", "luggage" };
}

class Session {
private:
	const std::string& m_word{};
	std::vector<char> m_stateDisplay{};
	std::vector<char> m_guessed{};
	int m_guesses{};


public:
	Session()
		:m_word{ WordList::words[Random::get<size_t>(0, size(WordList::words) - 1)] }
		, m_stateDisplay{} {
	}
	const std::string& word() { return m_word; }

	int initStateDisplay();

	int replaceChar(size_t i, char c);

	std::string wordWithGuesses();

	int addToGuessed(char letter);

	int displayState(Session& session);

};

int Session::initStateDisplay() {
	for (char c : this->word()) {
		m_stateDisplay.push_back('_');
	}
	return 0;
}

int Session::replaceChar(size_t i, char c) {
	m_stateDisplay[i] = c;
}

std::string Session::wordWithGuesses() {
	std::string s{ this->word() };
	for (size_t i{}; i < size(s); i++) {
		for (char c : m_guessed) {
			if (c == s[i])	this->replaceChar(i, c);
		}
	}


	return "";
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

int Session::displayState(Session& session) {

	std::cout << std::format("The word is: {}", session.wordWithGuesses());
	

	char letter{ getTFromUser<char>("\nEnter your next letter: ") };
	while (!isalpha(letter)) {
		std::cout << "That wasn't valid input. Please try again\n";
		letter = getTFromUser<char>("Enter your next letter: ");
	}
	session.addToGuessed(letter);

	std::cout << std::format("You entered: {}", letter);

}

int playCPPMan();

const std::string& getWord(size_t i);

int initGame();