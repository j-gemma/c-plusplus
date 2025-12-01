#include "deck52.h"

int runDeck52() {

	Card card{ Card::five, Card::heart };
	std::cout << card << '\n';

	for (auto suit : Card::allSuits) {
		for (auto rank : Card::allRanks) {
			std::cout << Card{ rank, suit } << ' ';
		}
	}
	std::cout << '\n';
	return 0;
}

void Deck::shuffle() {
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
	m_currIdx = 0;
}

Card Deck::dealCard() {
	assert(m_currIdx < m_cards.size() && "Current card index greater than deck size.\n");
	return m_cards[m_currIdx++];
}

int runDealCards()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}

bool playBlackjack() {

	bool win{ false };

	return win;
}
