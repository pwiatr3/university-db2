#include "db.hpp"

void Db::addPerson(std::shared_ptr<Person> person_ptr) {
    db_.push_back(person_ptr);
}
void Db::printdb() {
    for (auto& person_ptr : db_) {
        person_ptr->print();
    }
}
std::shared_ptr<Person> Db::searchByPesel(std::string pesel) {
    for (auto& person : db_) {
        if(person->getPesel() == pesel) {
            return person;
        }        
    } 
    std::cout << "\nNo person with Pesel: " << pesel << '\n';

    // if no student was found return NullPerson object
    return std::make_shared<NullPerson>();
}

bool Db::peselValidation(std::string pesel) {
    std::array<size_t, 11> wagi {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    size_t suma = 0;

    for (int i = 0; i < pesel.size(); i++) {
        size_t peselDigit =  pesel[i] - 48; 
        suma += wagi[i] * peselDigit;
    }
    std::string sumaString = std::to_string(suma);
    if(sumaString.back() == '0') {
        return true;
    }
    return false; 
}
std::vector <std::shared_ptr<Person>> Db::getFullList() {
    return db_;
}
bool comparator(const std::shared_ptr<Person> lhs, const std::shared_ptr<Person> rhs) {
   return lhs->getSalary() < rhs->getSalary();
}

void Db::sortBySalary() {
    std::sort(begin(db_), end(db_), comparator);
}

void Db::modifySalary(std::string pesel, size_t newSalary) {
    std::shared_ptr<Person> personPtr = searchByPesel(pesel);
    personPtr->modifySalary(newSalary);
}
