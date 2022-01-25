#pragma once
#include <iostream>
#include <string>
#include "person.hpp"

class Student : public Person {
private:
    size_t index_;
    
public:
    Student();
    Student(std::string name, std::string surname, std::string address, size_t index, std::string pesel, std::string gender);
    
    // setters
    void setIndex(size_t index);
    void setPesel(std::string pesel);
    
    // getters
    size_t getIndex() const override;
    std::string getPesel() const;
    size_t getSalary() const override;

    // other
    void print() override;
    bool operator==(const Student &rhs) const;
    void modifySalary(size_t newSalary) override;
};
