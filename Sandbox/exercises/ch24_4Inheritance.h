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
  Apple(std::string_view name, std::string_view color, double fiber)
  :Fruit{name, color}
  ,m_Fiber{fiber}
  {}

  double getFiber() const { return m_Fiber; }

  };

class Banana : public Fruit{

public:
  Banana(std::string name, std::string color)
  :Fruit{name, color}
  {}

};

std::ostream& operator<<(std::ostream& out, const Apple& apple);

std::ostream& operator<<(std::ostream& out, const Banana& banana);

int printFruits();
