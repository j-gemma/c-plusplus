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
	int m_guesses{};


public:
	Session()
		:m_word{ WordList::words[Random::get<size_t>(0, size(WordList::words) - 1)] }
		, m_unguessed{ initUnguessed() }
		,m_stateDisplay{ initStateDisplay() }
	{
	}
	const std::string& word() { return m_word; }

	std::string getDisplayState();

	std::vector<char> initStateDisplay();

	std::vector<char> initUnguessed();

	int replaceChar(size_t i, char c);

	int addToGuessed(char letter);

	int displayState();

};

int playCPPMan();

const std::string& getWord(size_t i);

int initGame();