#pragma once
#include <iostream>
#include <string>
#include "person.hpp"

class Student : Person {
private:
    size_t index_;
    size_t pesel_;

public:
    Student();
    Student(std::string name, std::string surname, std::string address, size_t index, size_t pesel, std::string gender);
    
    // setters
    void setIndex(size_t index);
    void setPesel(size_t pesel);
    
    // getters
    size_t getIndex() const;
    size_t getPesel() const;

    // other
    void print();
    bool operator==(const Student &rhs) const;

};
