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