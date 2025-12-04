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
	m_nextIdx = 0;
}

Card Deck::dealCard() {
	assert(m_nextIdx != m_cards.size() && "Deck ran out of cards.\n");
	return m_cards[m_nextIdx++];
}

int runDealCards()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}

int initGame(Blackjack::Player& dealer, Blackjack::Player& player, Deck& deck) {
	

	Card card1{ deck.dealCard() };
	if (card1.value() == 11) dealer.numAces++;
	std::cout << std::format("The dealer is showing {} ({})\n", card1, card1.value());
	dealer.m_score = dealer.m_score + card1.value();

	Card card2{ deck.dealCard() };
	Card card3{ deck.dealCard() };
	if (card2.value() == 11) player.numAces++;
	if (card3.value() == 11) player.numAces++;
	std::cout << std::format("You are showing {} {} ({})\n", card2, card3, card2.value() + card3.value());
	player.m_score = player.m_score + card2.value() + card3.value();

	return 0;
}

int dealerTurn(Blackjack::Player& dealer, Deck& deck) {

	while (dealer.m_score < Settings::DEALERSTAND) {
		Card card{ deck.dealCard() };
		dealer.m_score += card.value();
		if (card.value() == 11) dealer.numAces++;
		dealer.m_score += card.value();
		while ((dealer.m_score > Settings::BUST) && (dealer.numAces > 0)) {
			dealer.m_score -= 10;
			dealer.numAces--;
		}

		std::cout << std::format("The dealer flips a {}. They now have {}\n", card, dealer.m_score);
		if (dealer.m_score > Settings::BUST) std::cout << "The dealer went bust!\n";
	}

	return 0;
}


int playerTurn(Blackjack::Player& player, Deck& deck) {
	
	while (player.m_score < Settings::BUST) {
		char choice{ getTFromUser<char>("(h) to hit, or (s) to stand: ") };

		while ((choice != 's') && (choice != 'h')) {
			choice = getTFromUser<char>("(h) to hit, or (s) to stand: ");
		}

		if (choice == 'h') {
			Card card{ deck.dealCard() };
			if (card.value() == 11) player.numAces++;
			player.m_score += card.value();
			while ((player.m_score > Settings::BUST) && (player.numAces > 0)) {
				player.m_score -= 10;
				player.numAces--;
			}
			std::cout << std::format("You were dealt {}. You now have {}: \n", card, player.m_score);
			if (player.m_score > Settings::BUST) std::cout << "You went bust!\n";
		}

		if (choice == 's') break;

	}
	
	return 0;
}

Blackjack::Condition playBlackjack() {

	Blackjack::Player dealer{};
	Blackjack::Player player{};

	Deck deck{};

	initGame(dealer, player, deck);
	playerTurn(player, deck);
	if(player.m_score <= Settings::BUST) dealerTurn(dealer, deck);

	if (player.m_score == dealer.m_score) return Blackjack::tie;

	bool win{  ((player.m_score > dealer.m_score) && (player.m_score <= Settings::BUST))
			|| ((dealer.m_score > Settings::BUST) && player.m_score <= Settings::BUST) ? true : false };

	if (win) return Blackjack::playerWin;
	else return Blackjack::dealerWin;
}

int runPlayBlackjack() {
	while (true) {
		switch (playBlackjack()) {
			
		case Blackjack::playerWin: {
			std::cout << "You win!\n\n";
			break;
		}
		case Blackjack::dealerWin: {
			std::cout << "You lose!\n\n";
			break;
		}
		case Blackjack::tie:
		default:
		{
			std::cout << "You tied!\n\n";
			break;
		}
		
		}
		
	}return 0;
}

