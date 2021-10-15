#pragma once
#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    size_t index_;
    size_t pesel_;
    std::string gender_;
public:
    Student();
    Student(std::string name, std::string surname, std::string address, size_t index, size_t pesel, std::string gender);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setAddress(const std::string& address);
    void setIndex(size_t index);
    void setPesel(size_t pesel);
    void setGender(std::string gender);
    

    std::string getName() const;
    std::string getSurname() const;
    std::string getFullName() const;
    std::string getAddress() const;
    size_t getIndex() const;
    size_t getPesel() const;
    std::string getGender() const;
    void print();
    bool operator==(const Student &rhs) const;

};
