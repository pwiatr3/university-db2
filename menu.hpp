#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <iomanip>
#include "student.hpp"
#include "employee.hpp"
#include "db.hpp"

constexpr int name_field_width = 25;// name & surname field width in characters
constexpr int address_field_width = 25;// address field width in characters
constexpr int gender_field_width = 10;// sex field width in characters
constexpr int index_field_width = 10;// zip code field width in characters
constexpr int salary_field_width = 10;// salary field width in characters
constexpr int pesel_field_width = 11;// pesel number field width in characters
constexpr int position_field_width = 15;// pesel number field width in characters
// display window width in characters
constexpr int window_width = name_field_width + address_field_width +
                                gender_field_width + index_field_width +
                                salary_field_width + pesel_field_width +
                                position_field_width;

constexpr char file_to_load[] = "student_db.txt";
constexpr char file_to_save[] = "student_db_save.txt";


class Menu {
public:
    void run();
    Menu(Db& dbRef);
    
    private:
    std::map<std::string, std::function<void()>> menuMapCommands_ {
            {"add", [this](){ add_command(); }},
            {"generate", [this](){ generate_command(); }},
            {"printdb", [this](){ printdb_command(); }},
            {"modifySalary", [this](){ modifySalary_command(); }},
            {"search", [this](){ search_command(); }},
            {"sort", [this](){ sort_command(); }},
            {"exit", [this](){ Exit_ = true; }},
        };

    // Functions to communicate with database
    void addStudent(Student student);
    void tokenize(char delimeter);

    // Functions calling methods of a Db class
    void available_commands();
    void add_command();
    void generate_command();
    void modifySalary_command();
    void printdb_command();
    void search_command();
    void sort_command();

    // Auxillary functions
    bool isNumber(std::string str);
    void printRuler();
    void printStudent(Student& student);


    Db &dbRef_;
    std::string userCommand_;
    std::vector<std::string> commandArgs_;
    bool Exit_ {false};
    const std::string title {"University database"}; // database title 
};