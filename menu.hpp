#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <iomanip>
#include "student.hpp"
#include "db.hpp"

constexpr int window_width = 80;// display window width in characters
constexpr int name_field_width = 25;// name & surname field width in characters
constexpr int address_field_width = 25;// address field width in characters
constexpr int index_field_width = 5;// zip code field width in characters
constexpr int gender_field_width = 10;// sex field width in characters
constexpr int pesel_field_width = 15;// pesel number field width in characters
constexpr char file_to_load[] = "student_db.txt";
constexpr char file_to_save[] = "student_db_save.txt";


class Menu {
public:
    Menu(Db& dbRef);
    std::map<std::string, std::function<void()>> menuMapCommands_ {
            {"add", [this](){ add_command(); }},
            {"printdb", [this](){ printdb_command(); }},
            {"search", [this](){ search_command(); }},
            {"sort", [this](){ sort_command(); }},
            {"erase", [this](){ erase_command(); }},
            {"load", [this](){ load_command(); }},
            {"save", [this](){ save_command(); }},
            {"exit", [this](){ Exit_ = true; }},
        };

    // Functions to communicate with database
    void addStudent(Student student);
    void run();
    void tokenize(char delimeter);

    // Functions calling methods of a Db class
    void available_commands();
    void add_command();
    void printdb_command();
    void search_command();
    void sort_command();
    void erase_command();
    void load_command();
    void save_command();
    // Auxillary functions
    bool isNumber(std::string str);
    void printRuler();
    void printStudent(Student& student);

private:
    Db &dbRef_;
    std::string userCommand_;
    std::vector<std::string> commandArgs_;
    bool Exit_ {false};
    const std::string title {"Student's database"}; // database title 
};