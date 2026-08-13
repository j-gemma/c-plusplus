#include "Game15Puzzle.h"

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
  constexpr int g_consoleLines{ 25 };

  int i{0};
  while(i < g_consoleLines){
    std::cout << '\n';
    ++i;
 }
// Your code goes here

  Board board{};
  std::cout << board;

  while(true){
    char in{getTFromUser<char>("")};

    switch(in){
      case 'w':
      case 'a':
      case 's':
      case 'd':
        std::cout << "Valid command: " << Direction(in) << '\n';
        break;

      case 'q':
        std::cout << "\n\nBye!\n\n";
        return 0;

    }


  }

  return 0;
}
