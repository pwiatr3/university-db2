#pragma once
#include <iostream>
#include <string>
#include "person.hpp"

class Employee : public Person {
private:
    //size_t pesel_;
    size_t salary_;

public:
    Employee();
    Employee(std::string name, std::string surname, std::string address, std::string pesel, size_t salary, std::string gender);
    
    // setters
    void setPesel(std::string pesel);
    void setSalary(size_t salary);
    
    // getters
    std::string getPesel() const;
    size_t getSalary() const override;
    size_t getIndex() const override;

    // other
    void print();
    bool operator==(const Employee &rhs) const;
    void modifySalary(size_t newSalary) override;

};
