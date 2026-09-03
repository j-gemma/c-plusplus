#include <iostream>
#include <string>
#include "../common/input.h"
#include <format>
#include "../common/ClassRandom.h" 

class Creature{
protected:

  std::string m_name{};
  char m_symbol{};
  int m_health{};
  int m_damagePerAttack{};
  int m_goldCarried{};

public:

  const std::string& getName() const { return m_name; }

  char getSymbol() const { return m_symbol; }

  int getHealth() const { return m_health; }

  int getDamage() const { return m_damagePerAttack; }

  int getGold() const { return m_goldCarried; }

  void reduceHealth(int i){ m_health -= i; }

  bool isDead() const { return (m_health <= 0); }

  void addGold(int i){ m_goldCarried += i; }

  Creature(std::string name, char symbol, int health, int damage, int gold)
  :m_name{name}
  ,m_symbol{symbol}
  ,m_health{health}
  ,m_damagePerAttack{damage}
  ,m_goldCarried{gold}
  {}

};

class Monster : public Creature{
public:
  enum Type{
    dragon,
    orc,
    slime,
    max_types
  };

private:
  static inline Creature monsterData[] {{"dragon", 'D', 20, 4, 100}, {"orc", 'o', 4, 2, 25}, {"slime", 's', 1, 1, 10} };

public:
  Monster(Monster::Type type)
  :Creature{monsterData[type]}{}

  static Monster getRandomMonster(){
    return {static_cast<Monster::Type>(Random::get(0, max_types -1))};
  }

};

class Player : public Creature{
private:
  int m_level{1};

public:

  Player(const std::string& name)
  :Creature{name, '@', 10, 1, 0}
  {}

  void levelUp(){ ++m_level; ++m_damagePerAttack; }

  int getLevel() const { return m_level; }

  bool hasWon() const { return(m_level >= 20); }


};

Player initPlayer();

void attackMonster(Player& p, Monster& m);

void attackPlayer(Player& p, Monster& m);

//void fightMonster(Player& p, Monster& m);

void fightMonster(Player& p);

int fightMonstersMain();
