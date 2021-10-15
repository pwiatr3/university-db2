#include "db.hpp"

void Db::addStudent(Student student) {
    db_.push_back(student);
}
void Db::printdb() {
    for (auto& student : db_) {
        student.print();
    }
}
Student Db::searchBySurname(std::string surname) {
    // lambda to change all letters in string to lowercase
    auto changeToLower = [](std::string str) -> std::string { 
                                std::string lowerSurname {str}; 
                                std::for_each(begin(str), end(str), [](char & c){ c = std::tolower(c); });
                                return str;
                            };
                       
    for (auto& student : db_) {
        if(changeToLower(student.getSurname()) == changeToLower(surname)) {
            return student;
        }        
    } 
    std::cout << "No student with surname: " << surname << '\n';      
    Student empty;
    // if no student was found return empty Student object
    return empty;
}
Student Db::searchByPesel(size_t pesel) {
    for (auto& student : db_) {
        if(student.getPesel() == pesel) {
            return student;
        }        
    } 
    std::cout << "No student with Pesel: " << pesel << '\n';
    Student empty;
    // if no student was found return empty Student object
    return empty;
}
void Db::sortByPesel() {
    // // if database is empty, do nothing
    // if(db_.size() == 0) {
    //     return;
    // }
    std::sort(db_.begin(), db_.end(), [](Student a, Student b) {
        return a.getPesel() > b.getPesel();
    });
}
void Db::sortBySurname() {
    std::sort(db_.begin(), db_.end(), [](Student a, Student b) {
        return a.getSurname() < b.getSurname();
    });
}
void Db::deleteRecord(size_t index) {
    auto it = db_.begin();
    for (auto& student : db_) {
        if(student.getIndex() == index) {
            //remove(it, it);
            db_.erase(it);
            return;
        }
        it++;        
    } 
    std::cout << "No student with Index: " << index << '\n';
}
void Db::readDbFromFile(const std::string& filename) {
    std::ifstream dbFileStream;
    Student st {};

    size_t db_index;
    std::string name;
    std::string surname;
    std::string address;
    size_t index;
    std::string gender;
    size_t pesel;

    std::string line;
    
    dbFileStream.open(filename);
    // checking if file is open
    if(!dbFileStream) {
        std::cout << "Could not open:" << filename << '\n';
        return;
    }
    while (getline(dbFileStream, line))
    {   
        std::stringstream ss (line);
        std::vector <std::string>  vecOfData {};
        char tmp[100]; // temporary char array
        while (ss) {
            std::string substr;
            getline(ss, substr, ',');
            vecOfData.push_back(substr);
            //std::cout << substr << '\n';
        }
        sscanf(vecOfData[0].c_str(), "%lud", &db_index);
        sscanf(vecOfData[1].c_str(), "%s", tmp);
        name = tmp;
        sscanf(vecOfData[2].c_str(), "%s", tmp);
        surname = tmp;
        address = vecOfData[3];
        //removing leading space character
        address = address.substr(1, address.size());
        sscanf(vecOfData[4].c_str(), "%lud", &index);
        sscanf(vecOfData[5].c_str(), "%s", tmp);
        gender = tmp;
        sscanf(vecOfData[6].c_str(), "%lud", &pesel);

        st.setName(name);
        st.setSurname(surname);
        st.setAddress(address);
        st.setIndex(index);
        st.setGender(gender);
        st.setPesel(pesel);  
        db_.push_back(st);      
    }
}    
void Db::saveDbInFile(const std::string& filename) {
    std::ofstream dbFileStream;
    dbFileStream.open(filename);
    size_t db_index = 0;
    // checking if file is open
    if(!dbFileStream) {
        std::cout << "Could not open:" << filename << '\n';
        return;
    }
    for (const auto& item : db_) {
         dbFileStream << db_index << ", " << item.getName() << ", " << item.getSurname() << ", " << item.getAddress() 
            << ", " << item.getIndex() << ", " << item.getGender() << ", " << item.getPesel() << '\n';  
         db_index++;   
    }
}
bool Db::peselValidation(size_t pesel) {
    std::array<size_t, 11> wagi {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    size_t suma = 0;
    std::string peselString = std::to_string(pesel);

    for (int i = 0; i < peselString.size(); i++) {
        size_t peselDigit =  peselString[i] - 48; 
        suma += wagi[i] * peselDigit;
    }
    std::string sumaString = std::to_string(suma);
    if(sumaString.back() == '0') {
        return true;
    }
    return false; 
}
std::vector <Student>& Db::getFullList() {
    return db_;
}

