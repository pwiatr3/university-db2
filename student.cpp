#include "student.hpp"

Student::Student() 
    :   Person(),
        index_(0) {}

Student::Student(std::string name, std::string surname, std::string address, size_t index, std::string pesel, std::string gender) 
    :   Person(name, surname, address, pesel, gender, "Student"),
        index_(index) {}


void Student::setIndex(size_t index) {
    index_ = index;
}
void Student::setPesel(std::string pesel) {
    Person::setPesel(pesel);
}

size_t Student::getIndex() const {
    return index_;
}

std::string Student::getPesel() const {
    return Person::getPesel();
}

size_t Student::getSalary() const {
    return 0;
}

void Student::print() {
    Person::print();
    std::cout << "Index: " << index_ << '\n';
}

bool Student::operator==(const  Student &rhs) const {
    // if(this->getFullName() != rhs.getFullName()) {
    //     return false;
    // }
    // if(this->getAddress() != rhs.getAddress()) {
    //     return false;
    // }
    // if(this->getIndex() != rhs.getIndex()) {
    //     return false;
    // }
    // if(this->getPesel() != rhs.getPesel()) {
    //     return false;
    // }
    //     if(this->getGender() != rhs.getGender()) {
    //     return false;
    // }
    // calling base class operator==
    if((Person::operator==(rhs)) == false) {
        return false;
    }
    if(this->getIndex() != rhs.getIndex()) {
        return false;
    }

    return true;
}

void Student::modifySalary(size_t newSalary) {
      
}
