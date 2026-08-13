#pragma once

#include "../common/common.h"
#include "../common/ClassRandom.h"
#include <format>
#include <iostream>
#include <array>

class Point{

private:
  int m_x{0};
  int m_y{0};

public:
  Point(int x, int y)
  :m_x(x)
  ,m_y(y)
  {}

  Point() = default;
};

class Tile{
  int m_value{};
  Point m_location{};
  
public:
  Tile(int value)
  :m_value(value)
  {}

  Tile() = default;

  int getNum() const { return m_value; }

  bool isEmpty() { return m_value == 0; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& t);

 };

const int ROWS{4};
const int COLS{4};

class Board{
private:
  int m_rows{ROWS};
  int m_cols{COLS};

  Tile m_tiles[ROWS][COLS];

public:

  int numRows() const { return m_rows; }
  int numCols() const { return m_cols; }

  Board(){
    for(int i = 0; i < m_rows; i++){
      for(int j = 0; j< m_cols; j++){
        m_tiles[i][j] = Tile{((m_rows*i) + (j + 1)) % (m_rows*m_cols)};
      }
    }

  }

  friend std::ostream& operator<<(std::ostream& out, const Board& b);


};



namespace UserInput{};

class Direction{

private:

  enum direction{
    up,
    down,
    left, 
    right,
  };

direction m_dir{up};

public:
  Direction(char c){
    switch(c){

      case 'w':
        m_dir = up;
        break;
      case 'a':
        m_dir =  left;
        break;
      case 's':
        m_dir = down;
        break;
      case 'd':
        m_dir = right;
        break;
    }
  }

  Direction randomDir(){
    return static_cast<direction>(Random::get(0, 3));


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

};

int play15Game();

