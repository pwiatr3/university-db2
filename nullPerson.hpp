#include "person.hpp"

class NullPerson : public Person {
    public:
    //NullPerson();
    void print() override;
    size_t getSalary() const override;
    size_t getIndex() const override;
    void modifySalary(size_t newSalary) override;
};