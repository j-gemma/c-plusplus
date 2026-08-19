#include "Game15Puzzle.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Tile& t){
  int num {t.getNum()};

  if(num == 0){
    out << "    ";
    return out;
  }

  if(num >= 10){
    out << ' ' << num << ' ';
    return out;
  }

  out << ' ' << ' ' << num << ' ';
  return out;
}

std::ostream& operator<<(std::ostream& out, const Board& b){

  int rows{b.numRows()};
  int cols{b.numCols()};

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      out << b.m_tiles[i][j];
    }
    out << '\n';
  }

  return out;
}

Direction randomDir(){
    return Direction(Random::get(0, 3));
  }

Point Point::getAdjacentPoint(Direction d){
  switch(d.getDirection()){
    case Direction::up:     return Point{m_x,     m_y - 1};
    case Direction::down:   return Point{m_x,     m_y + 1};
    case Direction::left:   return Point{m_x - 1, m_y};
    case Direction::right:  return Point{m_x + 1, m_y};
    default:                break;
    }

    assert(0 && "Unsupported direction passed!");
    return *this;
}

bool operator==(Point p1, Point p2){
  return((p1.m_x == p2.m_x) && (p1.m_y == p2.m_y));
}

bool operator!=(Point p1, Point p2){
  return !(p1==p2);
}

namespace UserInput{
  bool isValidCommand(char c){
    return c == 'w'
        || c == 'a'
        || c == 's'
        || c == 'd'
        || c == 'q';
  }

  Direction charToDirection(char c){

    switch(c){
      case 'w': return Direction{Direction::up};
      case 'a': return Direction{Direction::left};
      case 's': return Direction{Direction::down};
      case 'd': return Direction{Direction::right};
    }

  assert(0 && "Unsupported direction was passed!");
  return Direction{randomDir()};
  }
}

void Board::setEmptyTile(Point p){
  m_emptyTile = p;
  return;
}

void Board::findAndSetEmptyTile(){
  for(size_t i{}; i < m_rows; ++i){
    for(size_t j{}; j < m_cols; ++j){
//      std::cout << "Cell value at " << i << ", " << j << " is " << m_tiles[i][j].getNum();
      if (m_tiles[i][j].getNum() == 0) setEmptyTile(Point(j, i));
    }
  }
  return;
}

bool Board::isValidMove(Point p, Direction d){
  Point moved{p.getAdjacentPoint(-d)};
  if((moved.m_x >= 0) && (moved.m_x < COLS) && (moved.m_y >= 0) && (moved.m_y < ROWS)) return true;
  else return false;
}

void Board::swapTile(Point p, Direction d){
  Point toBeEmpty{p.getAdjacentPoint(-d)};
  m_tiles[m_emptyTile.m_y][m_emptyTile.m_x].setNum(m_tiles[toBeEmpty.m_y][toBeEmpty.m_x].getNum());
  m_tiles[toBeEmpty.m_y][toBeEmpty.m_x].setNum(0);
  setEmptyTile(toBeEmpty);
}

void Board::moveTile(Direction dir){
  Point empty{getEmptyTile()};
  if (isValidMove(empty, dir)){
    swapTile(empty, dir);
     }
}

bool Board::gameWon(){
  if((m_emptyTile.m_x == COLS - 1) && (m_emptyTile.m_y == ROWS - 1)){
    for(int i{}; i < ROWS; ++i){
      for(int j{}; j < COLS; ++j){
        int expected{((m_rows*i) + (j + 1)) % (m_rows*m_cols)};

        if(m_tiles[i][j].getNum() != expected){
          std::cout << "Expected: " << expected << ", Tile: " << m_tiles[i][j].getNum();
          return false;
        }
      }
    }
    return true;
  }
  else return false;
}

int play15Game(){
//    Tile tile1{ 10 };
//    Tile tile2{ 8 };
//    Tile tile3{ 0 }; // the missing tile
//    Tile tile4{ 1 };
//
//    std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
//    std::cout << tile1 << tile2 << tile3 << tile4 << '\n';
//
//    std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
//    std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';
//
// Increase amount of new lines if your board isn't
// at the very bottom of the console
  constexpr int g_consoleLines{ 21 };
  constexpr int g_randomMoves{100};
// Your code goes here

//  std::cout << std::boolalpha;
//  std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up)    == Point{ 1, 0 }) << '\n';
//  std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down)  == Point{ 1, 2 }) << '\n';
//  std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left)  == Point{ 0, 1 }) << '\n';
//  std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 2, 1 }) << '\n';
//  std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
//  std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
//  std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

  Board board{};

  for(size_t i{}; i < g_randomMoves; i++){
    board.moveTile(randomDir());
  }
  std::cout << board;

//  for (int i{}; i < 4; i++){
//    std::cout << "Generating random direction... " << randomDir() << '\n';
//  }

//  Point empty{board.getEmptyTile()};
//  std::cout << "Empty tile location: " << empty.m_x << ", " << empty.m_y;

  while(true){

    int i{0};
    while(i < g_consoleLines){
      std::cout << '\n';
      ++i;
    }


    char in{getTFromUser<char>("")};

    switch(in){
      case 'w':
      case 'a':
      case 's':
      case 'd':
        std::cout << "Valid command: " << UserInput::charToDirection(in) << '\n';
        break;

      case 'q':
        std::cout << "\n\nBye!\n\n";
        return 0;

    }

    board.moveTile(UserInput::charToDirection(in));
    std::cout << board;

    if(board.gameWon()){
      std::cout << "\n\nYou won!\n\n";
      break;
    }
  }

  return 0;
}

