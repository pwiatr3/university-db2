#include "person.hpp"

Person::Person() 
    :   name_(""),
        surname_(""),
        address_(""),
        pesel_{"0000000000"},
        gender_("unknown"),
        position_("unkown") {
}
Person::Person(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, std::string position)
    :   name_(name),
        surname_(surname),
        address_(address),
        pesel_(pesel),
        gender_(gender),
        position_(position) {
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
void Person::setPesel(const std::string pesel) {
    pesel_ = pesel;
}
void Person::setGender(std::string gender) {
    gender_ = gender;
}
void Person::setPosition(const std::string& position) {
    position_ = position;
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
std::string Person::getPesel() const {
    return pesel_;
}
std::string Person::getGender() const {
    return gender_;
}
std::string Person::getPosition() const {
    return position_;
}

void Person::print() {
    std::cout << "================"<< '\n';
    std::cout << "Name: " << name_ << '\n';
    std::cout << "Surname: " << surname_ << '\n';
    std::cout << "Address: " << address_ << '\n';
    std::cout << "Pesel: " << pesel_ << '\n';
    std::cout << "Gender: " << gender_ << '\n';
}

bool Person::operator==(const  Person &rhs) const {
    if(this->getFullName() != rhs.getFullName()) {
        return false;
    }
    if(this->getAddress() != rhs.getAddress()) {
        return false;
    }
    if(this->getPesel() != rhs.getPesel()) {
        return false;
    }
    if(this->getGender() != rhs.getGender()) {
        return false;
    }
    return true;
}
