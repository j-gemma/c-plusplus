#include <ostream>
#include <vector>
#include <iostream>
#include <format>
#include <utility>

#include "../common/Point2d.h"

class Shape{
public:
  virtual std::ostream& print(std::ostream& o) const = 0;

  friend std::ostream& operator<<(std::ostream& o, Shape& s){
    return s.print(o);
  }

  virtual ~Shape() = default;

};

class Triangle : public Shape{
private:
  Point2d m_p1{};
  Point2d m_p2{};
  Point2d m_p3{};

public:

  Triangle(const Point2d& p1, const Point2d& p2, const Point2d& p3)
  :m_p1{p1}
  ,m_p2{p2}
  ,m_p3{p3}
  {}

  std::ostream& print(std::ostream& o) const override{
    return o << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
  }

  friend std::ostream& operator<<(std::ostream& o, Triangle& t){
    return t.print(o);
  }
};

class Circle : public Shape{
private: 
  Point2d m_center{};
  int m_radius{};

public:

  Circle(Point2d center, int radius)
  :m_center{center}
  ,m_radius{radius}
  {}

  std::ostream& print(std::ostream& o) const override{
    return o << "Circle(" << m_center << ", radius " << m_radius << ')';
  }

  friend std::ostream& operator<<(std::ostream& o, Circle c){
    return c.print(o);
  } 

  virtual ~Circle() = default;

  int getRadius() const { return m_radius; }
};

int ch25SummaryQuizMain();

int ch25SummaryQuizMain2();

int ch25Question2b();
