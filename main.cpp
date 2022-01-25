// university-db - Project for homework in CODERS SCHOOL (https:://coders,school)
/* 
Authors:
Main Code: Pawel Wiatr (https://github.com/pwiatr3/university-db2)

*/
#include "person.hpp"
#include "student.hpp"
#include "employee.hpp"
#include "menu.hpp"
#include "db.hpp"
#include "generator.hpp"

int main () {
    Db db {};
    Generator gn {};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> personDistrib(0, 2); // 0 - 
    std::shared_ptr<Person> personPtr;
    int personChoice = 0;

    // for(int i = 0; i < 10; i++) {
    
    //     personChoice = personDistrib(gen);
    //     if(personChoice) {
    //         personPtr = gn.generateEmployee();
    //     }
    //     else {
    //         personPtr = gn.generateStudent();
    //     }
    //     if(db.peselValidation(personPtr->getPesel()) == false) {
    //         std::cout << "Wrong PESEL: " << personPtr->getPesel() << '\n';
    //     }
    //     else {
    //         std::cout << "Valid PESEL: " << personPtr->getPesel() << '\n';
    //     }

    //     db.addPerson(personPtr);
    //     int j = 0;
    // }
 
    Menu menu {db};
    menu.run();
}