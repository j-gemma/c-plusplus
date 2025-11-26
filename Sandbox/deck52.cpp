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

bool playBlackjack() {

	bool win{ false };

	Player dealer{};
	Player p1{};

	Card drawn{
		Card::allRanks[Random::get(0, Card::max_rank - 1)],
		Card::allSuits[Random::get(0, Card::max_suit - 1)]
	};



	return win;
}
