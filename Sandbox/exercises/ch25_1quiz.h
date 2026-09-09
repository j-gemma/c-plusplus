#include <iostream>
#include <string_view>
#include <string>
#include <array>
#include <iostream>


class BaseAnimal
{
protected:
    std::string m_name;
    std::string m_speak;
    // We're making this constructor protected because
    // we don't want people creating BaseAnimal objects directly,
    // but we still want derived classes to be able to use it.
    BaseAnimal(std::string_view name, std::string_view speak)
        : m_name{ name }
        , m_speak{ speak }
    {
    }

    // To prevent slicing (covered later)
    BaseAnimal(const BaseAnimal&) = delete;
    BaseAnimal& operator=(const BaseAnimal&) = delete;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

class Cat: public BaseAnimal
{
public:
    Cat(std::string_view name, std::string_view speak="Meow")
        : BaseAnimal{ name, speak }
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog: public BaseAnimal
{
public:
    Dog(std::string_view name, std::string_view speak="Woof")
        : BaseAnimal{ name, speak }
    {
    }

    std::string_view speak() const { return "Woof"; }
};

int ch25_1quizMain();

