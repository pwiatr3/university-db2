#include "person.hpp"

Person::Person() 
    :   name_(""),
        surname_(""),
        address_(""),
        gender_("unknown") {
}

Person::Person(std::string name, std::string surname, std::string address, std::string gender)
    :   name_(name),
        surname_(surname),
        address_(address),
        gender_(gender) {
}

void Person::setName(const std::string& name) {
    name_ = name;
}
void Person::setSurname(const std::string& surname) {
    surname_ = surname;
}
void Person::setAddress(const std::string& address) {
    address_ = address;
}

void Person::setGender(std::string gender) {
    gender_ = gender;
}

std::string Person::getName() const {
    return name_;
}
std::string Person::getSurname() const {
    return surname_;
}
std::string Person::getFullName() const {
    return name_ + ' ' + surname_;
}
std::string Person::getAddress() const {
    return address_;
}
std::string Person::getGender() const {
    return gender_;
}
void Person::print() {
    std::cout << "================"<< '\n';
    std::cout << name_ << '\n';
    std::cout << surname_ << '\n';;
    std::cout << address_ << '\n';;
    std::cout << gender_ << '\n';;
}

bool Person::operator==(const  Person &rhs) const {
    if(this->getFullName() != rhs.getFullName()) {
        return false;
    }
    if(this->getAddress() != rhs.getAddress()) {
        return false;
    }
    if(this->getGender() != rhs.getGender()) {
        return false;
    }
    return true;
}
