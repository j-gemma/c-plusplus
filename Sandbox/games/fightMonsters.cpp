#include "fightMonsters.h"
#include <utility>

int fightMonsters()
{

  Creature o{ "orc", 'o', 4, 2, 10 };
  o.addGold(5);
  o.reduceHealth(1);
  std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

  return 0;
}

int fightMonsters2(){

  std::string name {getTFromUser<std::string>("Enter your name: ") };
  Player player{name};

  std::cout << std::format("Welcome, {}.\n", player.getName());
  std::cout << std::format("You have {} health and are carrying {} gold.\n", player.getHealth(), player.getGold());

  return 0;
}
