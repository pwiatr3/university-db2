#pragma once
#include <iostream>
#include <string>

class Person {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    std::string gender_;
    std::string position_;

public:

    Person();
    Person(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, std::string position);

    // setters
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setGender(std::string gender);
    void setPesel(const std::string pesel);
    void setAddress(const std::string& address);
    void setPosition(const std::string& position);

    // getters
    std::string getName() const;
    std::string getSurname() const;
    std::string getFullName() const;
    std::string getAddress() const;
    std::string getPesel() const;
    std::string getGender() const;
    std::string getPosition() const;
    virtual size_t getSalary() const = 0;
    virtual size_t getIndex() const = 0;

    //other
    virtual void modifySalary(size_t newSalary) = 0;
    virtual void print();
    bool operator==(const Person &rhs) const;

};