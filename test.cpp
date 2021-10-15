// #include <catch2/catch_test_macros.hpp>
// #include "db.hpp"

// SCENARIO("Testing addStudent function in db") {

//     GIVEN("Empty database db and Student st1 = { Pawel, Wiatr, Namyslowska 8, 12345, 85052006075, Male }") {
//         Db db {};
//         Student st1 {"Pawel", "Wiatr", "Namyslowska 8", 12345, 85052006075, "Male"};
        
//         WHEN("addStudent(st1) is called") {
//             db.addStudent(st1);

//             THEN("First element in database is st1") {
//                 REQUIRE( db.getFullList().size() == 1);
//                 REQUIRE( st1 == db.getFullList().at(0));
//             }
//         }
//     }
    
// }

// SCENARIO("Testing readDbFromFile() function in database") {

//     GIVEN("Empty database db") {
//         Db db {};
//         Student first {"Adam", "Milczarek", "Prosta 1 Warszawa", 1234, 63042251892, "Male"};
//         Student middle {"Anna", "Aleksandrowska", "Dereniowa 6 Katowice", 5245, 77040612348, "Female"};
//         Student last {"Anna", "Maliszkiewicz", "Wrzeciono 9 Rybnik", 974, 84050293344, "Female"};
        
        
//         WHEN("readDbFromFile(student_db.txt) is called") {
//             db.readDbFromFile("student_db.txt");

//             THEN("Size of database is 10") {
                
//                 REQUIRE( db.getFullList().size() == 10);
//             }
//             THEN("First student in database is Adam Milczarek") {
//                 REQUIRE( first == db.getFullList().at(0));
//             }
//             THEN("Student in the middle of database is Anna Aleksandrowska") {
//                 REQUIRE( middle == db.getFullList().at(4));
//             }
//             THEN("Last student in the database is Anna Maliszkiewicz") {
//                 REQUIRE( last == db.getFullList().at(9));
//             }
//         }
//     }   
// }

// SCENARIO("Testing searchBySurname() function in database") {

//     GIVEN("Database loaded from file student_db.txt") {
//         Db db {};
//         db.readDbFromFile("student_db.txt");
//         Student st {"Anna", "Aleksandrowska", "Dereniowa 6 Katowice", 5245, 77040612348, "Female"};
                
//         WHEN("searchBySurname(Aleksandrowska) is called") {
//             Student st1 = db.searchBySurname("Aleksandrowska");

//             THEN("Student's surname, returned by the function is Aleksandrowska") {
//                 REQUIRE(  st1.getSurname() == "Aleksandrowska");
//             }
//         }
//         WHEN("searchBySurname(aleksandrowska) is called") {
//             Student st1 = db.searchBySurname("aleksandrowska");

//             THEN("Student's surname, returned by the function is Aleksandrowska") {
//                 REQUIRE(  st1.getSurname() == "Aleksandrowska");
//             }
//         }
//         WHEN("searchBySurname(Mickiewicz) is called") {
//             Student st1 = db.searchBySurname("Mickiewicz");

//             THEN("Function returns empty Student object with empty surname") {
//                 REQUIRE(  st1.getSurname() == "");
//             }
//         }
//     }   
// }

// SCENARIO("Testing searchByPesel() function in database") {

//     GIVEN("database loaded from file student_db.txt") {
//         Db db {};
//         db.readDbFromFile("student_db.txt");
                
//         WHEN("search for PESEL = 46010786794") {
//             Student st1 = db.searchByPesel(46010786794);

//             THEN("Student's PESEL, returned by the function is 46010786794") {
//                 REQUIRE(  st1.getPesel() == 46010786794);
//             }
//         }
//         WHEN("search for PESEL = 12341234123") {
//             Student st1 = db.searchByPesel(12341234123);

//             THEN("Student's PESEL, returned by the function is 0") {
//                 REQUIRE(st1.getPesel() == 0);
//             }
//         }
//     }   
// }

// SCENARIO("Testing sortByPesel() function in database") {

//     GIVEN("Adding to an empty database 3 student with PESEL numbers: 63042251892, 53050439434, 86072049352") {
//         Db db {};
//         Student st1 {"", "", "", 0, 63042251892, ""};
//         Student st2 {"", "", "", 0, 53050439434, ""};
//         Student st3 {"", "", "", 0, 86072049352, ""};

//         db.addStudent(st1);
//         db.addStudent(st2);
//         db.addStudent(st3);
                
//         WHEN("sort by PESEL is called") {
//             db.sortByPesel();
//             THEN("First PESEL in sorted database is 86072049352") {
//                 REQUIRE(db.getFullList().at(0).getPesel() == 86072049352);
//             }
//             THEN("Last PESEL in sorted database is 53050439434") {
//                 REQUIRE(db.getFullList().at(2).getPesel() == 53050439434);
//             }
                            
//         }
//     }   
// }

// SCENARIO("Testing sortBySurname() function in database") {

//     GIVEN("Adding to an empty database 3 student with surname: Zelent, Andrzejczak, Kozłowska") {
//         Db db {};
//         Student st1 {"", "Zelent", "", 0, 0, ""};
//         Student st2 {"", "Andrzejczak", "", 0, 0, ""};
//         Student st3 {"", "Kozłowska", "", 0, 0, ""};

//         db.addStudent(st1);
//         db.addStudent(st2);
//         db.addStudent(st3);
                
//         WHEN("sort by surname is called") {
//             db.sortBySurname();
//             THEN("First surname in sorted database is Andrzejczak") {
//                 REQUIRE(db.getFullList().at(0).getSurname() == "Andrzejczak");
//             }
//             THEN("Last surname in sorted database is Zelent") {
//                 REQUIRE(db.getFullList().at(2).getSurname() == "Zelent");
//             }
                            
//         }
//     }   
// }

// SCENARIO("Testing deleteRecord() function in database") {

//     GIVEN("Adding to an empty database 3 students") {
//         Db db {};
//         Student st1 {"Adam", "Milczarek", "Prosta 1 Warszawa", 1234, 63042251892, "Male"};
//         Student st2 {"Anna", "Aleksandrowska", "Dereniowa 6 Katowice", 5245, 77040612348, "Female"};
//         Student st3 {"Anna", "Maliszkiewicz", "Wrzeciono 9 Rybnik", 974, 84050293344, "Female"};

//         db.addStudent(st1);
//         db.addStudent(st2);
//         db.addStudent(st3);
                
//         WHEN("deleteRecord(5245) is called") {
//             db.deleteRecord(5245);
//             THEN("Size of databse is reduced to 2") {
//                 REQUIRE(db.getFullList().size() == 2);
//             }                           
//         }
//     }   
// }

// SCENARIO("Testing peselValidation() function") {
//     Db db {};
//         WHEN("when correct pesel 98010233714 is passed") {
//             THEN("peselValidation is true") {
//                 REQUIRE(db.peselValidation(98010233714) == true);
//             }                           
//         }
//         WHEN("when correct pesel 97062537166 is passed") {
//             THEN("peselValidation is true") {
//                 REQUIRE(db.peselValidation(97062537166) == true);
//             }                           
//         }
//         WHEN("when incorrect pesel 123 is passed") {
//             THEN("peselValidation is false") {
//                 REQUIRE(db.peselValidation(123) == false);
//             }                           
//         }
//         WHEN("when incorrect pesel 12121212121 is passed") {
//             THEN("peselValidation is false") {
//                 REQUIRE(db.peselValidation(12121212121) == false);
//             }                           
//         } 
// }

