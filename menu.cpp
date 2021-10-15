// #include <sstream>
// #include "menu.hpp"

// //===============================================================================================================================================//
// Menu::Menu(Db& dbRef) : dbRef_{dbRef} {}
// //===============================================================================================================================================//
// void Menu::available_commands() {
//     std::cout << "Available commands to use in database:\n";
//     int i = 0;
//     for (auto &entry : menuMapCommands_)
//     {
//         std::cout << i <<". " << entry.first << "\n";
//         i++;
//     };
//     //std::cout << "\nType: [command] help to get help of specify command. Example: showdb help\n";
// }
// //===============================================================================================================================================//
// void Menu::add_command() {
//     std::string name {};
//     std::string surname {};
//     std::string address {};
//     size_t index = 0;
//     size_t pesel = 0;
//     std::string gender {};

//     std::cout << "Please enter student's name: ";
//     std::getline (std::cin, name);
//     std::cout << "\nPlease enter student's surname: ";
//     std::getline (std::cin, surname);
//     std::cout << "\nPlease enter student's address: ";
//     std::getline (std::cin, address);
//     std::cout << "\nPlease enter student's index number: ";
//     std::cin >> index;
//     std::cout << "\nPlease enter student's pesel number: ";
//     std::cin >> pesel;
//     while(dbRef_.peselValidation(pesel) == false) {
//         std::cout << "Invalid pesel number. Please enter corrent number\n";
//         std::cin >> pesel;
//     }
//     std::cout << "\nPlease enter student's gender: ";
//     std::cin >> gender;

//     Student newStudent (name, surname, address, index, pesel, gender);
//     dbRef_.addStudent(newStudent);
//     std::cout << "\nStudent has been added to the database\n";
// }
// //===============================================================================================================================================//
// void Menu::printdb_command() {
//     //printRuler();
//     std::cout << std::setw((window_width - title.length()) / 2) << "" << title << '\n';
//     std::cout << std::setw(name_field_width) << std::left << "Name"
//               << std::setw(address_field_width) << std::left << "Address"
//               << std::setw(gender_field_width) << std::left << "Gender"
//               << std::setw(index_field_width) << std::right << "Index"
//               << std::setw(pesel_field_width) << std::right << "Pesel"
//               << '\n'; 
//     std::cout << std::string(window_width, '-') << '\n';   

//     for (auto& student : dbRef_.getFullList()) {
//         std::cout << std::setw(name_field_width) << std::left << student.getFullName()
//             << std::setw(address_field_width) << std::left << student.getAddress()
//             << std::setw(gender_field_width) << std::left << student.getGender()
//             << std::setw(index_field_width) << std::right << student.getIndex()
//             << std::setw(pesel_field_width) << std::right << student.getPesel()
//             << std::endl; 
//     }                             
//     std::cout << std::string(window_width, '-') << '\n';
// }
// //===============================================================================================================================================//
// void Menu::printStudent(Student& student) {

//     std::cout << std::setw(name_field_width) << std::left << "Name"
//               << std::setw(address_field_width) << std::left << "Address"
//               << std::setw(gender_field_width) << std::left << "Gender"
//               << std::setw(index_field_width) << std::right << "Index"
//               << std::setw(pesel_field_width) << std::right << "Pesel"
//               << '\n'; 
//     std::cout << std::string(window_width, '-') << '\n';   


//     std::cout << std::setw(name_field_width) << std::left << student.getFullName()
//         << std::setw(address_field_width) << std::left << student.getAddress()
//         << std::setw(gender_field_width) << std::left << student.getGender()
//         << std::setw(index_field_width) << std::right << student.getIndex()
//         << std::setw(pesel_field_width) << std::right << student.getPesel()
//         << std::endl; 
                          
//     std::cout << std::string(window_width, '-') << '\n';
// }
// //===============================================================================================================================================//
// void Menu::search_command() {
//     std::string str;
//     std::cout << "Please enter student's surname or PESEL number: ";
//     std::cin >> str;
//     std::stringstream ss (str);
//     Student studentFound;
//     if(isNumber(str)) {
//         size_t pesel;
//         ss >> pesel;
//         studentFound = dbRef_.searchByPesel(pesel);    
//     }
//     else {
//         studentFound = dbRef_.searchBySurname(str);
//     }
//     // if studentFound is not empty, then print student
//     if(studentFound.getSurname() != "") {
//         printStudent(studentFound);
//     }
// }
// //===============================================================================================================================================//
// void Menu::sort_command() {
//     std::string str;
//     std::cout << "If you want to sort by PESEL press P else it will sort by surname ";
//     std::cin >> str;
   
//     if(str == "P" || str == "p") {
//         dbRef_.sortByPesel();    
//     }
//     else {
//         dbRef_.sortBySurname();
//     }    
// }
// //===============================================================================================================================================//
// void Menu::erase_command() {
//     size_t index;
//     std::cout << "Enter index number: ";
//     std::cin >> index;
//     dbRef_.deleteRecord(index);
// }
// //===============================================================================================================================================//
// void Menu::load_command() {
//     std::string file {file_to_load};
//     dbRef_.readDbFromFile(file);  
//     std::cout << "Database from file: " << file << " has been loaded\n";
// }
// //===============================================================================================================================================//
// void Menu::save_command() {
//     std::string file {file_to_save};
//     dbRef_.saveDbInFile(file);  
//     std::cout << "Database has been saved in a file: " << file << '\n';
// }
// //===============================================================================================================================================//
// void Menu::run() {
//     //clear_command();
//     while (!Exit_) {

//         std::cout << '\n' << std::string(window_width, '-') << '\n';
//         available_commands(); 
//         std::cout << "Type command to execute: ";
//         commandArgs_.clear();
//         userCommand_.clear();
//         while(userCommand_.size() == 0) {
//             std::getline(std::cin, userCommand_);
//         }
//         std::cout << '\n';
//         //std::cout << "You entered: " << userCommand_ << '\n';
//         tokenize(' ');
//         try
//         {
//             menuMapCommands_.at(commandArgs_[0])();
//         }
//         catch (...)
//         {
//             std::cout << "\nUnknown command!\n Type: help to check all available commands.\n";
//         }
//     }
// }
// //===============================================================================================================================================//
// void Menu::tokenize(char delimeter) {
//     std::string token {};
//     std::istringstream tokenStream(userCommand_);
//     while(getline(tokenStream, token, delimeter)) {
//         commandArgs_.push_back(token);
//     }
// }
// //===============================================================================================================================================//
// bool Menu::isNumber(std::string str) {
//     if(std::find_if_not(begin(str), end(str), isdigit) != end(str)) {
//         return false;
//     }
//     else {
//         return true;
//     }
// }
// //===============================================================================================================================================//
// void Menu::printRuler() {
//     std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890\n\n";
// }
