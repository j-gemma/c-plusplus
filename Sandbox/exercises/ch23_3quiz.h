#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(std::string_view name)
      : m_name{ name }
  {
  }

  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  std::vector<std::reference_wrapper<const Teacher>> m_teachers{};
public:
  Department()
      : m_teachers{ }
  {
  }

  void add(const Teacher& t){
    m_teachers.emplace_back(t);
  }

  friend std::ostream& operator<<(std::ostream& out, Department& d){
    for(const Teacher& t : d.m_teachers){
      out << t.getName() << '\n';
    }
    return out;
  }
};

int ch23_3quizMain();
