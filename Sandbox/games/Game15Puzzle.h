#pragma once
#include "../common/common.h"
#include <format>
#include <iostream>

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

  Tile getTile(int i, int j) const {
    return m_tiles[i][j];
  }

  Board(){
    for(int i = 0; i < m_rows; i++){
      for(int j = 0; j< m_cols; j++){
        m_tiles[i][j] = Tile{((m_rows*i) + (j + 1)) % (m_rows*m_cols)};
      }
    }

  }

};

std::ostream& operator<<(std::ostream& out, const Board& b);

std::ostream& operator<<(std::ostream& out, const Tile& t);

namespace UserInput{};

class Direction{
  enum direction{
    up,
    down,
    left, 
    right,
  };
};

int play15Game();


