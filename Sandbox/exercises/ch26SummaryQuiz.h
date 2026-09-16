#pragma once
#include <iostream>

template <typename T>
class Pair1{
private:
  T m_v1;
  T m_v2;

public:
  Pair1(const T& v1, const T& v2)
  :m_v1{v1}
  ,m_v2{v2}
  {}

  T& first() { return m_v1; }
  T& second() { return m_v2; }
  const T& first() const{ return m_v1; }
  const T& second() const { return m_v2; }

};

template <typename T, typename U>
class Pair{
  T m_v1;
  U m_v2;

public:
  Pair(const T& v1, const U& v2)
  :m_v1{v1}
  ,m_v2{v2}
  {}

  T& first() { return m_v1; }
  U& second() { return m_v2; }
  const T& first() const { return m_v1; }
  const U& second() const { return m_v2; }
};

int ch26SummaryQuizMain();
