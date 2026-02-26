#pragma once

#include <iostream>
#include <string>
#include <string_view>
//#include <iosfwd>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);

    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend bool operator<(const Car& a, const Car& b);
};



