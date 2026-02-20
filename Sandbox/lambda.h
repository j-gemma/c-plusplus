#pragma once
#include <array>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "input.h"
#include "ClassRandom.h"

class GameState {

private:
    const int MIN_START{ 1 };
    const int MIN_COUNT{ 1 };
    const int m_start{};
    const int m_howMany{};
    const int m_mult{};
    std::vector<int> m_generated{};

    int getStartInt(int min);
    int getHowMany(int min);

public:

    GameState()
        : m_start{ GameState::getStartInt(MIN_START) }
        , m_howMany{ GameState::getHowMany(MIN_COUNT) }
        , m_mult{ Random::get(2, 4) }
    {
        for (int i{ m_start }; i < m_start + m_howMany; ++i)
        {
            m_generated.push_back(i * i * m_mult);
        }
        
    }

    bool playGame();
};

struct Student {
    const std::string_view m_name{};
    const int m_points{};
};

struct Season
{
  std::string_view m_name{};
  double m_averageTemperature{};
};

static std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

static std::array<Student, 8> studentsArr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

void runFindBestStudent();

int sortSeasons();

void runSortSeasons();

bool runSquareGame();