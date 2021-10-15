#pragma once
#include <iostream>
#include <string>

class Person {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string gender_;
public:

    Person();
    Person(std::string name, std::string surname, std::string address, std::string gender);

    // setters
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setGender(std::string gender);
    void setAddress(const std::string& address);

    // getters
    std::string getName() const;
    std::string getSurname() const;
    std::string getFullName() const;
    std::string getAddress() const;
    std::string getGender() const;
    void print();
    bool operator==(const Person &rhs) const;

};