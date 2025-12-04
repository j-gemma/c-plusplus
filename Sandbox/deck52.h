#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <array>
#include <vector>

#include "input.h"
#include "ClassRandom.h"

namespace Settings {
	const int BUST{ 21 };
	const int DEALERSTAND{ 17 };

}

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

	int value() const {
		constexpr std::array rankValues{ 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
		return rankValues[rank];
	}

};

namespace Blackjack {
	struct Player {
		int m_score{};
		int numAces{};

	};

	enum Condition {
		playerWin, 
		dealerWin,
		tie,
		max_conditions
	};

}

template <>
struct std::formatter<Card> : std::formatter<std::string> {
	static constexpr std::array<char, Card::max_rank> ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	static constexpr std::array<char, Card::max_suit> suits{ 'C', 'H', 'D', 'S' };

	auto format(const Card& c, auto& ctx) const {
		std::string s = std::format("{}{}", ranks[c.rank], suits[c.suit]);
		return std::formatter<std::string>::format(s, ctx);
	}
};


class Deck {

	
	std::vector<Card> m_cards{ std::vector<Card>(52) };
	size_t m_nextIdx{ 0 };

public:
	Deck() {
		deckOfCards();
		shuffle();
	}

	Card dealCard(); 

	void shuffle();

private:
	void deckOfCards() {
		size_t index{ 0 };
		for (size_t j{ 0 }; j < Card::max_suit; ++j) {
			for (size_t k{ 0 }; k < Card::max_rank; ++k) {
				m_cards[index] = { Card::allRanks[k], Card::allSuits[j] };
				++index;
			}
		}
	}

	friend class Random;
};

int runDealCards();

int runDeck52();

Blackjack::Condition playBlackjack();

int runPlayBlackjack();