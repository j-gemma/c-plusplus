#include <iostream>

class Fruit{
private:
  std::string m_name{};
  std::string m_color{};

public:

  Fruit(std::string_view name, std::string_view color)
  :m_name{name}
  ,m_color{color}
  {}

  const std::string& getName() const { return m_name; }

  const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit{
private:
  double m_Fiber{};

public:
  Apple(std::string_view name, std::string_view color, double fiber = 0)
  :Fruit{name, color}
  ,m_Fiber{fiber}
  {}

  Apple(std::string_view color = "red")
  :Apple{"apple", color}
  {}

  double getFiber() const { return m_Fiber; }

};

class Banana : public Fruit{

public:
  Banana(std::string name = "banana", std::string color = "yellow")
  :Fruit{name, color}
  {}

};

class GrannySmith : public Apple{
private:

public:
  GrannySmith()
  :Apple{"granny smith apple", "green"}
  {}


};

std::ostream& operator<<(std::ostream& out, const Apple& apple);

std::ostream& operator<<(std::ostream& out, const Banana& banana);

int printFruits();

int printFruits2();

