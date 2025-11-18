#include "roscoes.h"

int displayShop() {
	std::cout << "Here is our selection for today:\n";

	for (auto p : Potion::types) {
		std::cout << std::format("{}) {} costs {}\n", static_cast<int>(p), Potion::name[p], Potion::cost[p]);
	}

	return 0;

}

Player greetAndInitPlayer() {
	std::cout << "Welcome to Roscoes Potion Emporium!\n";

	Player gamer{ getTFromUser<std::string>("What's your name?: ") };
	
	std::cout << std::format("Hello, {}! You have {} gold.\n\n", gamer.name(), gamer.getWealth() );

	return gamer;
}

bool isValidInput(char input) {

	//std::cout << "Input: " << input << '\n';

	// Accept quit
	if (input == 'q')
		return true;

	// Accept digits within range
	if (std::isdigit(input)) {
		int value = input - '0';  // convert char digit to number 0–9
		return value >= 0 && value < Potion::max_potions;
	}

	return false;
}

int updatePlayer(Player gamer, char purchase) {

	//std::cout << std::format("Choice: {}", purchase);
	size_t choice{ static_cast<size_t>(purchase - '0')};

	int purchasePrice{ Potion::cost[choice] };
	std::cout << std::format("Purchase price: {}", purchasePrice);

	if (gamer.getWealth() < purchasePrice) 
		std::cout << "You cannot afford that.";
	else {
		gamer.addToInventory(choice);
		gamer.setWealth(gamer.getWealth() - purchasePrice);
		std::cout << std::format("You purchased a potion of {}. You have {} gold left.\n", Potion::name[choice], gamer.getWealth());
	}

	return 0;
}

int printExitStats(Player gamer) {
	std::cout << "Your inventory contains: \n";
	
	for (auto& a : Potion::types) {
		std::cout << std::format("{}x potion of {}", gamer.getInventory()[a], Potion::name[a]);
	}

	std::cout << std::format("You escaped with {} gold remaining.\n\n", gamer.getWealth());
	std::cout << "Thanks for shopping at Roscoe's potion emporium!";
	return 0;
}

int runRoscoes() {
	Player gamer{ greetAndInitPlayer() };
	bool quit{ false };

	while (gamer.getWealth() > 0 && !quit) {

		displayShop();

		char input{ getTFromUser<char>("Enter the number of the potion you'd like to buy, or 'q' to quit: ") };
		
		while (!isValidInput(input) ){
			std::cout << "That is an invalid input. Try again.\n";
			input = getTFromUser<char>("");
			if (input == 'q') quit = true;
		}
		
		if (quit) {
			printExitStats(gamer);
		}
		else {
			std::cout << gamer.getWealth();
			updatePlayer(gamer, input);
		}
	}
	
	return 0;
}