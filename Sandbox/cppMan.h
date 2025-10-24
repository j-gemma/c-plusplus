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
	std::vector<char> m_unguessed{};
	std::vector<char> m_stateDisplay{};
	std::vector<char> m_guessed{};
	int m_guessesLeft{};


public:
	Session()
		: m_word{ WordList::words[Random::get<size_t>(0, size(WordList::words) - 1)] }
		, m_unguessed{ initUnguessed() }
		, m_stateDisplay{ initStateDisplay() }
		, m_guessesLeft{ 10 }
	{
	}

	const std::string& word() const { return m_word; }

	int guessesLeft() const { return m_guessesLeft; }

	std::string getDisplayState();

	std::vector<char> initStateDisplay();

	std::vector<char> initUnguessed();

	int replaceDisplayIndex(size_t i, char c);

	int displayState();
	
	char getGuess();

	int processGuess(char guess);
};

int playCPPMan();