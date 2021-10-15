#include "student.hpp"
//#include "db.hpp"

Student::Student() 
    :   name_(""),
        surname_(""),
        address_(""),
        index_(12345),
        pesel_(0),
        gender_("unknown") {
}

Student::Student(std::string name, std::string surname, std::string address, size_t index, size_t pesel, std::string gender)
    :   name_(name),
        surname_(surname),
        address_(address),
        index_(index),
        pesel_(pesel), 
        gender_(gender) {
}

void Student::setName(const std::string& name) {
    name_ = name;
}
void Student::setSurname(const std::string& surname) {
    surname_ = surname;
}
void Student::setAddress(const std::string& address) {
    address_ = address;
}
void Student::setIndex(size_t index) {
    index_ = index;
}
void Student::setPesel(size_t pesel) {
    pesel_ = pesel;
}
void Student::setGender(std::string gender) {
    gender_ = gender;
}

std::string Student::getName() const {
    return name_;
}
std::string Student::getSurname() const {
    return surname_;
}
std::string Student::getFullName() const {
    return name_ + ' ' + surname_;
}
std::string Student::getAddress() const {
    return address_;
}
size_t Student::getIndex() const {
    return index_;
}
size_t Student::getPesel() const {
    return pesel_;
}
std::string Student::getGender() const {
    return gender_;
}
void Student::print() {
    std::cout << "================"<< '\n';
    std::cout << name_ << '\n';
    std::cout << surname_ << '\n';;
    std::cout << address_ << '\n';;
    std::cout << index_ << '\n';;
    std::cout << pesel_ << '\n';;
    std::cout << gender_ << '\n';;
}

bool Student::operator==(const  Student &rhs) const {
    if(this->getFullName() != rhs.getFullName()) {
        return false;
    }
    if(this->getAddress() != rhs.getAddress()) {
        return false;
    }
    if(this->getIndex() != rhs.getIndex()) {
        return false;
    }
    if(this->getPesel() != rhs.getPesel()) {
        return false;
    }
    if(this->getIndex() != rhs.getIndex()) {
        return false;
    }
    if(this->getGender() != rhs.getGender()) {
        return false;
    }
    return true;
}
