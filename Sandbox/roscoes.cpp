#include "roscoes.h"

int shop() {
	std::cout << "Here is our selection for today:\n";

	for (auto p : Potion::types) {
		std::cout << std::format("{}) {} costs {}\n", static_cast<int>(p), Potion::name[p], Potion::cost[p]);
	}

	return 0;

}

int greet() {
	std::cout << "Welcome to Roscoes Potion Emporium!\n";
	playerName = getTFromUser<std::string>("What's your name?: ");
	wealth = Random::get(80, 120);
	std::cout << std::format("Hello, {}! You have {} gold.\n\n", playerName, wealth);

	return 0;
}

int runRoscoes() {
	greet();
	shop();

	return 0;
}