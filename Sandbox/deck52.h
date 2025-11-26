#pragma once
#include <iostream>

#include "projectHeaders.h"

struct Card {
	enum Rank {
		ace,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		max_rank,
	};

	enum Suit {
		club,
		heart,
		diamond,
		spade,
		max_suit
	};

	Rank rank{};
	Suit suit{};

	static constexpr std::array<Card::Rank, max_rank> allRanks{ ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };
	static constexpr std::array<Card::Suit, max_suit> allSuits{ club, diamond, heart, spade };
	
	friend std::ostream& operator<<(std::ostream& out, const Card& card) {
		static constexpr std::array<char, max_rank> ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		static constexpr std::array<char, max_suit> suits{ 'C', 'H', 'D', 'S' };

		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int value() const{
		constexpr std::array rankValues {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10 };
		return rankValues[rank];
	}

};

struct Player {
	int m_score{};

	void setScore(int score) { m_score = score; }

	int getScore() { return m_score; }

};

int runDeck52();