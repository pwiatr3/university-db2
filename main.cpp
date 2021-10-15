// university-db - Project for homework in CODERS SCHOOL (https:://coders,school)
/* 
Authors:
Main Code: Pawel Wiatr (https://github.com/pwiatr3/university-db)

*/
#include "student.hpp"
#include "db.hpp"
#include "menu.hpp"

int main () {
    Db db1 {};
    Menu menu {db1};
    menu.run();
}