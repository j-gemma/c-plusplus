#include "ch17ArraysPt1.h"

std::array<double, 366> dailyHighTemps{};

const std::array<Animal::Data, Animal::max_animals>& makeAnimalData() {

    std::array<Animal::Data, Animal::max_animals> animalData{};


    const std::array<Animal::Data, Animal::max_animals> temp{ animalData };
    return temp;
}

int runArrayIntro() {
	constexpr std::array hello { 'h', 'e', 'l', 'l', 'o' };

	std::cout << std::format("The length is {}\n", hello.size());
	std::cout << hello[1] << hello.at(1) << std::get<1>(hello) << '\n';
	return 0;
}

int runPrintArray()
{
    constexpr std::array arr1{ 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2{ 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}

int runPrintItems() {

    constexpr std::array<Item, 4> items{ {
        {"sword", 5},
        {"dagger", 3},
        {"club", 2},
        {"spear", 7}
    } };

    for (const auto& a : items) {
        std::cout << std::format("A {} costs {} gold.\n", a.name, a.gold);
    }

    return 0;
}


