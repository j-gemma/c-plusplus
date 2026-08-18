#pragma once

#include "../common/common.h"
#include "../common/ClassRandom.h"
#include <format>
#include <iostream>
#include <array>

const int ROWS{4};
const int COLS{4};

class Direction{

public:

 enum direction{
    up,
    down,
    left, 
    right,
  };

  Direction(direction d)
  :m_dir{d}
  {}

  Direction::direction getDirection(){
      return m_dir;
  }

  Direction(int i){
    m_dir = static_cast<direction>(i%4);
  }

  friend std::ostream& operator<<(std::ostream& out, const Direction d){

    switch(d.m_dir){

    case up:
      out << "up";
      break;
    case down:
      out << "down";
      break;
    case left: 
      out << "left";
      break;
    case right:
      out << "right";
    }

    return out;
  }

  Direction operator-() const{
    switch(m_dir){
      case up:
        return down;
      case down:
        return up;
      case left:
        return right;
      case right:
        return left;
    }
  }

private:
  direction m_dir{};

};

class Point{

public:

  int m_x{0};
  int m_y{0};

  Point(int x, int y)
  :m_x(x)
  ,m_y(y)
  {}

  Point() = default;

  Point getAdjacentPoint(Direction d);

  friend bool operator==(Point p1, Point p2);
  
  friend bool operator!=(Point p1, Point p2);

};

class Tile{
  int m_value{};

public:
  Tile(int value)
  :m_value(value)
  {}

  Tile() = default;

  int getNum() const { return m_value; }

  void setNum(int i) { m_value = i; } 

  bool isEmpty() { return m_value == 0; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& t);


 };

class Board{
private:
  int m_rows{ROWS};
  int m_cols{COLS};

  Tile m_tiles[ROWS][COLS];

  Point m_emptyTile{};

public:

  int numRows() const { return m_rows; }
  int numCols() const { return m_cols; }

  Board(){
    for(int i{}; i < m_rows; i++){
      for(int j{}; j < m_cols; j++){
        m_tiles[i][j] = Tile{((m_rows*i) + (j + 1)) % (m_rows*m_cols)};
      }
    }
  findAndSetEmptyTile();
  }

  void setEmptyTile(Point p);

  Point getEmptyTile(){ return m_emptyTile; }

  void findAndSetEmptyTile();

  bool isValidMove(Point p, Direction d);

  void swapTile(Point p, Direction d);

  void moveTile(Direction d);

  friend std::ostream& operator<<(std::ostream& out, const Board& b);

  bool gameWon();

};

int play15Game();

Direction randomDir();

