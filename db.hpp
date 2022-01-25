#pragma once
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream> 
#include "student.hpp"
#include "person.hpp"
#include "nullPerson.hpp"
#include <stdio.h>

class Db {
private:
    std::vector <std::shared_ptr<Person>> db_;
public:
    void addPerson(std::shared_ptr<Person> person_ptr);
    void printdb();
    std::shared_ptr<Person> searchByPesel(std::string pesel);
    void sortBySalary();
    void modifySalary(std::string pesel, size_t newSalary);
    bool peselValidation(std::string pesel);
    std::vector <std::shared_ptr<Person>> getFullList();
};