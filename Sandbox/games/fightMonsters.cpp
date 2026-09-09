#include "fightMonsters.h"
#include <format>
#include <utility>

Player initPlayer(){

  std::string name {getTFromUser<std::string>("Enter your name: ") };
  Player player{name};

  std::cout << std::format("Welcome, {}.\n", player.getName());
  std::cout << std::format("You have {} health and are carrying {} gold.\n", player.getHealth(), player.getGold());

  return player;
}

EffectDeducer getPotionEffect(const Potion &p){
  if(p.getType() == "strength") return &Player::increaseStrength;
  else return &Player::increaseHealth;

}

void potionChance(Player& player){

  if(player.getLevel() <= 20) return;

  if(Random::get(0, 9) < 3){
    Potion potion{ Potion::getRandomPotion() };
    char drinkPotion = getTFromUser<char>("You found a mythical potion! Do you want to drink it? [y/n]: ");

    while((drinkPotion != 'y') && (drinkPotion != 'Y') && (drinkPotion != 'n') && (drinkPotion != 'N')){
     drinkPotion = getTFromUser<char>("You found a mythical potion! Do you want to drink it? [y/n]: ");
    }

    if(drinkPotion == 'n' || drinkPotion == 'N') return;
    else{
      EffectDeducer fcn{ getPotionEffect(potion) };
      const std::string& potionType{potion.getType()};
      (player.*fcn)(potion.getValue());
      std::cout << std::format("You drank a {} potion of {}\n", potion.getSize(), potionType);
      if (potionType != "strength"){
        std::cout << std::format("Health changed by {}.\n", potion.getValue(), player.getHealth());
      }
      else{
        std::cout << std::format("Strength increased by {}. Your strength is {}.\n", potion.getValue(), player.getDamage());
      }

    }
  }
  else return;

}

void attackMonster(Player& p, Monster& m){
  if(p.isDead()) return;

  int damage{p.getDamage()};
  m.reduceHealth(damage);
  std::cout << std::format("You hit the {} for {} damage.\n", m.getName(), damage);

  if(m.isDead()){
    p.levelUp();
    std::cout << std::format("You are now level {}\n", p.getLevel());
    int gold{m.getGold()};
    p.addGold(gold);
    std::cout << std::format("You found {} gold.\n", gold);
    potionChance(p);
  }
}

void attackPlayer(Player& p, Monster& m){

  if(m.isDead()) return;

  int damage{m.getDamage()};
  p.reduceHealth(damage);
  std::cout << std::format("The {} hit you for {} damage.\n", m.getName(), damage);
}

//void fightMonster(Player& p, Monster& m){
//
//  char c {getTFromUser<char>("(R)un or (F)ight:")  };
//
//  while(c != 'R' && c != 'F' && c != 'r' && c!= 'f'){
//    c = getTFromUser<char>("(R)un or (F)ight:");
//  }
//
//  if(c == 'r' || c == 'R'){ 
//    if(Random::get(0, 1) == 1){
//      std::cout << "You failed to flee.\n";
//      attackPlayer(p, m);
//      if(p.getHealth() > 0){ 
//        std::cout << std::format("You have {} health.\n", p.getHealth());
//        fightMonster(p, m);
//      }
//    }
//    else std::cout << "You successfully fled.\n";
//  }
//  else{
//    attackMonster(p, m);
//    if(m.getHealth() > 0){
//      attackPlayer(p, m);
//      std::cout << std::format("You have {} health\n", p.getHealth());
//      if(p.getHealth() >= 0) fightMonster(p, m);
//    }
//  }
//}

void fightMonster(Player& p){
  Monster m{ Monster::getRandomMonster() };
  std::cout << std::format("You have encountered a {} ({}).\n", m.getName(), m.getSymbol());

  while(!m.isDead() && !p.isDead()){

    char c {getTFromUser<char>("(R)un or (F)ight:")  };

     while(c != 'R' && c != 'F' && c != 'r' && c!= 'f'){
       c = getTFromUser<char>("(R)un or (F)ight:");
     }

    if(c == 'r' || c == 'R'){ 
        if(Random::get(0, 1) == 1){
          std::cout << "You failed to flee.\n";
          attackPlayer(p, m);
          std::cout << std::format("You have {} health.\n", p.getHealth());
          continue;
        }
        else std::cout << "You successfully fled.\n";
        return;
      }
    else{
      attackMonster(p, m);
      attackPlayer(p, m);
      std::cout << std::format("You have {} health\n", p.getHealth());
    }
  }
}

int fightMonstersMain(){

  Player player{initPlayer()};

  while(!player.isDead() && !player.hasWon()){
    fightMonster(player);
  }

  if(player.isDead()) std::cout << std::format("You died at level {} and with {} gold\nToo bad you can't take it with you!\n", player.getLevel(), player.getGold());

  else std::cout << std::format("You won the game with {} gold!\n", player.getGold());

  return 0;
}


