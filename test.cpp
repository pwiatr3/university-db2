#include <catch2/catch_test_macros.hpp>
#include "db.hpp"
#include "employee.hpp"
#include "generator.hpp"

SCENARIO("Testing addPerson function in db") {

    GIVEN("Empty database db, pointer to Student and pointer to Employee") {
        Db db {};
        std::shared_ptr<Person> studentPtr = std::make_shared<Student>("Pawel", "Wiatr", "Namyslowska 8", 12345, "85052006075", "Male");
        std::shared_ptr<Person> employeePtr = std::make_shared<Employee>("Anna", "Aleksandrowska", "Dereniowa 6 Katowice", "77040612348", 100000, "Female");

        WHEN("addPerson(studentPtr) ") {
            db.addPerson(std::make_shared<Student>("Pawel", "Wiatr", "Namyslowska 8", 12345, "85052006075", "Male"));
            db.addPerson(std::make_shared<Employee>("Anna", "Aleksandrowska", "Dereniowa 6 Katowice", "77040612348", 100000, "Female"));
            
            THEN("First element in database is student, second is employee") {
                REQUIRE( db.getFullList().size() == 2);
                REQUIRE( *studentPtr == *db.getFullList().at(0));
                REQUIRE( *employeePtr == *db.getFullList().at(1));
            }
        }
    }
}

 SCENARIO("Testing sortBySalary() function in database") {

    GIVEN("Adding to an empty database 4 employees with Salaries: 3000, 4000, 1000, 2000") {
        Db db {};
        
        db.addPerson(std::make_shared<Employee>("", "", "", "00000000000", 3000, ""));
        db.addPerson(std::make_shared<Employee>("", "", "", "00000000000", 4000, ""));
        db.addPerson(std::make_shared<Employee>("", "", "", "00000000000", 1000, ""));
        db.addPerson(std::make_shared<Employee>("", "", "", "00000000000", 2000, ""));
                
        WHEN("sort by PESEL is called") {
            db.sortBySalary();
            THEN("First salary in sorted database is 1000") {
                REQUIRE(db.getFullList().at(0)->getSalary() == 1000);
            }
            THEN("Second salary in sorted database is 2000") {
                REQUIRE(db.getFullList().at(1)->getSalary() == 2000);
            }
            THEN("Third salary in sorted database is 3000") {
                REQUIRE(db.getFullList().at(2)->getSalary() == 3000);
            }
            THEN("Fourth salary in sorted database is 4000") {
                REQUIRE(db.getFullList().at(3)->getSalary() == 4000);
            }
                            
        }
    }   
}

SCENARIO("Testing generator object") {

    GIVEN("Generator object gen") {
        Db db {};
        Generator gen {};
        WHEN("gen.generateStudent() is called ") {
            std::shared_ptr<Student> studentPtr = gen.generateStudent();
            
            THEN("All student's fields are not empty, pesel number is valid") {
                REQUIRE(studentPtr->getName() !=  "");
                REQUIRE(studentPtr->getSurname() !=  "");
                REQUIRE(studentPtr->getAddress() !=  "");
                REQUIRE(studentPtr->getIndex() >= 0);
                REQUIRE(studentPtr->getIndex() <= maxIndex);
                REQUIRE(db.peselValidation(studentPtr->getPesel()) == true);
                REQUIRE(studentPtr->getGender() != "");
            }
        }        
    }
    GIVEN("Generator object gen") {
        Db db {};
        Generator gen {};
        WHEN("gen.generateEmployee() is called ") {
            std::shared_ptr<Employee> employeePtr = gen.generateEmployee();
            
            THEN("All employee fields are not empty, pesel number is valid") {
                REQUIRE(employeePtr->getName() !=  "");
                REQUIRE(employeePtr->getSurname() !=  "");
                REQUIRE(employeePtr->getAddress() !=  "");
                REQUIRE(db.peselValidation(employeePtr->getPesel()) == true);
                REQUIRE(employeePtr->getSalary() >= 0);
                REQUIRE(employeePtr->getSalary() <= maxSalary);
                REQUIRE(employeePtr->getGender() != "");
            }
        }        
    }
}

SCENARIO("Testing modifySalary(size_t pesel, size_t newSalary) function in db") {
    
    GIVEN("2 employees with salaries 200000, 10000 respectively and 1 student with salary 0 are added to empty db") {
        Db db {};
        db.addPerson(std::make_shared<Student>("Pawel", "Wiatr", "Namyslowska 8", 12345, "85052006075", "Male"));
        db.addPerson(std::make_shared<Employee>("Anna", "Aleksandrowska", "Dereniowa 6 Katowice", "77040612348", 200000, "Female"));
        db.addPerson(std::make_shared<Employee>("Stefan", "Żeromski", "Pejzażowa 8 Gdynia", "47070856498", 10000, "Male"));

        WHEN("sortBySalary() is called") {
            db.modifySalary("77040612348", 1000000);
            
            THEN("Person with PESEL 77040612348 salary is changed to 1000000") {
                REQUIRE(db.searchByPesel("77040612348")->getSalary() == 1000000);
            }
        }
    }
}

SCENARIO("Testing sortBySalary() function in db") {
    
    GIVEN("2 employees with salaries 200000, 10000 respectively and 1 student with salary 0 are added to empty db") {
        Db db {};
        db.addPerson(std::make_shared<Student>("Pawel", "Wiatr", "Namyslowska 8", 12345, "85052006075", "Male"));
        db.addPerson(std::make_shared<Employee>("Anna", "Aleksandrowska", "Dereniowa 6 Katowice", "77040612348", 200000, "Female"));
        db.addPerson(std::make_shared<Employee>("Stefan", "Żeromski", "Pejzażowa 8 Gdynia", "47070856498", 10000, "Male"));

        WHEN("sortBySalary() is called") {
            db.sortBySalary();
            
            THEN("First person is student with salary 0, then person with salary 10000 and last with person with 200000") {
                REQUIRE( db.getFullList().at(0)->getSalary() == 0);
                REQUIRE( db.getFullList().at(1)->getSalary() == 10000);
                REQUIRE( db.getFullList().at(2)->getSalary() == 200000);
            }
        }
    }
}
