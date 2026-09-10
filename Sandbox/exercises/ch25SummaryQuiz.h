#include <vector>
#include <iostream>
#include <format>
#include "../common/Point2d.h"

class Shape{

  virtual std::ostream& print(std::ostream& o) = 0;

  virtual std::ostream& operator<<(Shape& s) = 0;

  virtual ~Shape() = 0;

};

class Triangle : public Shape{
protected:
  Point2d m_p1{};
  Point2d m_p2{};
  Point2d m_p3{};

public:

  std::ostream& print(std::ostream& o) override{
    o << std::format("Triangle

  }

  virtual ~Triangle();
};

class Circle : public Shape{
protected: 
  Point2d m_center{};
  int m_radius{};


  virtual ~Circle();
}
