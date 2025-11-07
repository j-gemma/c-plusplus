#include "ch17ArraysPt1.h"

int printAnimalInfo(int matchIndex) {

    
    if (matchIndex == -1) {
        std::cout << "That animal couldn't be found.\n";
        return matchIndex;
    }

    size_t cast{ static_cast<size_t>(matchIndex) };
  
    std::cout << std::format("A {} has {} legs and says {}.\n",
                            Animal::data[cast].name,
                            Animal::data[cast].legs,
                            Animal::data[cast].sound);
                            
    return matchIndex;
}

int printRestOfAnimals(int matchIndex) {

    std::cout << "\nHere is the info for the rest of the animals: \n";
    for (int i{}; i < Animal::max_animals; i++) {
        if (i != matchIndex) printAnimalInfo(i);
    }

    return 0;
}

int matchAnimal(std::string& animal) {

    
    for (size_t i{}; i < Animal::max_animals; i++) {
        if (animal == Animal::data[i].name)
            return static_cast<int>(i);
    }
    return -1;
}

int runArrayOfAnimals() {

    std::string uAnimal{ getTFromUser<std::string>("Enter an animal: ") };
    printRestOfAnimals(printAnimalInfo(matchAnimal(uAnimal)));
  
    return 0;
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
