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
	std::shuffle(m_cards.begin(), m_cards.end(), Random::getMT());
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

	Blackjack::Player dealer{};
	Blackjack::Player player{};

	Deck deck{};

	dealer.setScore(dealer.getScore() + deck.dealCard().value());
	player.setScore(player.getScore() + deck.dealCard().value() + deck.dealCard().value());

	std::cout << std::format("The dealer is showing: {}\n", dealer.getScore());
	std::cout << std::format("You have score: {}\n", player.getScore());

	return (player.getScore() >= dealer.getScore());
}

int runPlayBlackjack() {

	while (true) {
		if (playBlackjack()) std::cout << "You win!\n\n";
		else {
			std::cout << "You lose";
			break;
		}
	}
	return 0;
}
