#include "employee.hpp"

Employee::Employee() 
    :   Person(),
        salary_(0.0) {}

Employee::Employee(std::string name, std::string surname, std::string address, std::string pesel, size_t salary, std::string gender) 
    :   Person(name, surname, address, pesel, gender, "Employee"),
        salary_(salary) {}

void Employee::setPesel(std::string pesel) {
    Person::setPesel(pesel);
}

void Employee::setSalary(size_t salary) {
    salary_ = salary;
}


std::string Employee::getPesel() const {
    return Person::getPesel();
}

size_t Employee::getSalary() const {
    return salary_;
}

size_t Employee::getIndex() const {
    return 0;
}

void Employee::print() {
    Person::print();
    std::cout << "Salary: " << salary_ << "$\n";
}

bool Employee::operator==(const  Employee &rhs) const {
    

    // if(this->getFullName() != rhs.getFullName()) {
    //     return false;
    // }
    // if(this->getAddress() != rhs.getAddress()) {
    //     return false;
    // }
    // if(this->getPesel() != rhs.getPesel()) {
    //     return false;
    // }
    // if(this->getGender() != rhs.getGender()) {
    //     return false;
    // }

    // calling base class operator==
    if((Person::operator==(rhs)) == false) {
        return false;
    }
    if(this->getSalary() != rhs.getSalary()) {
        return false;
    }
    return true;
}
void Employee::modifySalary(size_t newSalary) {
    salary_ = newSalary;
}
