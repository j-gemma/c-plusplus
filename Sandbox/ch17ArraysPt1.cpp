#include "ch17ArraysPt1.h"

std::array<double, 366> dailyHighTemps{};

const std::array<Animal::Data, Animal::max_animals> makeAnimalData() {

    std::array<Animal::Data, Animal::max_animals> animalData{};

    for (std::size_t i{}; i < Animal::max_animals; i++) {
        animalData[i] = { Animal::legNums[i], Animal::animalNames[i], Animal::animalSounds[i] };
        //std::cout << animalData[i].name << '\n';
    }
    
    return animalData;
}


int runArrayOfAnimals() {

    std::array<Animal::Data, Animal::max_animals> animalData{ makeAnimalData() };
    std::string_view uAnimal{ getTFromUser<std::string>("Enter an animal: ") };

    int matchIndex { matchAnimal(uAnimal) };

    if (matchIndex != -1) {
        printAnimalInfo(matchIndex);
        printRestOfAnimals(matchIndex);
    }

    return 0;
}

int matchAnimal(std::string_view& animal) {
    for (size_t i{}; i < Animal::max_animals; i++) {
        if (animal == Animal::animalNames[i])
            return static_cast<int>(i);
    }
    return -1;
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


