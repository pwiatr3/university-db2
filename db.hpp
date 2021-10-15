#pragma once
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream> 
#include "student.hpp"
#include <stdio.h>

class Db {
private:
    std::vector <Student> db_;
public:
    
    void addStudent(Student student);
    void printdb();
    Student searchBySurname(std::string surname);
    Student searchByPesel(size_t pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteRecord(size_t index);
    void readDbFromFile(const std::string& filename);
    void saveDbInFile(const std::string& filename);
    bool peselValidation(size_t pesel);
    std::vector <Student>& getFullList();
};