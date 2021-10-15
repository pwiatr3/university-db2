#include "student.hpp"

Student::Student() 
    :   Person("", "", "", "unkwon"),
        index_(0),
        pesel_(0) {
}

Student::Student(std::string name, std::string surname, std::string address, size_t index, size_t pesel, std::string gender) 
    :   Person(name, surname, address, gender),
        index_(index),
        pesel_(pesel) {
}


void Student::setIndex(size_t index) {
    index_ = index;
}
void Student::setPesel(size_t pesel) {
    pesel_ = pesel;
}

size_t Student::getIndex() const {
    return index_;
}
size_t Student::getPesel() const {
    return pesel_;
}

void Student::print() {
    std::cout << "================"<< '\n';
    std::cout << index_ << '\n';
    std::cout << pesel_ << '\n';

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
