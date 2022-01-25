#include <sstream>
#include "menu.hpp"
#include "generator.hpp"

// //===============================================================================================================================================//
Menu::Menu(Db& dbRef) : dbRef_{dbRef} {}
//===============================================================================================================================================//
void Menu::available_commands() {
    std::cout << "Available commands to use in database:\n";
    int i = 0;
    for (auto &entry : menuMapCommands_)
    {
        std::cout << i <<". " << entry.first << "\n";
        i++;
    };
    //std::cout << "\nType: [command] help to get help of specify command. Example: showdb help\n";
}
//===============================================================================================================================================//
void Menu::add_command() {
    std::string str;
    std::string name {};
    std::string surname {};
    std::string address {};
    size_t index = 0;
    std::string pesel = "";
    std::string gender {};
    size_t salary = 0;;
    std::cout << "If you want to add Employee press E else you will add student: ";
    //std::cin >> str;
    std::getline (std::cin, str);
    std::cout << "Please enter name: ";
    std::getline (std::cin, name);
    std::cout << "\nPlease enter surname: ";
    std::getline (std::cin, surname);
    std::cout << "\nPlease enter address: ";
    std::getline (std::cin, address);

    std::cout << "\nPlease enter pesel number: ";
    std::cin >> pesel;
    while(dbRef_.peselValidation(pesel) == false) {
        std::cout << "Invalid pesel number. Please enter corrent number\n";
        std::cin >> pesel;
    }
    std::cout << "\nPlease enter gender: ";
        std::cin >> gender;  

    if(str == "E" || str == "e") {
        std::cout << "\nPlease enter salary: ";
        std::cin >> salary;
        dbRef_.addPerson(std::make_shared<Employee>(name, surname, address, pesel, salary, gender));
        std::cout << "\nEmployee has been added to the database\n";
    }
    else {
        std::cout << "\nPlease enter index number: ";
        std::cin >> index;
        dbRef_.addPerson(std::make_shared<Student>(name, surname, address, index, pesel, gender));
        std::cout << "\nStudent has been added to the database\n";
    } 
}
//===============================================================================================================================================//
void Menu::generate_command() {
    Generator gn {};
    std::string str;
    size_t numberOfPersons = 0; // 
    std::cout << "If you want to generate random Employee press E else you will add student: ";
    std::getline (std::cin, str);
    if(str == "E" || str == "e") {
        std::cout << "\nPlease enter number of Employees to generate: ";
    }
    else {
        std::cout << "\nPlease enter number of Students to generate: ";    
    }
    std::cin >> numberOfPersons;
    for (int i = 0; i < numberOfPersons; i++) {
        if(str == "E" || str == "e") {
            dbRef_.addPerson(gn.generateEmployee());        
        }
        else {
            dbRef_.addPerson(gn.generateStudent());
        }
    }
}
//===============================================================================================================================================//
void Menu::modifySalary_command() {
    std::string pesel;
    size_t newSalary;
    std::cout << "\nPlease enter Employees PESEL number: ";
    std::cin >> pesel;
    std::cout << "\nPlease enter Employees new salary: ";
    std::cin >> newSalary;    
    dbRef_.modifySalary(pesel, newSalary);
}
//===============================================================================================================================================//
void Menu::printdb_command() {
    //printRuler();
    std::cout << std::setw((window_width - title.length()) / 2) << "" << title << "\n\n";
    std::cout << std::setw(name_field_width)    << std::left    << "Name"
              << std::setw(address_field_width) << std::left    << "Address"
              << std::setw(gender_field_width)  << std::left    << "Gender"
              << std::setw(index_field_width)   << std::left   << "Index"
              << std::setw(salary_field_width)   << std::left  << "Salary"
              << std::setw(pesel_field_width)   << std::right   << "Pesel"
              << std::setw(position_field_width) << std::right   << "Position"
              << '\n'; 
    std::cout << std::string(window_width, '-') << '\n';   

    for (auto personPtr : dbRef_.getFullList()) {
        std::cout   << std::setfill(' ') 
            << std::setw(name_field_width)     << std::left  << personPtr->getFullName()
            << std::setw(address_field_width)  << std::left  << personPtr->getAddress()
            << std::setw(gender_field_width)   << std::left  << personPtr->getGender()
            << std::setw(index_field_width)    << std::left << personPtr->getIndex() 
            << std::setw(salary_field_width)   << std::left  << personPtr->getSalary() 
            << std::setw(pesel_field_width)    << std::right << std::setfill('0') << personPtr->getPesel() << std::setfill(' ')
            << std::setw(position_field_width) << std::right << personPtr->getPosition()
            << std::endl;  

    }                             
    std::cout << std::string(window_width, '-') << '\n';
}
//===============================================================================================================================================//
void Menu::printStudent(Student& student) {

    std::cout << std::setw(name_field_width) << std::left << "Name"
              << std::setw(address_field_width) << std::left << "Address"
              << std::setw(gender_field_width) << std::left << "Gender"
              << std::setw(index_field_width) << std::right << "Index"
              << std::setw(pesel_field_width) << std::right << "Pesel"
              << '\n'; 
    std::cout << std::string(window_width, '-') << '\n';   


    std::cout << std::setw(name_field_width) << std::left << student.getFullName()
        << std::setw(address_field_width) << std::left << student.getAddress()
        << std::setw(gender_field_width) << std::left << student.getGender()
        << std::setw(index_field_width) << std::right << student.getIndex()
        << std::setw(pesel_field_width) << std::right << student.getPesel()
        << std::endl; 
                          
    std::cout << std::string(window_width, '-') << '\n';
}
//===============================================================================================================================================//
void Menu::search_command() {
    std::string str;
    std::cout << "Please enter person's PESEL number: ";
    std::cin >> str;
    std::stringstream ss (str);
    std::shared_ptr<Person> personFoundPtr;
    if(isNumber(str)) {
        std::string pesel;
        ss >> pesel;
        personFoundPtr = dbRef_.searchByPesel(pesel);    
    }
    personFoundPtr->print();
}
//===============================================================================================================================================//
void Menu::sort_command() {
    dbRef_.sortBySalary();
}
//===============================================================================================================================================//
void Menu::run() {
    while (!Exit_) {

        std::cout << '\n' << std::string(window_width, '-') << '\n';
        available_commands(); 
        std::cout << "Type command to execute: ";
        commandArgs_.clear();
        userCommand_.clear();
        while(userCommand_.size() == 0) {
            std::getline(std::cin, userCommand_);
        }
        std::cout << '\n';
        //std::cout << "You entered: " << userCommand_ << '\n';
        tokenize(' ');
        try
        {
            menuMapCommands_.at(commandArgs_[0])();
        }
        catch (...)
        {
            std::cout << "\nUnknown command!\n Type: help to check all available commands.\n";
        }
    }
}
//===============================================================================================================================================//
void Menu::tokenize(char delimeter) {
    std::string token {};
    std::istringstream tokenStream(userCommand_);
    while(getline(tokenStream, token, delimeter)) {
        commandArgs_.push_back(token);
    }
}
//===============================================================================================================================================//
bool Menu::isNumber(std::string str) {
    if(std::find_if_not(begin(str), end(str), isdigit) != end(str)) {
        return false;
    }
    else {
        return true;
    }
}
//===============================================================================================================================================//
void Menu::printRuler() {
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890\n\n";
}
