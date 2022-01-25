#include "generator.hpp"


    std::vector<std::string> Generator::loadFiletoVector(std::string file) {
        std::string fileLine;
        std::vector<std::string> vec;
        std::fstream fileStream(file, fileStream.in);
        if(fileStream.is_open()) {
            while(!std::getline(fileStream, fileLine, '\n').eof() ) {
                vec.push_back(fileLine);
            }
            return vec;
        }
        std::cout << "Could not open file: " << file << '\n';
        return vec;
    }
    std::string Generator::generateName(std::string gender) {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<std::string> vecOfNames;    
        if(gender == "Male") {
            vecOfNames = loadFiletoVector(boyNamesFile);
        }
        if(gender == "Female") {
            vecOfNames = loadFiletoVector(girlNamesFile);
        }
        size_t numberOfNames = vecOfNames.size();
        if(numberOfNames != 0) {
            std::uniform_real_distribution<> genderDistrib(0, numberOfNames);
            size_t nameNumber = genderDistrib(gen);
            return vecOfNames[nameNumber];
        }
        return "";
    }
    std::string Generator::generateSurname() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<std::string> vecOfSurnames;    
        std::string gender = generateGender();
        vecOfSurnames = loadFiletoVector(surnamesFile);
        size_t numberOfSurnames = vecOfSurnames.size();
        if(numberOfSurnames != 0) {
            std::uniform_real_distribution<> genderDistrib(0, numberOfSurnames);
            size_t surnameNumber = genderDistrib(gen);
            return vecOfSurnames[surnameNumber];
        }
        return "";
    }
    std::string Generator::generateAddress() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<std::string> vecOfAddresses;    
        std::string gender = generateGender();
        vecOfAddresses = loadFiletoVector(addressesFile);
        size_t numberOfSurnames = vecOfAddresses.size();
        if(numberOfSurnames != 0) {
            std::uniform_real_distribution<> genderDistrib(0, numberOfSurnames);
            size_t addressNumber = genderDistrib(gen);
            return vecOfAddresses[addressNumber];
        }
        return "";
    }
    std::string Generator::generatePesel(std::string gender) {
        std::string pesel;
        std::ostringstream oss;
        
        // random 
        std::random_device rd;
        std::mt19937 gen(rd());

        // getting random year of birth
        std::uniform_real_distribution<> yearOfBirthDistrib(yearOfBirthMin, yearOfBirthMax);
        std::size_t yearOfBirth = yearOfBirthDistrib(gen);
        std::string twoLastDigitsOfYear = std::to_string(yearOfBirth).substr(2, 2);
        
        // getting random month of birth
        std::uniform_real_distribution<> monthOfBirthDistrib(1, 12);
        size_t monthOfBirth = monthOfBirthDistrib(gen);
        // coding month of birth with pesel style
        size_t peselStyleMonthOfBirth = monthOfBirth;
        if(yearOfBirth >= 2000) {
            peselStyleMonthOfBirth  += 20;
        }
        if(yearOfBirth >= 1800 && yearOfBirth < 1900) {
            peselStyleMonthOfBirth  += 80;    
        }   
        // setting leading zeros in month of birth     
        oss << std::setw(2) << std::setfill('0') << peselStyleMonthOfBirth;
        std::string monthOfBirthStr = oss.str();
        oss.str(""); // clearing oss string

        // getting random day of birth depending on the month of birth
        std::uniform_real_distribution<> dayOfBirthDistrib(1, monthDays[monthOfBirth]);
        size_t dayOfBirth = dayOfBirthDistrib(gen);  
        oss << std::setw(2) << std::setfill('0') << dayOfBirth;
        std::string dayOfBirthStr = oss.str();
        oss.str(""); // clearing oss string

        // getting random series number from 0..999
        std::uniform_real_distribution<> seriesNumberDistrib(0, 999);
        size_t seriesNumber = seriesNumberDistrib(gen);
        // setting leading zeros in series number     
        oss << std::setw(3) << std::setfill('0') << seriesNumber;
        std::string seriesNumberStr = oss.str();

        // getting random gender digit : 0, 2, 4, 6, 8 for male; 1, 3, 5, 7, 9 - for female
        std::uniform_real_distribution<> genderDigitDistrib(0, 4);
        size_t randomGenderDigit = genderDigitDistrib(gen);
        if(gender == "Female") {
            randomGenderDigit *= 2;
        }
        else {
            randomGenderDigit = 2 * randomGenderDigit + 1;
        }
        pesel = twoLastDigitsOfYear 
                    + monthOfBirthStr
                    + dayOfBirthStr
                    + seriesNumberStr
                    + std::to_string(randomGenderDigit);
        size_t controlDigit = calculateControlDigit(pesel);
        pesel.append(std::to_string(controlDigit));

        return pesel;
    }
    size_t Generator::calculateControlDigit(std::string number) {
        std::vector<int> wagi = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
        int suma = 0;

        for(int i = 0; i < number.size(); i++) {
            size_t peselDigit =  number[i] - 48; 
            suma += wagi[i] * peselDigit;
        }
        size_t M = suma % 10;
        if(M == 0) {
            return 0;
        }
        return 10 - M;
    }
    std::string Generator::generateGender() {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> genderDistrib(0, 2);
        size_t genderNumber = genderDistrib(gen);
        //std::cout << "genderNumber: " << genderNumber << " gender: " << genderArray[genderNumber] << " ";
        return genderArray[genderNumber];
    }
    size_t Generator::generateSalary() {        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> salaryDistrib(1, maxSalary);
        return salaryDistrib(gen);
    }
    size_t Generator::generateIndex() {        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> salaryDistrib(1, maxIndex);
        return salaryDistrib(gen);
    }
    std::shared_ptr<Student> Generator::generateStudent() {
        std::string gender = generateGender();
        std::string name = generateName(gender);
        std::string surname = generateSurname();
        std::string address = generateAddress();
        size_t index = generateIndex();       
        std::string pesel = generatePesel(gender);
        return std::make_shared<Student> (name, surname, address, index, pesel, gender);
    }
    std::shared_ptr<Employee> Generator::generateEmployee() {
        std::string gender = generateGender();
        std::string name = generateName(gender);
        std::string surname = generateSurname();
        std::string address = generateAddress();
        size_t salary = generateSalary();       
        std::string pesel = generatePesel(gender);
        return std::make_shared<Employee> (name, surname, address, pesel, salary, gender);
    }
