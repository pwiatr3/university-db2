#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <memory>
#include "person.hpp"
#include "student.hpp"
#include "employee.hpp"

constexpr char boyNamesFile[] = "../boyNames.txt";
constexpr char girlNamesFile[] = "../girlNames.txt";
constexpr char surnamesFile[] = "../surnames.txt";
constexpr char addressesFile[] = "../addresses.txt";

// constexpr char boyNamesFile[] = "./boyNames.txt";
// constexpr char girlNamesFile[] = "./girlNames.txt";
// constexpr char surnamesFile[] = "./surnames.txt";
// constexpr char addressesFile[] = "./addresses.txt";

constexpr size_t yearOfBirthMin = 1800;
constexpr size_t yearOfBirthMax = 2021;
constexpr std::array<size_t, 12> monthDays {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
constexpr size_t maxSalary = 1000000;
constexpr size_t maxIndex = 9999;


class Generator {
    private:
    const std::array<std::string, 2> genderArray {"Male", "Female"};
    std::vector<std::string> loadFiletoVector(std::string file);
    std::string generateName(std::string gender);
    std::string generateSurname();
    std::string generateAddress();
    std::string generatePesel(std::string gender);
    std::string generateGender();
    size_t generateSalary();  
    size_t generateIndex();
    size_t calculateControlDigit(std::string number); // for calculation of 11-th digit in PESEL number

    public:
    std::shared_ptr<Student> generateStudent();
    std::shared_ptr<Employee> generateEmployee();
    
};
